/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omgorege <omgorege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:20:05 by omgorege          #+#    #+#             */
/*   Updated: 2025/01/30 14:28:37 by omgorege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1

# endif

int		ft_strlen2(char const *s);
char	*ft_strjoin2(char *s1, char *s2);
char	*get_next_line(int fd);
char	*ft_strchr2(char *s, int c);
char	*line_str(char *str);
char	*ft_new(char *str);

#endif