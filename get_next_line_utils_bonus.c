/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 08:15:43 by tel-mouh          #+#    #+#             */
/*   Updated: 2021/12/26 13:31:28 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	size_t	lens;
	size_t	lenf;

	if (!s1 || !s2)
		return (NULL);
	lens = ft_strlen(s2);
	lenf = ft_strlen(s1);
	p = (char *)malloc(lenf + lens + 1);
	if (!p)
		return (NULL);
	ft_strlcpy(p, s1, lenf + 1);
	ft_strlcpy(p + lenf, s2, lenf + lens + 1);
	if (!*p)
		return (free(p), NULL);
	if (*s1)
		free(s1);
	return (p);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	t;

	t = 0;
	if (!dstsize)
		return (ft_strlen(src));
	while (src[t] && dstsize - 1)
	{
		dst[t] = src[t];
		t++;
		dstsize--;
	}
	return (dst[t] = 0, ft_strlen(src));
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*p;

	p = (char *)malloc(ft_strlen(s1)+1);
	if (p == NULL)
		return (NULL);
	return (ft_strlcpy(p, s1, ft_strlen(s1) + 1), p);
}

int	ft_strchr(const char *p, int c)
{
	int			i;

	i = 0;
	while (p[i] != (char )c && p[i])
		i++;
	if (!p[i])
		return (-1);
	return (i);
}
