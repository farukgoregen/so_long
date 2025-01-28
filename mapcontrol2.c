/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcontrol2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omgorege <omgorege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:34:03 by omgorege          #+#    #+#             */
/*   Updated: 2025/01/25 16:23:39 by omgorege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_control4(t_maps *data)
{
	int	i;
	int	j;

	j = 0;
	while (j < data->rw)
	{
		i = 0;
		while (data->map[j][i])
		{
			if ((data->map[j][i] != '1') && (data->map[j][i] != '0')
				&& (data->map[j][i] != 'E') && (data->map[j][i] != 'C')
				&& (data->map[j][i] != 'P'))
				ft_error(data);
			i++;
		}
		j++;
	}
}

void	map_control5(t_maps *data)
{
	int	i;
	int	j;

	data->coin = 0;
	j = 0;
	while (j < data->rw)
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] == 'C')
				data->coin++;
			i++;
		}
		j++;
	}
	if (data->coin == 0)
		ft_error(data);
}

void	map_control6(t_maps *data)
{
	int	i;
	int	j;

	data->player = 0;
	j = 0;
	while (j < data->rw)
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] == 'P')
			{
				data->player++;
				data->x = i;
				data->y = j;
			}
			i++;
		}
		j++;
	}
	if ((data->player == 0) || (data->player > 1))
		ft_error(data);
}

void	map_control7(t_maps *data)
{
	int	i;
	int	j;

	data->ex = 0;
	j = 0;
	while (j < data->rw)
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] == 'E')
				data->ex++;
			i++;
		}
		j++;
	}
	if ((data->ex == 0) || (data->ex > 1))
		ft_error(data);
}
