/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoge <gdoge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 01:27:22 by gdoge             #+#    #+#             */
/*   Updated: 2020/12/19 17:40:58 by gdoge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	north_direction_player(t_all *all)
{
	all->ray.abscissa = tan(M_PI * (VIEW_ANGLE / 360.0));
	all->ray.ordinate = 0;
	all->player.y_direction = -1;
	all->player.x_direction = 0;
}

static void	south_direction_player(t_all *all)
{
	all->ray.abscissa = -tan(M_PI * (VIEW_ANGLE / 360.0));
	all->ray.ordinate = 0;
	all->player.y_direction = 1;
	all->player.x_direction = 0;
}

static void	west_direction_player(t_all *all)
{
	all->ray.abscissa = 0;
	all->ray.ordinate = -tan(M_PI * (VIEW_ANGLE / 360.0));
	all->player.y_direction = 0;
	all->player.x_direction = -1;
}

static void	east_direction_player(t_all *all)
{
	all->ray.abscissa = 0;
	all->ray.ordinate = tan(M_PI * (VIEW_ANGLE / 360.0));
	all->player.y_direction = 0;
	all->player.x_direction = 1;
}

void		player_parsing(char **map, t_all *all)
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
				all->player.x_coord = j + 0.01;
				all->player.y_coord = i + 0.01;
				all->player.direction = map[i][j];
			}
	}
	if (all->player.direction == 'N')
		north_direction_player(all);
	else if (all->player.direction == 'S')
		south_direction_player(all);
	else if (all->player.direction == 'W')
		west_direction_player(all);
	else if (all->player.direction == 'E')
		east_direction_player(all);
}
