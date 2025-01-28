/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omgorege <omgorege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 10:46:13 by omgorege          #+#    #+#             */
/*   Updated: 2025/01/27 17:08:29 by omgorege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(t_maps *data)
{
	ft_free(data->mapcpy);
	ft_free(data->map);
	free(data);
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	null_error(t_maps *data, char *str)
{
	free(str);
	free(data);
	write(2, "Error\n", 6);
	exit(1);
}

int	close_window(t_maps *data)
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
	write(1, "You closed the game.", 20);
	exit(0);
}

int	main(int ac, char **av)
{
	t_maps	*data;

	if (ac < 2)
		return (1);
	data = malloc(sizeof(t_maps));
	data->mov = 0;
	ft_mapadd(av[1], data);
	map_colon(data);
	e_control(data);
	mapcpy_control(data);
	mlxinit(data);
	mlx_hook(data->mlxwin, 2, (1L << 0), key_press, data);
	mlx_hook(data->mlxwin, 17, 0L, close_window, data);
	mlx_loop(data->mlx);
}
