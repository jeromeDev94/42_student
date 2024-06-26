/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_failure.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:08:42 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/01 22:48:37 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_exit_failure(t_game *data, int errnum)
{
	const char	*error_messages[] = 
	{
		"Invalid character present in map.\n",
		"Multiple exits not allowed.\n",
		"Multiple starting positions not allowed.\n",
		"Map is not rectangular.\n",
		"Map is not fully enclosed by walls.\n",
		"Door need to have more floor space.\n",
		"No collectibles found in the map.\n",
		"No exit found in the map.\n",
		"No start position in the map.\n",
		"Usage : ./so_long <map_file.ber>\n",
		"Tileset list has an invalid format.\n",
		"Map has no possible path to exit.\n",
		"Failed to initialize mlx.\n",
		"Failed to find tile in tileset.\n",
		"Failed to create window.\n"
	};
	errno = errnum;
	if (errnum >= ENOCHAR && errnum <= ENOPATH)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd((char *)error_messages[errnum - 100], 2);
	}
	else if (errnum == ENOMEM || errnum == ENOENT)
		perror("Error");
	else if (errnum >= ENOINIT && errnum <= ENOWIN)
		perror((char *)error_messages[errnum - 100]);
	else
		ft_putstr_fd("Unknown error\n", 2);
	if (data->tiles)
	{
		gc_destroy_tiles(data);
		gc_destroy_tileset(data);
	}
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
		mlx_destroy_display(data->mlx_ptr);
	gc_cleanup();
	exit(EXIT_FAILURE);
}
