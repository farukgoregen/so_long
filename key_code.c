/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_code.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omgorege <omgorege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:23:24 by omgorege          #+#    #+#             */
/*   Updated: 2025/01/28 17:25:07 by omgorege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	key_w(t_maps *data)
{
	if (data->map[data->y - 1][data->x] != '1')
	{
		if (data->map[data->y - 1][data->x] == 'E' && data->coin != 0)
			return ;
		data->mov++;
		ft_printf("%d\n", data->mov);
		if (data->map[data->y - 1][data->x] == 'C')
			data->coin--;
		if (data->map[data->y - 1][data->x] == 'E' && data->coin == 0)
			mlxend_free(data);
		else
		{
			data->map[data->y][data->x] = '0';
			data->map[data->y - 1][data->x] = 'P';
			data->y--;
		}
	}
}

static void	key_s(t_maps *data)
{
	if (data->map[data->y + 1][data->x] != '1')
	{
		if (data->map[data->y + 1][data->x] == 'E' && data->coin != 0)
			return ;
		data->mov++;
		ft_printf("%d\n", data->mov);
		if (data->map[data->y + 1][data->x] == 'C')
			data->coin--;
		if (data->map[data->y + 1][data->x] == 'E' && data->coin == 0)
			mlxend_free(data);
		else
		{
			data->map[data->y][data->x] = '0';
			data->map[data->y + 1][data->x] = 'P';
			data->y++;
		}
	}
}

static void	key_d(t_maps *data)
{
	if (data->map[data->y][data->x + 1] != '1')
	{
		if (data->map[data->y][data->x + 1] == 'E' && data->coin != 0)
			return ;
		data->mov++;
		ft_printf("%d\n", data->mov);
		if (data->map[data->y][data->x + 1] == 'C')
			data->coin--;
		if (data->map[data->y][data->x + 1] == 'E' && data->coin == 0)
			mlxend_free(data);
		else
		{
			data->map[data->y][data->x] = '0';
			data->map[data->y][data->x + 1] = 'P';
			data->x++;
		}
	}
}

static void	key_a(t_maps *data)
{
	if (data->map[data->y][data->x - 1] != '1')
	{
		if (data->map[data->y][data->x - 1] == 'E' && data->coin != 0)
			return ;
		data->mov++;
		ft_printf("%d\n", data->mov);
		if (data->map[data->y][data->x - 1] == 'C')
			data->coin--;
		if (data->map[data->y][data->x - 1] == 'E' && data->coin == 0)
			mlxend_free(data);
		else
		{
			data->map[data->y][data->x] = '0';
			data->map[data->y][data->x - 1] = 'P';
			data->x--;
		}
	}
}

int	key_press(int key_code, t_maps *data)
{
	if (key_code == 65307)
		close_window(data);
	else if (key_code == 65362 || key_code == 119)
		key_w(data);
	else if (key_code == 65364 || key_code == 115)
		key_s(data);
	else if (key_code == 65363 || key_code == 100)
		key_d(data);
	else if (key_code == 65361 || key_code == 97)
		key_a(data);
	wall_backg_init(data);
	player_coin_exit_init(data);
	return (0);
}
