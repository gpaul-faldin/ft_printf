/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:11:33 by gpaul             #+#    #+#             */
/*   Updated: 2021/01/15 02:25:22 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int		main(void)
{
	//char c = 'C';
	//char *str = "salut";
	//unsigned int	i	= 4294967295;
	int		n = 1000;
	//void	*ptr = &n;

	printf ("TEST SIZE %d\n", ft_printf("TEST == %0*d    %.5d\n", 10, n, 325));
	printf ("TRUE SIZE %d\n", printf("TRUE == %0*d    %.5d\n", 10, n, 325));
}
