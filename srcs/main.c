/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoge <gdoge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 11:52:13 by gdoge             #+#    #+#             */
/*   Updated: 2020/12/19 17:37:00 by gdoge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void 	sprite_rendering(t_all *all)
{

}

static void 	sprite_calculation(t_all *all)
{

}

void			sprite_calculations_and_rendering(t_all *all)
{
	sprite_calculation(all);
	sprite_rendering(all);
}

int		main(int argc, char **argv)
{
	t_all		all;

	init_some_stuff(&all);
	all = get_all_information_from_config(argv[1]);
	program_arguments_checking(argc, argv, &all);
	textures_capturing(&all);
	create_image(&all);
	ray_casting(&all);
	if (all.screenshot.flag)
		make_screenshot(&all);
	all.win = mlx_new_window(all.mlx, all.config.x_resolution,
						  all.config.y_resolution, "cub3D");
	if (!all.win)
	{
		perror("Error\nIT'S BAD ERROR, I REALLY HAVE NO IDEA, HOW TO FIX IT");
		exit(errno);
	}
	mlx_put_image_to_window(all.mlx, all.win, all.image.snapshot, 0, 0);
	combined_loop(&all);
	return (0);
}
