/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_arguments_checking.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoge <gdoge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 14:31:22 by gdoge             #+#    #+#             */
/*   Updated: 2020/12/07 14:35:47 by gdoge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	program_arguments_checking(int argc, char **argv, t_all *all)
{
	if (argc > 3 || argc < 2)
	{
		write(2, "Error\nWrong number of arguments\n", 32);
		exit(0);
	}
	if (argc == 3)
	{
		if (ft_strncmp(argv[2], "--save", 7))
		{
			write(2, "Error\nSecond argument isn't request for shot\n", 46);
			exit(0);
		}
		else
			all->screenshot.flag = 1;
	}
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub\0", 5))
	{
		write(2, "Error\nWrong format of configuration file\n", 41);
		exit(0);
	}
}
