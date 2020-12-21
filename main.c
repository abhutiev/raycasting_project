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

#include "includes/cub3d.h"



void 		sprite_rendering(t_all *all)
{

}

void 	sprite_calculations_and_rendering(t_all *all)
{

}


int		main(int argc, char **argv)
{
	t_all		all;

	init_some_stuff(&all);
	program_arguments_checking(argc, argv);
	all = get_all_information_from_config(argv[1]);
	textures_capturing(&all);
	create_image(&all);
	ray_casting(&all);
	mlx_put_image_to_window(all.mlx, all.win, all.image.snapshot, 0, 0);
	combined_loop(&all);
	return (0);
}
