/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoge <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 06:24:36 by gdoge             #+#    #+#             */
/*   Updated: 2020/12/25 06:24:39 by gdoge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void			get_color_from_sprite(t_all *all,
									t_texture sprite, int x, int y)
{
	all->texture.color = *(uint32_t *)(sprite.address +
			((abs(x) + abs(y) * sprite.width) * (sprite.bits_per_pixel / 8)));
}

static void			put_sprite_to_image(t_all *all,
								int x, int y, unsigned int color)
{
	char	*dst;

	dst = all->image.image_adress + (y * all->image.size_line
									+ (x * all->image.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void				render_sprite(t_all *all)
{
	int	i;

	i = all->sprite.y_pix_1;
	while (i < all->sprite.y_pix_last)
	{
		all->sprite.shit = i * 256 -
				all->config.y_resolution * 128 + all->sprite.height * 128;
		all->sprite.loop_y = ((all->sprite.shit * all->textures.sprite.height)
				/ all->sprite.height) / 256;
		get_color_from_sprite(all, all->textures.sprite,
							all->sprite.loop_x, all->sprite.loop_y);
		if ((all->texture.color & 0x00FFFFFF) != 0)
		{
			put_sprite_to_image(all, all->sprite.current,
				i, all->texture.color);
		}
		i++;
	}
}
