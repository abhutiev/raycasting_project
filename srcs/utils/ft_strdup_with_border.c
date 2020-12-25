/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_with_border.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoge <gdoge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 05:32:40 by gdoge             #+#    #+#             */
/*   Updated: 2020/12/06 22:51:12 by gdoge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static size_t	ft_strlcpy_with_border(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	while (i < dstsize - 1)
	{
		if (i < src_len)
		{
			if (src[i] == ' ')
			{
				dst[i + 1] = ' ';
				i++;
				continue ;
			}
			dst[i + 1] = src[i];
		}
		else
			dst[i + 1] = ' ';
		i++;
	}
	dst[i + 1] = ' ';
	dst[i + 2] = '\0';
	return (i);
}

char			*ft_strdup_with_border(char *s1, size_t len)
{
	char	*new_str;

	new_str = (char *)malloc(len + 3);
	if (!new_str)
	{
		write(2, "Error/n No one", 14);
		perror(" ever will see this message, but for error management...");
		exit(errno);
	}
	new_str[0] = ' ';
	ft_strlcpy_with_border(new_str, s1, len + 1);
	return (new_str);
}
