/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sporsche <sporsche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 13:25:02 by sporsche          #+#    #+#             */
/*   Updated: 2021/01/12 18:11:30 by sporsche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strdup_d(char const *s, char *s1);
char	*ft_strjoin(char *s1, char *s2, int var);
char	*ft_strcpy(char *dst, const char *src);
int		get_next_line(int fd, char **line);

#endif
