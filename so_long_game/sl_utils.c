/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheidi <fheidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 13:05:54 by fheidi            #+#    #+#             */
/*   Updated: 2022/04/02 13:05:54 by fheidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	err_exit(char *str)
{
	write(1, str, ft_strlen(str));
	exit(1);
}

void	err_exit_clean(char *str, t_game *game)
{
	free_map(game);
	err_exit(str);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*z1;
	unsigned char	*z2;

	z1 = (unsigned char *)s1;
	z2 = (unsigned char *)s2;
	if (*z1 == '\0')
		return (-1);
	if (*z2 == '\0')
		return (-1);
	while (*z1 != '\0' || *z2 != '\0')
	{
		if (*z1 != *z2)
			return (*z1 - *z2);
		z1++;
		z2++;
	}
	return (0);
}
