/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_imaging.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheidi <fheidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 13:56:41 by fheidi            #+#    #+#             */
/*   Updated: 2022/04/02 14:32:07 by fheidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	put_player(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->img_mlx, game->img_win,
		game->img_ground, (x * game->img_weight),
		(y * game->img_heigth));
	mlx_put_image_to_window(game->img_mlx, game->img_win,
		game->img_player, (x * game->img_weight),
		(y * game->img_heigth));
	return (0);
}

int	put_wall(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->img_mlx, game->img_win,
		game->img_wall, (x * game->img_weight),
		(y * game->img_heigth));
	return (0);
}

int	put_ground(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->img_mlx, game->img_win,
		game->img_ground, (x * game->img_weight),
		(y * game->img_heigth));
	return (0);
}

int	put_item(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->img_mlx, game->img_win,
		game->img_ground, (x * game->img_weight),
		(y * game->img_heigth));
	mlx_put_image_to_window(game->img_mlx, game->img_win,
		game->img_item, (x * game->img_weight),
		(y * game->img_heigth));
	return (0);
}

int	put_exit(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->img_mlx, game->img_win,
		game->img_exit, (x * game->img_weight),
		(y * game->img_heigth));
	return (0);
}
