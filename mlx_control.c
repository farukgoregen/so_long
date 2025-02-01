/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omgorege <omgorege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:01:25 by omgorege          #+#    #+#             */
/*   Updated: 2025/01/30 15:31:11 by omgorege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	mlxend_free(t_maps *data)
{
	mlx_destroy_image(data->mlx, data->playerml);
	mlx_destroy_image(data->mlx, data->coinml);
	mlx_destroy_image(data->mlx, data->exitml);
	mlx_destroy_image(data->mlx, data->wallml);
	mlx_destroy_window(data->mlx, data->mlxwin);
	mlx_destroy_image(data->mlx, data->back);
	ft_free(data->mapcpy);
	ft_free(data->map);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data);
	write(1, "You closed the game.\n", 21);
	exit(0);
}

void	mlxinit(t_maps *data)
{
	int	i;

	i = 64;
	data->mlx = mlx_init();
	data->mlxwin = mlx_new_window(data->mlx, data->colon * 64, data->rw * 64,
			"Minecraft");
	data->back = mlx_xpm_file_to_image(data->mlx, "textures/place.xpm", &i, &i);
	data->wallml = mlx_xpm_file_to_image(data->mlx, "textures/wall.xpm", &i,
			&i);
	data->playerml = mlx_xpm_file_to_image(data->mlx, "textures/player.xpm", &i,
			&i);
	data->exitml = mlx_xpm_file_to_image(data->mlx, "textures/exit.xpm", &i,
			&i);
	data->coinml = mlx_xpm_file_to_image(data->mlx, "textures/coin.xpm", &i,
			&i);
	wall_backg_init(data);
	player_coin_exit_init(data);
}

void	wall_backg_init(t_maps *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->rw)
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->mlxwin, data->wallml, j
					* 64, i * 64);
			else
				mlx_put_image_to_window(data->mlx, data->mlxwin, data->back, j
					* 64, i * 64);
			j++;
		}
		i++;
	}
}

void	player_coin_exit_init(t_maps *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->rw)
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx, data->mlxwin, data->exitml, j
					* 64, i * 64);
			else if (data->map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->mlxwin, data->coinml, j
					* 64, i * 64);
			else if (data->map[i][j] == 'P')
				mlx_put_image_to_window(data->mlx, data->mlxwin, data->playerml,
					j * 64, i * 64);
			j++;
		}
		i++;
	}
}

void	map_newline_error(t_maps *data)
{
	int		i;
	char	a;

	i = ft_strlen(data->str);
	if (data->str[i - 1] == '\n')
		ft_free2(data);
	a = data->str[0];
	i = 1;
	while (data->str[i])
	{
		if (a == '\n' && data->str[i] == '\n')
			ft_free2(data);
		a = data->str[i];
		i++;
	}
	data->map = ft_split(data->str, '\n');
	data->mapcpy = ft_split(data->str, '\n');
	free(data->str);
}
