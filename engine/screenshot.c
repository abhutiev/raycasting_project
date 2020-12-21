/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoge <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 19:02:00 by gdoge             #+#    #+#             */
/*   Updated: 2020/12/21 19:02:02 by gdoge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	screenshot_recording(t_all *all)
{
	all->screenshot.count = 0;
	all->screenshot.length = all->image.bits_per_pixel
			/ 8 * all->config.x_resolution;
	if ((all->screenshot.fd = open("cub3D.bmp", O_RDWR | O_CREAT, 0755)) < 0)
		return ;
	write(all->screenshot.fd, all->screenshot.bih, 40);
	write(all->screenshot.fd, all->screenshot.bfh, 14);
	while (all->screenshot.count < all->config.y_resolution)
	{
		write(all->screenshot.fd, all->image.image_adress +
		all->screenshot.count * all->image.size_line, all->screenshot.length);
		all->screenshot.count++;
	}
	close(all->screenshot.fd);
}

static void	bmp_metainfo(t_all *all)
{
	all->screenshot.size_of_file = 54 + all->config.x_resolution *
			all->config.y_resolution * all->image.bits_per_pixel / 8;
	all->screenshot.bih[0] = (unsigned char)(40);
	all->screenshot.bih[4] = (unsigned char)(all->config.x_resolution);
	all->screenshot.bih[5] = (unsigned char)(all->config.x_resolution >> 8);
	all->screenshot.bih[6] = (unsigned char)(all->config.x_resolution >> 16);
	all->screenshot.bih[7] = (unsigned char)(all->config.x_resolution >> 24);
	all->screenshot.bih[8] = (unsigned char)(-all->config.y_resolution);
	all->screenshot.bih[9] = (unsigned char)(-all->config.y_resolution >> 8);
	all->screenshot.bih[10] = (unsigned char)(-all->config.y_resolution >> 16);
	all->screenshot.bih[11] = (unsigned char)(-all->config.y_resolution >> 24);
	all->screenshot.bih[12] = (unsigned char)(1);
	all->screenshot.bih[14] = (unsigned char)(all->image.bits_per_pixel);
	all->screenshot.bfh[0] = 'B';
	all->screenshot.bfh[1] = 'M';
	all->screenshot.bfh[2] = (unsigned char)all->screenshot.size_of_file;
	all->screenshot.bfh[3] = (unsigned char)(all->screenshot.size_of_file >> 8);
	all->screenshot.bfh[4] =
			(unsigned char)(all->screenshot.size_of_file >> 16);
	all->screenshot.bfh[5] =
			(unsigned char)(all->screenshot.size_of_file >> 24);
	all->screenshot.bfh[10] = (unsigned char)(54);
}

void		make_screenshot(t_all *all)
{
	ft_bzero(all->screenshot.bih, 40);
	ft_bzero(all->screenshot.bfh, 14);
	bmp_metainfo(all);
	screenshot_recording(all);
	exit(0);
}
