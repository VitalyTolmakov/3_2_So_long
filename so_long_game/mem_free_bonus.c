/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_free_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheidi <fheidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 13:06:01 by fheidi            #+#    #+#             */
/*   Updated: 2022/04/03 16:02:17 by fheidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long_bonus.h"

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->y)
	{
		free(game->map[i]);
		game->map[i] = NULL;
		i++;
	}
	free(game->map);
	game->map = NULL;
}

int	destroy_images(t_game *game)
{
	mlx_destroy_image(game->img_mlx, game->img_player);
	mlx_destroy_image(game->img_mlx, game->img_exit);
	mlx_destroy_image(game->img_mlx, game->img_ground);
	mlx_destroy_image(game->img_mlx, game->img_wall);
	mlx_destroy_image(game->img_mlx, game->img_item);
	mlx_destroy_image(game->img_mlx, game->img_enemy);
	return (0);
}

int	endgame(t_game *game)
{
	destroy_images(game);
	mlx_destroy_window(game->img_mlx, game->img_win);
	free_map(game);
	exit(0);
	return (0);
}

void	finished(t_game *game)
{
	mlx_clear_window(game->img_mlx, game->img_win);
	ft_putstr_fd("-= CONGRADULATIONS! You WIN! =-\n", 1);
	endgame(game);
}

void	game_over(t_game *game)
{
	mlx_clear_window(game->img_mlx, game->img_win);
	ft_putstr_fd("-= YOU LOSE! GAME OVER! =-\n", 1);
	endgame(game);
}
