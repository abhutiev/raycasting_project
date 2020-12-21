/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoge <gdoge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 06:51:45 by gdoge             #+#    #+#             */
/*   Updated: 2020/12/19 17:33:31 by gdoge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		player_movement_forward_backward(t_all *all)
{
	if (all->key.forward)
	{
		if (all->map.map[(int)(all->player.y_coord)][(int)
		(all->player.x_coord + all->player.x_direction * MOVE_CHECK)] != '1')
			all->player.x_coord += all->player.x_direction * MOVE_SPEED;
		if (all->map.map[(int)(all->player.y_coord + all->player.y_direction
		* MOVE_CHECK)][(int)(all->player.x_coord)] != '1')
			all->player.y_coord += all->player.y_direction * MOVE_SPEED;
	}
	if (all->key.backward)
	{
		if (all->map.map[(int)(all->player.y_coord)][(int)
		(all->player.x_coord - all->player.x_direction * MOVE_CHECK)] != '1')
			all->player.x_coord -= all->player.x_direction * MOVE_SPEED;
		if (all->map.map[(int)(all->player.y_coord - all->player.y_direction
		* MOVE_CHECK)][(int)(all->player.x_coord)] != '1')
			all->player.y_coord -= all->player.y_direction * MOVE_SPEED;
	}
}

static void		player_movement_left_right(t_all *all)
{
	if (all->key.right)
	{
		if (all->map.map[(int)(all->player.y_coord)][(int)
		(all->player.x_coord + all->ray.abscissa * MOVE_CHECK)] != '1')
			all->player.x_coord += all->ray.abscissa * MOVE_SPEED;
		if (all->map.map[(int)(all->player.y_coord + all->ray.ordinate
		* MOVE_CHECK)][(int)(all->player.x_coord)] != '1')
			all->player.y_coord += all->ray.ordinate * MOVE_SPEED;
	}
	if (all->key.left)
	{
		if (all->map.map[(int)(all->player.y_coord)][(int)
		(all->player.x_coord - all->ray.abscissa * MOVE_CHECK)] != '1')
			all->player.x_coord -= all->ray.abscissa * MOVE_SPEED;
		if (all->map.map[(int)(all->player.y_coord - all->ray.ordinate
		* MOVE_CHECK)][(int)(all->player.x_coord)] != '1')
			all->player.y_coord -= all->ray.ordinate * MOVE_SPEED;
	}
}

static void		player_changing_direction_of_looking_clockwise(t_all *all)
{
	double	temporary_x_direction;
	double	temporary_abscissa;

	temporary_x_direction = all->player.x_direction;
	temporary_abscissa = all->ray.abscissa;
	if (all->key.clockwise)
	{
		all->player.x_direction = temporary_x_direction * COS_ROTATE_SPEED
				- all->player.y_direction * SIN_ROTATE_SPEED;
		all->player.y_direction = temporary_x_direction * SIN_ROTATE_SPEED
				+ all->player.y_direction * COS_ROTATE_SPEED;
		all->ray.abscissa = temporary_abscissa * COS_ROTATE_SPEED
				- all->ray.ordinate * SIN_ROTATE_SPEED;
		all->ray.ordinate = temporary_abscissa * SIN_ROTATE_SPEED
				+ all->ray.ordinate * COS_ROTATE_SPEED;
	}
}

static void		player_changing_direction_of_looking_anticlockwise(t_all *all)
{
	double	temporary_x_direction;
	double	temporary_abscissa;

	temporary_x_direction = all->player.x_direction;
	temporary_abscissa = all->ray.abscissa;
	if (all->key.anticlockwise)
	{
		all->player.x_direction = temporary_x_direction * COS_ROTATE_SPEED
				+ all->player.y_direction * SIN_ROTATE_SPEED;
		all->player.y_direction = -temporary_x_direction * SIN_ROTATE_SPEED
				+ all->player.y_direction * COS_ROTATE_SPEED;
		all->ray.abscissa = temporary_abscissa * COS_ROTATE_SPEED
							+ all->ray.ordinate * SIN_ROTATE_SPEED;
		all->ray.ordinate = -temporary_abscissa * SIN_ROTATE_SPEED
							+ all->ray.ordinate * COS_ROTATE_SPEED;
	}
}

int				engine(t_all *all)
{
	int	litmus;

	litmus = 0;
	if (all->key.forward || all->key.backward || all->key.left ||
														all->key.right)
	{
		player_movement_forward_backward(all);
		player_movement_left_right(all);
		litmus = 1;
	}
	if (all->key.clockwise || all->key.anticlockwise)
	{
		player_changing_direction_of_looking_clockwise(all);
		player_changing_direction_of_looking_anticlockwise(all);
		litmus = 1;
	}
	if (litmus)
	{
		mlx_destroy_image(all->mlx, all->image.snapshot);
		create_image(all);
		ray_casting(all);
		mlx_put_image_to_window(all->mlx, all->win, all->image.snapshot, 0, 0);
		litmus = 0;
	}
	return (0);
}
