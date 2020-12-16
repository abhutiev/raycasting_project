/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution_parsing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoge <gdoge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 16:18:04 by gdoge             #+#    #+#             */
/*   Updated: 2020/12/07 14:37:30 by gdoge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	duplicate_resolution_message(void)
{
	write(2, "Error\nDuplicate resolution\n", 27);
	exit(0);
}

static void	bad_resolution_message(void)
{
	write(2, "Error\nBad resolution\n", 21);
	exit(0);
}

t_config	resolution_parsing(char *string_to_parse, t_config config)
{
	int		i;

	i = 1;
	if (config.x_resolution != -1 || config.y_resolution != -1)
		duplicate_resolution_message();
	while (!ft_isdigit(string_to_parse[i]) && string_to_parse[i])
		i++;
	config.x_resolution = ft_atoi(string_to_parse + i);
	while (ft_isdigit(string_to_parse[i]) && string_to_parse[i])
		i++;
	while (!ft_isdigit(string_to_parse[i]) && string_to_parse[i])
		i++;
	config.y_resolution = ft_atoi(string_to_parse + i);
	i = -1;
	while (string_to_parse[++i])
		if (string_to_parse[i] == '-')
		{
			write(2, "Error\nBad resolution\n", 21);
			exit(0);
		}
	if (config.x_resolution <= 0 || config.y_resolution <= 0)
		bad_resolution_message();
	return (config);
}
