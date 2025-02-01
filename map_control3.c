/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omgorege <omgorege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:33:59 by omgorege          #+#    #+#             */
/*   Updated: 2025/01/30 18:11:24 by omgorege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(int x, int y, t_maps *data)
{
	char	c;

	c = data->mapcpy[x][y];
	if (c == '1')
		return ;
	data->mapcpy[x][y] = '1';
	if (c == 'E')
		return ;
	flood_fill(x + 1, y, data);
	flood_fill(x - 1, y, data);
	flood_fill(x, y + 1, data);
	flood_fill(x, y - 1, data);
}

void	mapcpy_control(t_maps *data)
{
	int	i;
	int	j;

	j = 0;
	while (data->mapcpy[j])
	{
		i = 0;
		while (data->mapcpy[j][i])
		{
			if (data->mapcpy[j][i] == 'C')
				ft_error(data, "Invalid map");
			if (data->mapcpy[j][i] == 'E')
				ft_error(data, "Invalid map");
			if (data->mapcpy[j][i] == 'P')
				ft_error(data, "Invalid map");
			i++;
		}
		j++;
	}
}
