/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loops_and_hooks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoge <gdoge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 20:53:19 by gdoge             #+#    #+#             */
/*   Updated: 2020/12/15 06:52:05 by gdoge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	fix_keypress(int keycode, t_all *all)
{
	if (keycode == ESCAPE)
		exit(0);
	if (keycode == KEY_W || keycode == KEY_UP)
		all->key.forward = 1;
	if (keycode == KEY_S || keycode == KEY_DOWN)
		all->key.backward = 1;
	if (keycode == KEY_A)
		all->key.left = 1;
	if (keycode == KEY_D)
		all->key.right = 1;
	if (keycode == KEY_RIGHT || keycode == KEY_E)
		all->key.clockwise = 1;
	if (keycode == KEY_LEFT || keycode == KEY_Q)
		all->key.anticlockwise = 1;
	return (0);
}

static int	fix_keyrelease(int keycode, t_all *all)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		all->key.forward = 0;
	if (keycode == KEY_S || keycode == KEY_DOWN)
		all->key.backward = 0;
	if (keycode == KEY_A)
		all->key.left = 0;
	if (keycode == KEY_D)
		all->key.right = 0;
	if (keycode == KEY_RIGHT || keycode == KEY_E)
		all->key.clockwise = 0;
	if (keycode == KEY_LEFT || keycode == KEY_Q)
		all->key.anticlockwise = 0;
	return (0);
}

static int	red_cross(void)
{
	exit(0);
}

void		combined_loop(t_all *all)
{
	mlx_hook(all->win, KEYPRESS_EVENT, KEYPRESS_MASK, &fix_keypress, all);
	mlx_hook(all->win, KEYRELEASE_EVENT, KEYRELEASE_MASK, &fix_keyrelease, all);
	mlx_hook(all->win, DESTROY_NOTIFY_EVENT, NO_EVENT_MASK, &red_cross, 0);
	mlx_loop_hook(all->mlx, &engine, all);
	mlx_loop(all->mlx);
}
