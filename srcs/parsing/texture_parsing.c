/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoge <gdoge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 16:08:09 by gdoge             #+#    #+#             */
/*   Updated: 2020/12/09 05:23:40 by gdoge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_config		north_texture_parsing(char *string_with_path, t_config config)
{
	size_t	i;
	int		fd_for_check;

	i = 0;
	if (config.path_north)
	{
		write(2, "Error\nNorth texture double definition\n", 32);
		exit(0);
	}
	while (string_with_path[i] == ' ')
	{
		i++;
	}
	config.path_north = ft_strdup(string_with_path + i);
	fd_for_check = open(config.path_north, O_RDONLY);
	if (fd_for_check < 3)
	{
		perror("Error\nWrong path to north texture");
		exit(0);
	}
	close(fd_for_check);
	return (config);
}

t_config		south_texture_parsing(char *string_with_path, t_config config)
{
	size_t	i;
	int		fd_for_check;

	i = 0;
	if (config.path_south)
	{
		write(2, "Error\nSouth texture double definition\n", 32);
		exit(0);
	}
	while (string_with_path[i] == ' ')
	{
		i++;
	}
	config.path_south = ft_strdup(string_with_path + i);
	fd_for_check = open(config.path_south, O_RDONLY);
	if (fd_for_check < 3)
	{
		perror("Error\nWrong path to south texture");
		exit(0);
	}
	close(fd_for_check);
	return (config);
}

t_config		west_texture_parsing(char *string_with_path, t_config config)
{
	size_t	i;
	int		fd_for_check;

	i = 0;
	if (config.path_west)
	{
		write(2, "Error\nWest texture double definition\n", 31);
		exit(0);
	}
	while (string_with_path[i] == ' ')
	{
		i++;
	}
	config.path_west = ft_strdup(string_with_path + i);
	fd_for_check = open(config.path_west, O_RDONLY);
	if (fd_for_check < 3)
	{
		perror("Error\nWrong path to west texture");
		exit(0);
	}
	close(fd_for_check);
	return (config);
}

t_config		sprite_texture_parsing(char *string_with_path, t_config config)
{
	size_t	i;
	int		fd_for_check;

	i = 0;
	if (config.path_sprite)
	{
		write(2, "Error\nSprite texture double definition\n", 39);
		exit(0);
	}
	while (string_with_path[i] == ' ')
	{
		i++;
	}
	config.path_sprite = ft_strdup(string_with_path + i);
	fd_for_check = open(config.path_sprite, O_RDONLY);
	if (fd_for_check < 3)
	{
		perror("Error\nWrong path to sprite texture");
		exit(0);
	}
	close(fd_for_check);
	return (config);
}

t_config		east_texture_parsing(char *string_with_path, t_config config)
{
	size_t	i;
	int		fd_for_check;

	i = 0;
	if (config.path_east)
	{
		write(2, "Error\nEast texture double definition\n", 37);
		exit(0);
	}
	while (string_with_path[i] == ' ')
	{
		i++;
	}
	config.path_east = ft_strdup(string_with_path + i);
	fd_for_check = open(config.path_east, O_RDONLY);
	if (fd_for_check < 3)
	{
		perror("Error\nWrong path to east texture");
		exit(0);
	}
	close(fd_for_check);
	return (config);
}
