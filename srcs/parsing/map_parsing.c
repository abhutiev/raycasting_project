/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoge <gdoge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 19:07:21 by gdoge             #+#    #+#             */
/*   Updated: 2020/12/07 01:49:31 by gdoge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**map_parsing(t_config config, char *filename)
{
	char	**map;
	size_t	i;
	int		gap_check;

	i = 1;
	config.fd = open(filename, O_RDONLY);
	map = (char **)malloc((config.number_of_strings + 1) * sizeof(char *));
	map[config.number_of_strings] = NULL;
	while (get_next_line(config.fd, &map[0]) && !map_started(map[0]))
	{
		free(map[0]);
	}
	config.longest_string = ft_strlen(map[0]);
	while ((gap_check = get_next_line(config.fd, &map[i])) &&
	gap_check && ft_strlen(map[i]))
	{
		if (ft_strlen(map[i++]) > config.longest_string)
			config.longest_string = ft_strlen(map[i - 1]);
	}
	if (gap_check != 0)
		check_gap(config);
	map[i + 1] = NULL;
	map_validation(map, config);
	close(config.fd);
	return (map);
}
