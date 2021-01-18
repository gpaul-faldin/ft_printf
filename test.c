/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:11:33 by gpaul             #+#    #+#             */
/*   Updated: 2021/01/18 22:17:20 by gpaul            ###   ########.fr       */
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

	printf ("TEST SIZE %d\n", ft_printf("%10.5d\n", -216));
	printf ("TRUE SIZE %d\n", printf("%10.5d\n", -216));

}
