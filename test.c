/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:11:33 by gpaul             #+#    #+#             */
/*   Updated: 2021/01/15 17:40:05 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int		main(void)
{
	//char c = 'C';
	//char *str = "salut";
	//unsigned int	i	= 4294967295;
	//int		n = 1000;
	//void	*ptr = &n;

	printf ("TEST SIZE %d\n", ft_printf("%8.5d\n", 34));
	printf ("TRUE SIZE %d\n", printf("%8.5d\n", 34));
}
