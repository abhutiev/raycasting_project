/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parsed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoge <gdoge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 03:41:04 by gdoge             #+#    #+#             */
/*   Updated: 2020/12/16 04:31:51 by gdoge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_way_to_textures(t_all *all)
{
	free(all->config.path_east);
	free(all->config.path_west);
	free(all->config.path_north);
	free(all->config.path_south);
	free(all->config.path_sprite);
}
