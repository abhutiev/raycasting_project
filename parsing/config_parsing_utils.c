/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_parsing_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoge <gdoge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 16:15:31 by gdoge             #+#    #+#             */
/*   Updated: 2020/12/07 14:39:05 by gdoge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			map_started(char *string)
{
	size_t	i;

	i = 0;
	while (string[i] == ' ' && string[i] != '\n' && string[i])
	{
		i++;
	}
	if (ft_strlen(string) && (string[i] != 'R' && string[i] != 'S' &&
	string[i] != 'N' && string[i] != 'W' && string[i] != 'E' &&
	string[i] != 'F' && string[i] != 'C'))
	{
		if (string[i] != '1' && string[i] != '2' && string[i] != '\n'
		&& string[i] != '0' && string[i] != '\0')
		{
			write(2, "Error\nBad config\n", 17);
			exit(0);
		}
		return (1);
	}
	else
	{
		return (0);
	}
}

t_config	config_to_zero(int fd)
{
	t_config	config;

	config.x_resolution = -1;
	config.y_resolution = -1;
	config.path_east = NULL;
	config.path_west = NULL;
	config.path_north = NULL;
	config.path_south = NULL;
	config.path_sprite = NULL;
	config.floor_color[0] = -1;
	config.floor_color[1] = -1;
	config.floor_color[2] = -1;
	config.ceiling_color[0] = -1;
	config.ceiling_color[1] = -1;
	config.ceiling_color[2] = -1;
	config.number_of_strings = 2;
	config.fd = fd;
	config.validity = 1;
	return (config);
}

t_config	fd_validation(char *config_file)
{
	t_config	config;
	char		*string;

	config.fd = open(config_file, O_RDONLY);
	if (config.fd < 3 || get_next_line(config.fd, &string) < 0)
	{
		config.validity = 0;
		perror("Error\nBad name of file");
		exit(errno);
	}
	else
	{
		close(config.fd);
		free(string);
		config.fd = open(config_file, O_RDONLY);
		return (config);
	}
}

t_config	get_number_of_strings(t_config config)
{
	while (get_next_line(config.fd, &config.buffer))
	{
		config.number_of_strings++;
		free(config.buffer);
	}
	return (config);
}
