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

static void		error_management(void *checked)
{
	if (!checked)
	{
		write(2, "Error/n No one", 14);
		perror(" ever will see this message, but for error management...");
		exit(errno);
	}
}

int				main(int argc, char **argv)
{
	t_all		all;

	init_some_stuff(&all);
	all.mlx = mlx_init();
	error_management(all.mlx);
	get_all_information_from_config(argv[1], &all);
	all.win = mlx_new_window(all.mlx, all.config.x_resolution,
						all.config.y_resolution, "cub3D");
	error_management(all.win);
	program_arguments_checking(argc, argv, &all);
	textures_capturing(&all);
	create_image(&all);
	ray_casting(&all);
	if (all.screenshot.flag)
		make_screenshot(&all);
	mlx_put_image_to_window(all.mlx, all.win, all.image.snapshot, 0, 0);
	combined_loop(&all);
	return (0);
}
