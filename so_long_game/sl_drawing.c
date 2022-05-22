/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_drawing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheidi <fheidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 14:59:11 by fheidi            #+#    #+#             */
/*   Updated: 2022/04/03 16:46:10 by fheidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	mlx_start(t_game *game)
{
	game->img_mlx = mlx_init();
	game->img_win = mlx_new_window(game->img_mlx, game->img_weight * game->x,
			game->img_heigth * game->y, "--== SO_LONG ==--");
	game->img_player = mlx_xpm_file_to_image(game->img_mlx, PLAYER,
			&game->img_weight, &game->img_heigth);
	game->img_exit = mlx_xpm_file_to_image(game->img_mlx, EXIT,
			&game->img_weight, &game->img_heigth);
	game->img_ground = mlx_xpm_file_to_image(game->img_mlx,
			GROUND, &game->img_weight, &game->img_heigth);
	game->img_item = mlx_xpm_file_to_image(game->img_mlx,
			ITEM, &game->img_weight, &game->img_heigth);
	game->img_wall = mlx_xpm_file_to_image(game->img_mlx,
			WALL, &game->img_weight, &game->img_heigth);
}

void	char_to_img(t_game *game, char object, int x, int y)
{	
	if (object == '0')
		put_ground(game, x, y);
	if (object == '1')
		put_wall(game, x, y);
	if (object == 'P')
		put_player(game, x, y);
	if (object == 'C')
		put_item(game, x, y);
	if (object == 'E')
		put_exit(game, x, y);
}

void	draw_map(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < game->y)
	{
		while (j < game->x)
		{
			char_to_img(game, game->map[i][j], j, i);
			j++;
		}
		j = 0;
		i++;
	}
	ft_putstr_fd("Steps: ", 1);
	ft_putnbr_fd(game->p_steps, 1);
	ft_putstr_fd("\n", 1);
}
