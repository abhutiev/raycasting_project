/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_detection_00.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoge <gdoge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 05:54:05 by gdoge             #+#    #+#             */
/*   Updated: 2020/12/15 08:45:41 by gdoge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int8_t	wall_detection_x_forward(t_all *all)
{
	if (all->map.map[(int)(all->player.x_coord +
					all->player.step_cos)][(int)(all->player.y_coord)] != '1')
	{
		return (1);
	}
	return (0);
}

int8_t	wall_detection_y_forward(t_all *all)
{
	if (all->map.map[(int)(all->player.x_coord)][(int)(all->player.y_coord +
						all->player.step_sin)] != '1')
	{
		return (1);
	}
	return (0);
}

int8_t	wall_detection_x_backward(t_all *all)
{
	if (all->map.map[(int)(all->player.x_coord -
					all->player.step_cos)][(int)(all->player.y_coord)] != '1')
	{
		return (1);
	}
	return (0);
}

int8_t	wall_detection_y_backward(t_all *all)
{
	if (all->map.map[(int)(all->player.x_coord)][(int)(all->player.y_coord -
						all->player.step_sin)] != '1')
	{
		return (1);
	}
	return (0);
}
