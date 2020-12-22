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
	all->sprite.x_coord = (int *)malloc(sizeof(int) * (all->sprite.number + 1));
	all->sprite.y_coord = (int *)malloc(sizeof(int) * (all->sprite.number + 1));
	if (!(all->sprite.x_coord) || !(all->sprite.y_coord))
	{
		perror("Error/n No one ever will see this message, but for error management...");
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
	all->sprite.x_coord[all->sprite.number] = 0;
	all->sprite.y_coord[all->sprite.number] = 0;
	i = -1;
	while (all->map.map[++i])
	{
		j = -1;
		while (all->map.map[i][++j])
		{
			if (all->map.map[i][j] == '2')
			{
				all->sprite.x_coord[sprite_counter] = i;
				all->sprite.y_coord[sprite_counter] = j;
				sprite_counter++;
			}
		}
	}
}
