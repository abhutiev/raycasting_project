/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoge <gdoge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 15:29:58 by gdoge             #+#    #+#             */
/*   Updated: 2020/12/01 03:04:14 by gdoge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void		error_management(void *checked)
{
	if (!checked)
	{
		write(2, "Error/n No one", 14);
		perror(" ever will see this message, but for error management...");
		exit(errno);
	}
}

static size_t	ncopy(char **dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		(*dst)[i] = src[i];
		i++;
	}
	(*dst)[i] = '\0';
	return (i);
}

int				get_next_line(int fd, char **line)
{
	char	*buffer;
	char	check;
	int		eof;
	size_t	i;

	if (!line || (read(fd, &check, 0) < 0))
		return (-1);
	i = 0;
	eof = 1;
	buffer = (char *)malloc(2048);
	error_management((void *)buffer);
	while (read(fd, &buffer[i], 1) == 1)
	{
		if (buffer[i] == '\n')
		{
			eof = 0;
			break ;
		}
		i++;
	}
	(*line) = (char *)malloc(i + 1);
	error_management((void *)(*line));
	ncopy(line, buffer, i);
	free(buffer);
	return (!eof);
}
