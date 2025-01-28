/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omgorege <omgorege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 10:52:03 by omgorege          #+#    #+#             */
/*   Updated: 2025/01/27 17:08:16 by omgorege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct st_list
{
	char	**map;
	char	**mapcpy;
	int		rw;
	char	*str;
	int		colon;
	int		coin;
	int		ex;
	int		player;
	int		x;
	int		y;
	int		mov;
	void	*mlx;
	void	*playerml;
	void	*coinml;
	void	*exitml;
	void	*wallml;
	void	*mlxwin;
	void	*back;
}			t_maps;

void		ft_mapadd(char *av, t_maps *data);
void		map_colon(t_maps *data);
void		ft_error(t_maps *data);
void		map_control1(t_maps *data);
void		map_control2(t_maps *data);
void		map_control3(t_maps *data);
void		map_control4(t_maps *data);
void		map_control5(t_maps *data);
void		map_control6(t_maps *data);
void		map_control7(t_maps *data);
void		flood_fill(int x, int y, t_maps *data);
void		mapcpy_control(t_maps *data);
void		mlxinit(t_maps *data);
void		wall_backg_init(t_maps *data);
void		player_coin_exit_init(t_maps *data);
int			close_window(t_maps *data);
int			key_press(int key_code, t_maps *data);
void		ft_free(char **str);
void		null_error(t_maps *data, char *str);
int		mlxend_free(t_maps *data);
void	e_control(t_maps *data);
#endif