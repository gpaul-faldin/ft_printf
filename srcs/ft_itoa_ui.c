/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ui.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 22:42:20 by gpaul             #+#    #+#             */
/*   Updated: 2021/01/20 18:07:32 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static char		*ft_zero(char *re)
{
	re[0] = '0';
	re[1] = '\0';
	return (re);
}

char			*ft_itoa_ui(unsigned int n)
{
	char	*re;
	int		i;

	i = 0;
	if (!(re = malloc(sizeof(char) * size_count(n) + 1)))
		return (0);
	if (n == 0)
		return (ft_zero(re));
	while (n > 0)
	{
		re[i++] = ((n % 10) + '0');
		n = n / 10;
	}
	re[i] = '\0';
	return (ft_rev(re));
}
