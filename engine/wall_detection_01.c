/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_detection_01.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoge <gdoge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 05:56:38 by gdoge             #+#    #+#             */
/*   Updated: 2020/12/15 08:46:05 by gdoge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int8_t	wall_detection_x_left(t_all *all)
{
	if (all->map.map[(int)(all->player.x_coord +
					all->player.step_sin)][(int)(all->player.y_coord)] != '1')
	{
		return (1);
	}
	return (0);
}

int8_t	wall_detection_y_left(t_all *all)
{
	if (all->map.map[(int)(all->player.x_coord)][(int)(all->player.y_coord -
						all->player.step_cos)] != '1')
	{
		return (1);
	}
	return (0);
}

int8_t	wall_detection_x_right(t_all *all)
{
	if (all->map.map[(int)(all->player.x_coord -
					all->player.step_sin)][(int)(all->player.y_coord)] != '1')
	{
		return (1);
	}
	return (0);
}

int8_t	wall_detection_y_right(t_all *all)
{
	if (all->map.map[(int)(all->player.x_coord)][(int)(all->player.y_coord +
						all->player.step_cos)] != '1')
	{
		return (1);
	}
	return (0);
}
