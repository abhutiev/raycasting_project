/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoge <gdoge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 06:51:45 by gdoge             #+#    #+#             */
/*   Updated: 2020/12/16 07:01:42 by gdoge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_movement(t_all *all)
{
	all->player.step_cos = cosf(all->player.angle) * MOVE_SPEED;
	all->player.step_sin = sinf(all->player.angle) * MOVE_SPEED;
	if (wall_detection_x_forward(all) && all->key.forward)
		all->player.x_coord += all->player.step_cos;
	if (wall_detection_y_forward(all) && all->key.forward)
		all->player.y_coord += all->player.step_sin;
	if (wall_detection_x_backward(all) && all->key.backward)
		all->player.x_coord -= all->player.step_cos;
	if (wall_detection_y_backward(all) && all->key.backward)
		all->player.y_coord -= all->player.step_sin;
	if (wall_detection_x_left(all) && all->key.left)
		all->player.x_coord += all->player.step_sin;
	if (wall_detection_y_left(all) && all->key.left)
		all->player.y_coord -= all->player.step_cos;
	if (wall_detection_x_left(all) && all->key.right)
		all->player.x_coord -= all->player.step_sin;
	if (wall_detection_y_left(all) && all->key.right)
		all->player.y_coord += all->player.step_cos;
}

void	player_changing_direction_of_looking(t_all *all)
{
	if (all->key.clockwise)
	{
		all->player.angle += M_PI / 180 * ROTATE_SPEED;
	}
	if (all->key.anticlockwise)
	{
		all->player.angle -= M_PI / 180 * ROTATE_SPEED;
	}
}

int		action(t_all *all)
{
	if (all->key.forward || all->key.backward || all->key.left ||
														all->key.right)
	{
		player_movement(all);
	}
	if (all->key.clockwise || all->key.anticlockwise)
	{
		player_changing_direction_of_looking(all);
	}
	printf("%f\n", all->player.x_coord);
	printf("%f\n", all->player.y_coord);
	printf("%f\n", all->player.angle);
	return (0);
}
