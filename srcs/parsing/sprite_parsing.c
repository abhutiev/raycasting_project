/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoge <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 01:04:25 by gdoge             #+#    #+#             */
/*   Updated: 2020/12/23 01:04:28 by gdoge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	sprite_counting(t_all *all)
{
	int			i;
	int			j;

	all->sprite.number = 0;
	i = -1;
	while (all->map.map[++i])
	{
		j = -1;
		while (all->map.map[i][++j])
		{
			if (all->map.map[i][j] == '2')
				all->sprite.number++;
		}
	}
	all->sprite.x = (double *)malloc(sizeof(double) * (all->sprite.number + 1));
	all->sprite.y = (double *)malloc(sizeof(double) * (all->sprite.number + 1));
	all->sprite.dist = (double *)malloc(8 * all->sprite.number + 1);
	all->sprite.ray = (double *)malloc(8 * all->config.x_resolution);
	if (!(all->sprite.x) || !(all->sprite.y))
	{
		write(2, "Error/n No one", 14);
		perror(" ever will see this message, but for error management...");
		exit(errno);
	}
}

void		sprite_parsing(t_all *all)
{
	int			i;
	int			j;
	size_t		sprite_counter;

	sprite_counting(all);
	sprite_counter = 0;
	all->sprite.x[all->sprite.number] = 0;
	all->sprite.y[all->sprite.number] = 0;
	i = -1;
	while (all->map.map[++i])
	{
		j = -1;
		while (all->map.map[i][++j])
		{
			if (all->map.map[i][j] == '2')
			{
				all->sprite.x[sprite_counter] = j + 0.5;
				all->sprite.y[sprite_counter] = i + 0.5;
				sprite_counter++;
			}
		}
	}
}
