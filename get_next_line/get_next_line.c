/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omgorege <omgorege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:59:58 by omgorege          #+#    #+#             */
/*   Updated: 2025/01/20 12:36:47 by omgorege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_bufferstr(int fd, char *str)
{
	char	*buffer;
	int		i;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	i = 1;
	while (ft_strchr2(str, '\n') == 0 && i != 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			free(str);
			return (NULL);
		}
		buffer[i] = '\0';
		str = ft_strjoin2(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*ptr;

	if (fd < 0 && BUFFER_SIZE < 1)
		return (NULL);
	str = ft_bufferstr(fd, str);
	if (!str)
		return (NULL);
	ptr = line_str(str);
	str = ft_new(str);
	return (ptr);
}
