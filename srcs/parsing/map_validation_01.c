/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_01.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoge <gdoge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 23:33:20 by gdoge             #+#    #+#             */
/*   Updated: 2020/12/07 14:49:03 by gdoge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	map_error_management(void *checked)
{
	if (!checked)
	{
		write(2, "Error/n No one", 14);
		perror(" ever will see this message, but for error management...");
		exit(errno);
	}
}

static char	**map_filling(char **map, size_t number_of_strings, size_t longest)
{
	size_t	i;
	size_t	j;
	char	**new_map;

	i = 0;
	j = 0;
	new_map = (char **)malloc(8 * number_of_strings + 24);
	map_error_management((void *)new_map);
	new_map[0] = (char *)malloc(longest + 3);
	map_error_management((void *)new_map[0]);
	new_map[0][j] = '\0';
	while (map[i])
	{
		new_map[i + 1] = ft_strdup_with_border(map[i], longest);
		i++;
	}
	new_map[i + 1] = NULL;
	return (new_map);
}

static void	free_filled(char **filled, size_t number_of_strings)
{
	size_t	i;

	i = 0;
	while (i < number_of_strings + 2)
	{
		free(filled[i]);
		i++;
	}
	free(filled);
}

void		check_if_closed(char **map, t_config config)
{
	int		i;
	int		j;
	char	**f;

	i = -1;
	f = map_filling(map, config.number_of_strings, config.longest_string);
	while (f[++i])
	{
		j = -1;
		while (f[i][++j])
		{
			if ((f[i][j] == '0' || f[i][j] == 'W' || f[i][j] == 'S' ||
			f[i][j] == 'E' || f[i][j] == 'N' || f[i][j] == '2') &&
			(f[i - 1][j - 1] == ' ' || f[i - 1][j] == ' ' ||
			f[i - 1][j + 1] == ' ' || f[i][j - 1] == ' ' ||
			f[i][j + 1] == ' ' || f[i][j] == ' ' || f[i + 1][j - 1] == ' ' ||
			f[i + 1][j] == ' ' || f[i + 1][j + 1] == ' '))
			{
				write(2, "Error\nMap is not closed\n", 24);
				exit(0);
			}
		}
	}
	free_filled(f, config.number_of_strings);
}
