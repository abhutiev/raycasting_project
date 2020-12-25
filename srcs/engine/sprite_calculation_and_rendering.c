/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_calculation_and_rendering.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoge <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 05:55:44 by gdoge             #+#    #+#             */
/*   Updated: 2020/12/21 05:55:50 by gdoge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		sprite_distance_calculation_sorting(t_all *all)
{
	int	i;

	i = -1;
	while (++i < all->sprite.number)
		all->sprite.dist[i] = pow(all->player.y_coord - all->sprite.y[i],
		2.0) + pow((all->player.x_coord - all->sprite.x[i]), 2.0);
	i = -1;
	while (++i < all->sprite.number - 1)
		if (all->sprite.dist[i] < all->sprite.dist[i + 1])
		{
			all->sprite.tmp = all->sprite.dist[i];
			all->sprite.dist[i] = all->sprite.dist[i + 1];
			all->sprite.dist[i + 1] = all->sprite.tmp;
			all->sprite.tmp = all->sprite.x[i];
			all->sprite.x[i] = all->sprite.x[i + 1];
			all->sprite.x[i + 1] = all->sprite.tmp;
			all->sprite.tmp = all->sprite.y[i];
			all->sprite.y[i] = all->sprite.y[i + 1];
			all->sprite.y[i + 1] = all->sprite.tmp;
			i = -1;
		}
}

static void		calculate_sprite_parameters(t_all *all)
{
	all->sprite.x_cur = -all->player.x_coord + all->sprite.x[all->sprite.i];
	all->sprite.y_cur = -all->player.y_coord + all->sprite.y[all->sprite.i];
	all->sprite.determ = 1.0 / (all->ray.abscissa * all->ray.y_direction -
	all->ray.ordinate * all->ray.x_direction);
	all->sprite.x_transpon = all->sprite.determ * (all->player.y_direction *
	all->sprite.x_cur - all->player.x_direction * all->sprite.y_cur);
	all->sprite.y_transpon = all->sprite.determ * (all->ray.abscissa *
	all->sprite.y_cur - all->ray.ordinate * all->sprite.x_cur);
	all->sprite.plane = (int)((all->config.x_resolution / 2) *
	(1 + all->sprite.x_transpon / all->sprite.y_transpon));
	all->sprite.height = ABS((int)(all->config.y_resolution /
	all->sprite.y_transpon));
	all->sprite.width = ABS((int)(all->config.x_resolution /
	all->sprite.y_transpon));
}

static void		prepare_to_draw(t_all *all)
{
	all->sprite.x_pix_1 = -all->sprite.width / 2 + all->sprite.plane;
	all->sprite.x_pix_last = all->sprite.width / 2 + all->sprite.plane;
	if (all->sprite.x_pix_1 < 0)
		all->sprite.x_pix_1 = 0;
	if (all->sprite.x_pix_last > all->config.x_resolution)
		all->sprite.x_pix_last = all->config.x_resolution;
	all->sprite.y_pix_1 = (-all->sprite.height
			+ all->config.y_resolution) / 2;
	all->sprite.y_pix_last = (all->sprite.height
			+ all->config.y_resolution) / 2;
	if (all->sprite.y_pix_1 < 0)
	{
		all->sprite.y_pix_1 = 0;
		all->sprite.y_pix_last = all->config.y_resolution;
	}
}

static void		render_sprites(t_all *all)
{
	all->sprite.current = all->sprite.x_pix_1;
	while (all->sprite.current < all->sprite.x_pix_last)
	{
		all->sprite.loop_x = (int)(256 * (all->sprite.current -
		(all->sprite.plane - all->sprite.width / 2))
			* all->textures.sprite.width / all->sprite.width) / 256;
		if (all->sprite.y_transpon > 0 && all->sprite.current >= 0
			&& all->sprite.current < all->config.x_resolution
			&& all->sprite.y_transpon <
				all->sprite.ray[all->sprite.current])
		{
			render_sprite(all);
		}
		all->sprite.current++;
	}
}

void			sprite_calculations_and_rendering(t_all *all)
{
	sprite_distance_calculation_sorting(all);
	all->sprite.i = 0;
	while (all->sprite.i < all->sprite.number)
	{
		calculate_sprite_parameters(all);
		prepare_to_draw(all);
		render_sprites(all);
		all->sprite.i++;
	}
}
