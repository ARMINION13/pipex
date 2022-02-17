/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:24:58 by rgirondo          #+#    #+#             */
/*   Updated: 2021/09/20 21:12:37 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

char	*ft_path(char **envp)
{
	char	*str;
	int		i;

	i = 0;
	str = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 6))
			return (envp[i] + 5);
		i++;
	}
	return (0);
}

void	ft_childprocess(int *pip, char **argv, char **envp)
{
	int		fd_infile;
	char	**cmd1;
	char	**path;
	int		i;

	if (access(argv[1], R_OK) != 0)
		perror("No access to infile");
	i = 0;
	path = ft_split(ft_path(envp), ':');
	cmd1 = ft_split(argv[2], ' ');
	fd_infile = open(argv[1], O_RDONLY);
	dup2(fd_infile, STDIN_FILENO);
	close(fd_infile);
	dup2(pip[1], STDOUT_FILENO);
	close(pip[0]);
	close(pip[1]);
	while (path[i])
	{
		if (ft_strnstr(argv[2], "/", 2))
			execve(cmd1[0], cmd1, envp);
		execve(ft_strjoin(ft_strjoin(path[i], "/"), cmd1[0]), cmd1, envp);
		i++;
	}
	perror("Command not found");
	exit(EXIT_FAILURE);
}

void	ft_adultprocess(int *pip, char **argv, char **envp)
{
	int		fd_outfile;
	char	**cmd2;
	char	**path;
	int		i;

	if (access(argv[4], W_OK) != 0 && access(argv[4], F_OK) == 0)
		perror("No access to outfile");
	i = 0;
	path = ft_split(ft_path(envp), ':');
	cmd2 = ft_split(argv[3], ' ');
	fd_outfile = open(argv[4], O_RDWR | O_TRUNC | O_CREAT, 0666);
	dup2(fd_outfile, STDOUT_FILENO);
	close(fd_outfile);
	dup2(pip[0], STDIN_FILENO);
	close(pip[1]);
	close(pip[0]);
	while (path[i])
	{
		if (ft_strnstr(argv[3], "/", 2))
			execve(cmd2[0], cmd2, envp);
		execve(ft_strjoin(ft_strjoin(path[i], "/"), cmd2[0]), cmd2, envp);
		i++;
	}
	perror("Command not found");
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int		pip[2];

	pipe(pip);
	pid = fork();
	if (argc != 5)
	{		
		perror("Wrong amount of arguments");
		exit(EXIT_FAILURE);
	}
	if (pid == -1)
		perror("Fork error");
	if (pid == 0)
		ft_childprocess(pip, argv, envp);
	else
	{
		pid = fork();
		if (pid == -1)
			perror("Fork error");
		if (pid == 0)
			ft_adultprocess(pip, argv, envp);
		waitpid(-1, NULL, 0);
	}
	return (0);
}
