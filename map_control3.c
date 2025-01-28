/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omgorege <omgorege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:33:59 by omgorege          #+#    #+#             */
/*   Updated: 2025/01/27 17:08:37 by omgorege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(int x, int y, t_maps *data)
{
	if (data->mapcpy[x][y] == '1')
		return ;
	data->mapcpy[x][y] = '1';
	flood_fill(x + 1, y, data);
	flood_fill(x - 1, y, data);
	flood_fill(x, y + 1, data);
	flood_fill(x, y - 1, data);
}

void	e_control(t_maps *data)
{
	int i;
	int j;

	j = 0;
	while (data->map[j])
	{
		i = 0;
		while(data->map[j][i])
		{
			if(data->map[j][i] == 'E')
			{
				if(data->map[j + 1][i] == '1' && data->map[j - 1][i] == '1')
				{
					if(data->map[j][i + 1] == '1' && data->map[j][i - 1] == '1')
						ft_error(data);
				}
				data->mapcpy[j][i] = '1';
			}
			i++;
		}
		j++;
	}
	flood_fill(data->y, data->x, data);
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
				ft_error(data);
			if (data->mapcpy[j][i] == 'E')
				ft_error(data);
			if (data->mapcpy[j][i] == 'P')
				ft_error(data);
			i++;
		}
		j++;
	}
}
