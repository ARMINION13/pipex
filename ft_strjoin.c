/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 20:07:45 by rgirondo          #+#    #+#             */
/*   Updated: 2021/09/10 18:07:07 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"
#include <stdio.h>
#include <stdlib.h>

static char	*string(char const *src, char const *src2, char *str)
{
	int	i;
	int	d;

	i = 0;
	d = 0;
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	while (src2[d])
	{
		str[i + d] = src2[d];
		d++;
	}
	str[i + d] = src2[d];
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		d;

	i = 0;
	d = 0;
	if (!s1 || !s2)
		return (NULL);
	while (s1[i])
		i++;
	while (s2[d])
		d++;
	str = malloc(i + d + 1);
	if (!(str))
		return (NULL);
	string(s1, s2, str);
	return (str);
}
