/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sporsche <sporsche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 13:26:09 by sporsche          #+#    #+#             */
/*   Updated: 2021/01/12 18:19:11 by sporsche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	n;
	char	*str;

	i = 0;
	n = ft_strlen((char *)s);
	str = (char *)s;
	if (c == '\0')
		return (&str[i]);
	while (i <= n)
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	return (0);
}

char	*ft_strdup_d(char const *s, char *s1)
{
	size_t	i;
	char	*str;

	i = ft_strlen(s);
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	while (*s != '\0')
	{
		*str = *s;
		s++;
		str++;
	}
	*str = '\0';
	str = str - i;
	if (s1 != NULL)
		free(s1);
	return (str);
}

char	*ft_strdup(char const *s)
{
	size_t	i;
	char	*str;

	i = ft_strlen(s);
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	while (*s != '\0')
	{
		*str = *s;
		s++;
		str++;
	}
	*str = '\0';
	str = str - i;
	return (str);
}

char	*ft_strjoin(char *s1, char *s2, int var)
{
	char	*str;
	size_t	len;
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		if (!(str = (char *)malloc((len + 1) * sizeof(char))))
			return (0);
		while (s1[n] != '\0')
			str[i++] = s1[n++];
		n = 0;
		while (s2[n] != '\0')
			str[i++] = s2[n++];
		str[i] = '\0';
		if (var == 1)
			free(s1);
		return (str);
	}
	return (0);
}
