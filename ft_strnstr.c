/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:04:49 by rgirondo          #+#    #+#             */
/*   Updated: 2021/09/10 18:12:27 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./pipex.h"
#include <stdio.h>
#include <string.h>

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	unsigned int	a;
	unsigned int	b;

	if (!*to_find)
		return ((char *)str);
	a = 0;
	b = 0;
	while (str[a] != '\0' && (size_t)a < len)
	{
		if (str[a] == to_find[0])
		{
			b = 1;
			while (to_find[b] && str[a + b] == to_find[b] && (a + b) < len)
				b++;
			if (to_find[b] == '\0')
				return ((char *)&str[a]);
		}
		a++;
	}
	return (NULL);
}
