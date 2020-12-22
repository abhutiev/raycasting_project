/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoge <gdoge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:30:40 by gdoge             #+#    #+#             */
/*   Updated: 2020/12/16 07:00:47 by gdoge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strdup(const char *s1)
{
	size_t	memory;
	char	*new_str;

	memory = ft_strlen(s1);
	new_str = (char *)malloc(memory + 1);
	if (new_str == NULL)
		return (NULL);
	ft_strlcpy(new_str, s1, memory + 1);
	return (new_str);
}
