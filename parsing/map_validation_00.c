/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_00.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoge <gdoge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 20:05:52 by gdoge             #+#    #+#             */
/*   Updated: 2020/12/07 14:38:44 by gdoge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_number_of_players(char **map)
{
	size_t	i;
	size_t	j;
	size_t	player_count;

	i = 0;
	player_count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'W' ||
			map[i][j] == 'S' || map[i][j] == 'E')
			{
				player_count++;
			}
			j++;
		}
		i++;
	}
	if (player_count != 1)
	{
		write(2, "Error\nWrong number of players\n", 30);
		exit(0);
	}
}

void	check_unwanted_symbols(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != 'N' && map[i][j] != 'W' && map[i][j] != 'S' &&
			map[i][j] != 'E' && map[i][j] != '1' && map[i][j] != '2' &&
			map[i][j] != '0' && map[i][j] != ' ' && map[i][j] != '\n')
			{
				write(2, "Error\nUnwanted symbols in map!\n", 31);
				exit(0);
			}
			j++;
		}
		i++;
	}
}

void	check_gap(t_config config)
{
	char	*check;

	while (get_next_line(config.fd, &check))
	{
		if (ft_strlen(check))
		{
			write(2, "Error\nGaps are forbidden!\n", 26);
			exit(0);
		}
		free(check);
	}
	if (ft_strlen(check))
	{
		write(2, "Error\nGaps are forbidden!\n", 26);
		exit(0);
	}
}
