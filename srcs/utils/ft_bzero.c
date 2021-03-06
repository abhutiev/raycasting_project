/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoge <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 01:24:50 by gdoge             #+#    #+#             */
/*   Updated: 2020/11/13 13:44:35 by gdoge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	*ft_bzero(void *b, size_t len)
{
	unsigned char	*tmp_mem;
	size_t			i;

	i = 0;
	tmp_mem = (unsigned char *)b;
	while (i < len)
	{
		tmp_mem[i] = 0;
		i++;
	}
	return (b);
}
