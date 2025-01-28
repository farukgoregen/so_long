/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcontrol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omgorege <omgorege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:14:03 by omgorege          #+#    #+#             */
/*   Updated: 2025/01/27 15:56:18 by omgorege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_colon(t_maps *data)
{
	int	i;

	i = 0;
	while (data->map[0][i])
		i++;
	data->colon = i;
	map_control1(data);
}

void	map_control3(t_maps *data)
{
	int	i;
	int	j;

	i = data->colon;
	j = 1;
	while (j < data->rw - 1)
	{
		if (data->map[j][0] != '1')
			ft_error(data);
		if (data->map[j][i - 1] != '1')
			ft_error(data);
		j++;
	}
}

void	map_control2(t_maps *data)
{
	int	i;
	int	j;

	i = 0;
	j = data->rw;
	while (data->map[0][i])
	{
		if (data->map[0][i] != '1')
			ft_error(data);
		i++;
	}
	i = 0;
	while (data->map[j - 1][i])
	{
		if (data->map[j - 1][i] != '1')
			ft_error(data);
		i++;
	}
}

void	map_control1(t_maps *data)
{
	int	i;
	int	j;

	j = 1;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			i++;
		}
		if (data->colon != i)
			ft_error(data);
		j++;
	}
	if (j < 3)
		ft_error(data);
	map_control2(data);
	map_control3(data);
	map_control4(data);
	map_control5(data);
	map_control6(data);
	map_control7(data);
}

void	ft_mapadd(char *av, t_maps *data)
{
	int		fd;
	char	*str;
	char	*new_str;

	data->rw = 1;
	fd = open(av, O_RDWR);
	str = get_next_line(fd);
	if (str == NULL || str[0] == '\n')
		null_error(data, str);
	data->str = ft_strdup(str);
	free(str);
	str = get_next_line(fd);
	while (str != NULL)
	{
		new_str = ft_strjoin(data->str, str);
		free(data->str);
		data->str = new_str;
		free(str);
		str = get_next_line(fd);
		data->rw++;
	}
	free(str);
	data->map = ft_split(data->str, '\n');
	data->mapcpy = ft_split(data->str, '\n');
	free(data->str);
}
