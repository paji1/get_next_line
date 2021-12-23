/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 08:13:37 by tel-mouh          #+#    #+#             */
/*   Updated: 2021/12/23 06:17:22 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*readbuf(int fd, char *str)
{
	char	buff[BUFFER_SIZE + 1];
	int		n;

	*buff = 0;
	n = 1;
	if (!str)
		str = strdup("");
	while (ft_strchr(buff, '\n') == -1 && n)
	{
		n = read(fd, buff, BUFFER_SIZE);
		if (n == -1)
			return (NULL);
		buff[n] = 0;
		if (*buff)
			str = ft_strjoin(str, buff);
	}
	if (!*str)
		return (NULL);
	return (str);
}

char	*get_line(char **str)
{
	int		i;
	char	*s;

	if (!*str)
		return (NULL);
	i = ft_strchr(*str, '\n');
	if (i == -1)
		return (NULL);
	s = strdup(*str + i + 1);
	(*str)[i + 1] = 0;
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*r;

	r = NULL;
	r = readbuf(fd, str);
	if (!r)
		return (NULL);
	str = get_line(&r);
	return (r);
}
