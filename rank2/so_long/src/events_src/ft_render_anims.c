/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_anims.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:55:54 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/02 14:55:54 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_render_player_anim(t_game *game)
{
	static int	turn;

	turn = 0;
	if (!turn)
	{
		ft_put_tile_to_buffer(game, "1b", game->player->y, game->player->x);
		turn++;
	}
	else if (turn == 1)
	{
		ft_put_tile_to_buffer(game, "2b", game->player->y, game->player->x);
		turn++;
	}
	else if (turn == 2)
	{
		ft_put_tile_to_buffer(game, "3b", game->player->y, game->player->x);
		turn++;
	}
	else if (turn == 3)
	{
		ft_put_tile_to_buffer(game, "4b", game->player->y, game->player->x);
		turn = 0;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->buffer->img_ptr, 0, 0);
}

void	ft_render_goblin_anim(t_game *game)
{
	static int	turn;

	turn = 0;
	if (!turn)
	{
		ft_put_tile_to_buffer(game, "1m", game->goblin->y, game->goblin->x);
		turn++;
	}
	else if (turn == 1)
	{
		ft_put_tile_to_buffer(game, "2m", game->goblin->y, game->goblin->x);
		turn++;
	}
	else if (turn == 2)
	{
		ft_put_tile_to_buffer(game, "3m", game->goblin->y, game->goblin->x);
		turn++;
	}
	else if (turn == 3)
	{
		ft_put_tile_to_buffer(game, "4m", game->goblin->y, game->goblin->x);
		turn = 0;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->buffer->img_ptr, 0, 0);
}
