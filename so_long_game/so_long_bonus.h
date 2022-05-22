/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheidi <fheidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 13:06:06 by fheidi            #+#    #+#             */
/*   Updated: 2022/04/02 13:06:06 by fheidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./libft/libft.h"
# include "./minilibx/mlx.h"

# define W		13 
# define S		1
# define A		0
# define D 		2

# define ESC	53

# define UP		126
# define DOWN	125
# define LEFT	123
# define RIGHT	124

# define VALID_SYMBOLS "10PCEX\n"

# define PLAYER		"./textures/player.xpm"
# define GROUND 	"./textures/ground.xpm"
# define WALL		"./textures/wall.xpm"
# define EXIT		"./textures/exit.xpm"
# define ITEM		"./textures/item.xpm"
# define ENEMY		"./textures/enemy1.xpm"

# define HEIGHT 50
# define WEIGHT 50
# define SCORE_COLOR 0xF1E8E6

typedef struct s_int
{
	int	y;
	int	x;
	int	player;
	int	exit;
	int	enemy;
}	t_int;

typedef struct s_game
{
	char	**map;
	int		y;
	int		x;
	int		items;
	int		p_x;
	int		p_y;
	int		p_items;
	int		p_steps;
	void	*img_mlx;
	void	*img_win;
	void	*img_player;
	void	*img_ground;
	void	*img_wall;
	void	*img_exit;
	void	*img_item;
	void	*img_enemy;
	int		img_weight;
	int		img_heigth;
}	t_game;

// sl_utils.c

int		ft_strcmp(const char *s1, const char *s2);
void	err_exit(char *st);
void	err_exit_clean(char *str, t_game *game);

// map_parse.c

int		chek_ber_file(char *file);
int		map_get_size(char *file, t_game *game);
void	fill_map(char *file, t_game *game, int fl_size);

// map_check.c

int		map_chek_size(t_game *game);
int		map_chek_border(t_game *game);
int		map_chek_units(t_game *game);

// mem_free.c

void	free_map(t_game *game);
int		endgame(t_game *game);
void	finished(t_game *game);
void	game_over(t_game *game);

// sl_imaging.c

int		put_player(t_game *game, int x, int y);
int		put_wall(t_game *game, int x, int y);
int		put_ground(t_game *game, int x, int y);
int		put_item(t_game *game, int x, int y);
int		put_exit(t_game *game, int x, int y);

// sl_drawing.c

int		put_enemy(t_game *game, int x, int y);
void	mlx_start(t_game *game);
void	char_to_img(t_game *game, char object, int x, int y);
int		draw_map(t_game *game);

#endif