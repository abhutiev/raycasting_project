/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoge <gdoge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 01:27:22 by gdoge             #+#    #+#             */
/*   Updated: 2020/12/07 01:41:49 by gdoge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_player	player_parsing(char **map, t_player player)
{
	int			i;
	int			j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if (map[i][j] == 'W' || map[i][j] == 'N' || map[i][j] == 'S'
			|| map[i][j] == 'E')
			{
				player.x_coord = j;
				player.y_coord = i;
				player.direction = map[i][j];
			}
	}
	if (player.direction == 'E')
		player.angle = 0;
	else if (player.direction == 'S')
		player.angle = M_PI_2;
	else if (player.direction == 'W')
		player.angle = M_PI;
	else if (player.direction == 'N')
		player.angle = 3 * M_PI_2;
	return (player);
}
