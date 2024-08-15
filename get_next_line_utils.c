/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:24:29 by ibenhoci          #+#    #+#             */
/*   Updated: 2023/04/24 11:34:16 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*x;
	int			i;
	int			j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	x = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (x == NULL)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		x[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
	{
		x[i] = s2[j];
		j++;
		i++;
	}
	x[i] = '\0';
	return (x);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((char)c == str[i])
			return ((char *)str + i);
		i++;
	}
	if ((char)c == str[i])
		return ((char *)str + i);
	return (NULL);
}

char	*ft_strdup(const char *str)
{
	int		i;
	char	*x;

	i = ft_strlen(str);
	x = (char *)malloc(i + 1);
	if (x == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		x[i] = str[i];
		i++;
	}
	x[i] = '\0';
	return (x);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*x;
	unsigned int	i;

	i = 0;
	if (ft_strlen(s) < start)
	{
		x = malloc(1);
		if (x == NULL)
			return (NULL);
		x[0] = '\0';
		return (x);
	}
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	x = malloc(len + 1);
	if (x == NULL)
		return (NULL);
	while (i < len)
	{
		x[i] = s[start + i];
		i++;
	}
	x[i] = '\0';
	return (x);
}
