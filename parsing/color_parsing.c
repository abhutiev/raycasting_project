/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoge <gdoge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 16:13:17 by gdoge             #+#    #+#             */
/*   Updated: 2020/12/07 14:41:47 by gdoge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			color_validation_check(t_config config)
{
	if (config.ceiling_color[0] > 255 || config.ceiling_color[0] < 0
	|| config.ceiling_color[1] > 255 || config.ceiling_color[1] < 0
	|| config.ceiling_color[2] > 255 || config.ceiling_color[2] < 0)
	{
		write(2, "Error\nWrong RGB for ceiling\n", 29);
		exit(0);
	}
	if (config.floor_color[0] > 255 || config.floor_color[0] < 0
	|| config.floor_color[1] > 255 || config.floor_color[1] < 0
	|| config.floor_color[2] > 255 || config.floor_color[2] < 0)
	{
		write(2, "Error\nWrong RGB for floor\n", 27);
		exit(0);
	}
}

t_config		ceiling_color_parsing(char *string_with_color, t_config config)
{
	size_t	i;

	i = 0;
	if (config.ceiling_color[0] != -1 || config.ceiling_color[1] != -1 ||
	config.ceiling_color[2] != -1)
	{
		write(2, "Error\nDouble definition of ceiling color\n", 41);
		exit(0);
	}
	config.ceiling_color[0] = ft_atoi(string_with_color);
	while (string_with_color[i] != ',' && string_with_color[i])
		i++;
	config.ceiling_color[1] = ft_atoi(string_with_color + 1 + i++);
	while (string_with_color[i] != ',' && string_with_color[i])
		i++;
	config.ceiling_color[2] = ft_atoi(string_with_color + i + 1);
	if (config.ceiling_color[0] > 255 || config.ceiling_color[0] < 0
	|| config.ceiling_color[1] > 255 || config.ceiling_color[1] < 0
	|| config.ceiling_color[2] > 255 || config.ceiling_color[2] < 0)
	{
		write(2, "Error\nWrong RGB for ceiling\n", 29);
		exit(0);
	}
	return (config);
}

t_config		floor_color_parsing(char *string_with_color, t_config config)
{
	size_t	i;

	i = 0;
	if (config.floor_color[0] != -1 || config.floor_color[1] != -1 ||
	config.floor_color[2] != -1)
	{
		write(2, "Error\nDouble definition of floor color\n", 39);
		exit(0);
	}
	config.floor_color[0] = ft_atoi(string_with_color);
	while (string_with_color[i] != ',' && string_with_color[i])
		i++;
	config.floor_color[1] = ft_atoi(string_with_color + 1 + i++);
	while (string_with_color[i] != ',' && string_with_color[i])
		i++;
	config.floor_color[2] = ft_atoi(string_with_color + i + 1);
	if (config.floor_color[0] > 255 || config.floor_color[0] < 0
	|| config.floor_color[1] > 255 || config.floor_color[1] < 0
	|| config.floor_color[2] > 255 || config.floor_color[2] < 0)
	{
		write(2, "Error\nWrong RGB for floor\n", 27);
		exit(0);
	}
	return (config);
}
