/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sporsche <sporsche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:27:00 by sporsche          #+#    #+#             */
/*   Updated: 2021/01/12 18:10:51 by sporsche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	check_rem(char **rem, char ***line, char **p_n)
{
	char	*tmp;

	if ((*p_n = ft_strchr(*rem, '\n')))
	{
		**p_n = '\0';
		tmp = **line;
		**line = ft_strjoin(**line, *rem, 0);
		free(tmp);
		tmp = *rem;
		*rem = ft_strdup(++(*p_n));
		free(tmp);
	}
	else
	{
		tmp = **line;
		**line = ft_strjoin(**line, *rem, 0);
		free(tmp);
		tmp = *rem;
		*rem = NULL;
		free(tmp);
	}
}

int		get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	int			b_w_r;
	char		*p_n;
	static char	*rem;

	b_w_r = 0;
	p_n = NULL;
	if (!line || fd < 0 || BUFFER_SIZE < 1 || !(*line = ft_strdup("\0"))
	|| (b_w_r = read(fd, buf, 0)) == -1)
		return (-1);
	*line[0] = 0;
	if (rem)
		check_rem(&rem, &line, &p_n);
	while (!p_n && (b_w_r = read(fd, buf, BUFFER_SIZE)))
	{
		buf[b_w_r] = '\0';
		if ((p_n = ft_strchr(buf, '\n')))
		{
			*p_n = '\0';
			rem = ft_strdup_d(++p_n, rem);
		}
		*line = ft_strjoin(*line, buf, 1);
	}
	return ((p_n) ? 1 : 0);
}
