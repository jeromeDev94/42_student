/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_controls.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 23:44:18 by jeportie          #+#    #+#             */
/*   Updated: 2024/06/18 17:09:13 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"
#include <X11/keysym.h>
#include <X11/X.h>

int	ft_display_controls(int keysym, t_game *data)
{
	int new_x = data->map->player_x;
	int new_y = data->map->player_y;

	if (keysym == XK_w || keysym == XK_Up)
		new_y--;
	else if (keysym == XK_s || keysym == XK_Down)
		new_y++;
	else if (keysym == XK_a || keysym == XK_Left)
		new_x--;
	else if (keysym == XK_d || keysym == XK_Right)
		new_x++;
	if (data->map->map[new_y][new_x] != '1')
	{
		data->map->map[data->map->player_y][data->map->player_x] = '0';
		data->map->player_x = new_x;
		data->map->player_y = new_y;
		data->map->map[new_y][new_x] = 'P';
		ft_render_map(data);
	}

	if (keysym == XK_Escape)
	{
		gc_destroy_tiles(data);
		gc_destroy_tileset(data);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		gc_cleanup();
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	ft_close_window(t_game *data)
{
	gc_destroy_tiles(data);
	gc_destroy_tileset(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	gc_cleanup();
	exit(EXIT_SUCCESS);
	return (0);
}
