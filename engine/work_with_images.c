/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_images.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoge <gdoge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 21:26:15 by gdoge             #+#    #+#             */
/*   Updated: 2020/12/16 21:26:53 by gdoge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_image(t_all *all)
{
	all->image.snapshot = mlx_new_image(all->mlx, all->config.x_resolution,
													all->config.y_resolution);
	if (!(all->image.snapshot))
	{
		perror("Error\nProblem somewhere in mlx");
		exit(errno);
	}
	all->image.adress = mlx_get_data_addr(all->image.snapshot,
					&(all->image.bits_per_pixel), &(all->image.size_line), 
														&(all->image.endian));
	if (!(all->image.adress))
	{
		perror("Error\nProblem somewhere in mlx");
		exit(errno);
	}
}
