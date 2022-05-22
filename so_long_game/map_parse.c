/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheidi <fheidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 19:05:58 by fheidi            #+#    #+#             */
/*   Updated: 2022/04/02 19:05:58 by fheidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	chek_ber_file(char *file)
{
	if (!ft_strcmp(file + ft_strlen(file) - 4, ".ber"))
		return (0);
	return (-1);
}

int	map_get_size(char *file, t_game *game)
{
	char	read_sym;
	int		cnt_lines;
	int		eof;
	int		fd;
	int		file_size;

	cnt_lines = 1;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		err_exit("ERROR, Invalid file descriptor!\n");
	eof = 1;
	file_size = 0;
	while (eof > 0)
	{
		eof = read(fd, &read_sym, 1);
		if (!ft_strchr(VALID_SYMBOLS, read_sym))
			err_exit("ERROR, Symbol(s) on map is invalid!\n");
		if (read_sym == '\n')
			cnt_lines++;
		file_size++;
	}
	close(fd);
	game->y = cnt_lines;
	return (file_size);
}

void	fill_map(char *file, t_game *game, int fl_size)
{
	int		fd;
	char	*map_line;

	fd = open(file, O_RDONLY);
	map_line = malloc(sizeof(char) * (fl_size + 1));
	if (NULL == map_line)
		err_exit("ERROR, Memory not allocated!\n");
	read(fd, map_line, fl_size + 1);
	game->map = ft_split(map_line, '\n');
	game->x = ft_strlen(game->map[0]);
	free(map_line);
	close(fd);
}
