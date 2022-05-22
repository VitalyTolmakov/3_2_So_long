/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheidi <fheidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 13:05:57 by fheidi            #+#    #+#             */
/*   Updated: 2022/04/02 13:05:57 by fheidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long_bonus.h"

int	map_chek_size(t_game *game)
{
	int	i;

	i = 0;
	if (game->y < 3 || game->x < 3)
		return (-1);
	while (i < game->y)
		if (game->x != (int)ft_strlen(game->map[i++]))
			return (-1);
	return (0);
}

int	map_chek_border(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->x)
	{
		if (game->map[0][i] != '1' || game->map[game->y - 1][i] != '1')
			return (-1);
		i++;
	}
	i = 1;
	while (i < (game->y - 1))
		if (game->map[i][0] != '1' || game->map[i++][game->x - 1] != '1')
			return (-1);
	return (0);
}

void	map_chek_units_init(t_int *h)
{
	h->y = 0;
	h->x = 0;
	h->player = 0;
	h->exit = 0;
	h->enemy = 0;
}

void	set_player_position(t_game *game, int x, int y)
{
	game->p_x = x;
	game->p_y = y;
}

int	map_chek_units(t_game *game)
{
	t_int	h;

	map_chek_units_init(&h);
	while (h.y < game->y)
	{
		while (h.x < game->x)
		{
			if (game->map[h.y][h.x] == 'C')
				game->items++;
			if (game->map[h.y][h.x] == 'P')
			{
				h.player++;
				set_player_position(game, h.x, h.y);
			}
			if (game->map[h.y][h.x] == 'X')
				h.enemy++;
			if (game->map[h.y][h.x++] == 'E')
				h.exit++;
		}
		h.x = 0;
		h.y++;
	}
	if (game->items < 1 || h.player != 1 || h.exit < 1 || h.enemy < 1)
		return (-1);
	return (0);
}
