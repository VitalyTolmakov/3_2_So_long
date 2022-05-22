/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheidi <fheidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 13:06:03 by fheidi            #+#    #+#             */
/*   Updated: 2022/04/02 13:06:03 by fheidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long_bonus.h"

void	move(t_game *game, int next_x, int next_y)
{
	int	x;
	int	y;

	x = game->p_x;
	y = game->p_y;
	if (game->map[next_y][next_x] != '1')
	{
		if (game->map[next_y][next_x] == 'E' && game->p_items == game->items)
			finished(game);
		if (game->map[next_y][next_x] == 'X')
			game_over(game);
		else if (game->map[next_y][next_x] != 'E')
		{
			if (game->map[next_y][next_x] == 'C')
				game->p_items++;
			game->map[y][x] = '0';
			game->map[next_y][next_x] = 'P';
			game->p_x = next_x;
			game->p_y = next_y;
			game->p_steps++;
			draw_map(game);
		}
	}
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == ESC)
		endgame(game);
	if (keycode == W || keycode == UP)
		move(game, game->p_x, game->p_y - 1);
	if (keycode == S || keycode == DOWN)
		move(game, game->p_x, game->p_y + 1);
	if (keycode == A || keycode == LEFT)
		move(game, game->p_x - 1, game->p_y);
	if (keycode == D || keycode == RIGHT)
		move(game, game->p_x + 1, game->p_y);
	return (0);
}

void	init_game(t_game *game)
{
	game->items = 0;
	game->p_items = 0;
	game->p_steps = 0;
	game->img_weight = WEIGHT;
	game->img_heigth = HEIGHT;
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		cnt_lns;

	if (argc != 2)
		err_exit("ERROR, Invalid parameters!\n");
	init_game(&game);
	if (chek_ber_file(argv[1]) == -1)
		err_exit("ERROR, Wrong filename!\n");
	cnt_lns = map_get_size(argv[1], &game);
	fill_map(argv[1], &game, cnt_lns);
	if (map_chek_size(&game) != 0)
		err_exit_clean("Error! Invalid map size\n", &game);
	if (map_chek_border(&game) != 0)
		err_exit_clean("Error! Invalid map border\n", &game);
	if (map_chek_units(&game) != 0)
		err_exit_clean("Error! Invalid map units\n", &game);
	mlx_start(&game);
	draw_map(&game);
	mlx_key_hook(game.img_win, key_hook, &game);
	mlx_hook(game.img_win, 17, 0, endgame, &game);
	mlx_loop(game.img_mlx);
	return (0);
}
