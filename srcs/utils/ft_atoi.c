/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoge <gdoge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 07:03:51 by gdoge             #+#    #+#             */
/*   Updated: 2020/12/09 05:30:22 by gdoge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int		ft_iswhitespace(char str)
{
	if ((str >= FIRST_WHITESPACE && str <= LAST_WHITESPACE) || (str == SPACE))
		return (1);
	else
		return (0);
}

static int		is_sign(char str)
{
	if ((str == '-') || (str == '+'))
		return (1);
	else
		return (0);
}

int				ft_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned int	res;
	unsigned int	big;

	big = C_LONG_MAX / 10;
	sign = 1;
	i = 0;
	res = -256;
	while (ft_iswhitespace(str[i]) == 1)
		i++;
	if (is_sign(str[i]) == 1)
		if (str[i++] == '-')
			(sign = -1);
	if (ft_isdigit(str[i]))
		res = 0;
	while (ft_isdigit(str[i]))
		res = res * 10 + str[i++] - '0';
	return ((int)(res) * sign);
}
