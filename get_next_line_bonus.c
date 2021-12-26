/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 08:13:37 by tel-mouh          #+#    #+#             */
/*   Updated: 2021/12/26 13:04:28 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*readbuf(int fd, char *str)
{
	char	buff[BUFFER_SIZE + 1];
	int		n;

	*buff = 0;
	n = 1;
	if (!str)
		str = "";
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
	char	*t;

	if (!*str)
		return (NULL);
	i = ft_strchr(*str, '\n');
	if (i == -1)
		return (NULL);
	if (!*(*str + i + 1))
		return (NULL);
	s = ft_strdup(*str + i + 1);
	t = *str;
	return (*str = malloc(i + 2), ft_strlcpy(*str, t, i + 2), free(t), s);
}

char	*get_next_line(int fd)
{
	static char	*str[10240];
	char		*r;

	if (fd < 0 || fd >= 10240)
		return (NULL);
	r = readbuf(fd, str[fd]);
	if (!r)
		return (NULL);
	return (str[fd] = get_line(&r), r);
}