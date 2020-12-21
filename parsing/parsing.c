/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoge <gdoge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 16:20:38 by gdoge             #+#    #+#             */
/*   Updated: 2020/12/17 04:05:47 by gdoge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_config		config_parsing(t_config conf)
{
	while (get_next_line(conf.fd, &conf.buffer) && !map_started(conf.buffer))
	{
		conf.count = 0;
		while (conf.buffer[conf.count] == ' ')
			conf.count++;
		if (conf.buffer[conf.count] == 'R')
			conf = resolution_parsing(conf.buffer + conf.count, conf);
		else if (ft_strncmp(conf.buffer + conf.count, "NO ", 3) == 0)
			conf = north_texture_parsing(conf.buffer + conf.count + 3, conf);
		else if (ft_strncmp(conf.buffer + conf.count, "WE ", 3) == 0)
			conf = west_texture_parsing(conf.buffer + conf.count + 3, conf);
		else if (ft_strncmp(conf.buffer + conf.count, "SO ", 3) == 0)
			conf = south_texture_parsing(conf.buffer + conf.count + 3, conf);
		else if (ft_strncmp(conf.buffer + conf.count, "EA ", 3) == 0)
			conf = east_texture_parsing(conf.buffer + conf.count + 3, conf);
		else if (ft_strncmp(conf.buffer + conf.count, "S ", 2) == 0)
			conf = sprite_texture_parsing(conf.buffer + conf.count + 2, conf);
		else if (ft_strncmp(conf.buffer + conf.count, "C ", 2) == 0)
			conf = ceiling_color_parsing(conf.buffer + conf.count + 1, conf);
		else if (ft_strncmp(conf.buffer + conf.count, "F ", 2) == 0)
			conf = floor_color_parsing(conf.buffer + conf.count + 1, conf);
		free(conf.buffer);
	}
	free(conf.buffer);
	return (conf);
}

static t_config		config_validation(t_config config, void *mlx)
{
	int	size_x;
	int	size_y;

	if (config.path_north == NULL || config.path_south == NULL
	|| config.path_west == NULL || config.path_east == NULL
	|| config.path_sprite == NULL)
	{
		write(2, "Error\nNot all textures are defined\n", 35);
		exit(0);
	}
	mlx_get_screen_size(mlx, &size_x, &size_y);
	if (size_x < config.x_resolution)
		config.x_resolution = size_x;
	if (size_y < config.y_resolution)
		config.y_resolution = size_y;
	color_validation_check(config);
	config.rgb_ceiling = (config.ceiling_color[0] << 16) |
			(config.ceiling_color[1] << 8) | (config.ceiling_color[2]);
	config.rgb_floor = (config.floor_color[0] << 16) |
			(config.floor_color[1] << 8) | (config.floor_color[2]);
	return (config);
}

static t_config		get_config(char *config_file, void *mlx)
{
	t_config	config;

	config = fd_validation(config_file);
	config = config_to_zero(config.fd);
	config = config_parsing(config);
	config = get_number_of_strings(config);
	config = config_validation(config, mlx);
	close(config.fd);
	return (config);
}

t_all				get_all_information_from_config(char *filename)
{
	t_all	all;

	all.mlx = mlx_init();
	if (!all.mlx)
	{
		perror("Error\nIT'S BAD ERROR, I REALLY HAVE NO IDEA, HOW TO FIX IT");
		exit(errno);
	}
	all.config = get_config(filename, all.mlx);
	all.map.map = map_parsing(all.config, filename);
	all.win = mlx_new_window(all.mlx, all.config.x_resolution,
						all.config.y_resolution, "cub3D");
	if (!all.mlx)
	{
		perror("Error\nIT'S BAD ERROR, I REALLY HAVE NO IDEA, HOW TO FIX IT");
		exit(errno);
	}
	player_parsing(all.map.map, &all);
	return (all);
}
