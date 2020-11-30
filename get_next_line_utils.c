/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguado- <gaguado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 11:11:56 by gaguado-          #+#    #+#             */
/*   Updated: 2020/11/30 13:03:55 by gaguado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (*str != '\0')
	{
		str++;
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	int		i;
	int		length;

	i = 0;
	if (!s)
		return (0);
	if (!(ret = malloc(len + 1)))
		return (NULL);
	length = ft_strlen((char*)s);
	while (i < (int)len && start < (unsigned int)length)
	{
		ret[i] = s[start];
		i++;
		start++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		i;

	i = 0;
	if (s1)
	{
		if (!(ret = malloc(ft_strlen((char*)s1) + ft_strlen((char*)s2) + 1)))
			return (NULL);
		while (*s1 != '\0')
		{
			ret[i] = (char)*s1;
			i++;
			s1++;
		}
		while (*s2 != '\0')
		{
			ret[i] = (char)*s2;
			i++;
			s2++;
		}
		ret[i] = '\0';
	}
	else
		ret = ft_substr((char*)s2, 0, ft_strlen((char*)s2));
	return (ret);
}

char	*ft_strchr(const char *str, int c)
{
	char *s;

	if (!str)
		return (0);
	s = (char*)str;
	while (*s != (char)c)
	{
		if (*s == '\0')
			return (0);
		s++;
	}
	return (s);
}
