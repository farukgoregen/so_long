/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omgorege <omgorege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 12:32:58 by omgorege          #+#    #+#             */
/*   Updated: 2025/01/20 12:37:29 by omgorege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen2(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin2(char *str, char *buffer)
{
	size_t	c;
	size_t	i;
	char	*res;

	if (!str)
	{
		str = malloc(1);
		str[0] = '\0';
	}
	c = 0;
	i = 0;
	res = malloc(ft_strlen2(str) + ft_strlen2(buffer) + 1);
	if (res == NULL)
		return (NULL);
	while (str[c])
	{
		res[c] = str[c];
		c++;
	}
	while (buffer[i])
		res[c++] = buffer[i++];
	res[ft_strlen2(str) + ft_strlen2(buffer)] = '\0';
	free(str);
	return (res);
}

char	*ft_strchr2(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

char	*line_str(char *str)
{
	size_t	i;
	char	*ptr;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	ptr = malloc(i + 2);
	if (!ptr)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		ptr[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_new(char *str)
{
	char	*res;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	res = malloc((ft_strlen2(str) - i) + 1);
	if (!res)
		return (NULL);
	i++;
	while (str[i])
		res[j++] = str[i++];
	res[j] = '\0';
	free(str);
	return (res);
}
