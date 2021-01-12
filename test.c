/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:11:33 by gpaul             #+#    #+#             */
/*   Updated: 2021/01/12 18:31:10 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int		main(void)
{
	char c = 'C';
	char *str = "salut";
	unsigned int	i	= 4294967295;
	//int	*test = &i;
	int		n = 1000;

	printf ("TEST SIZE %d\n", ft_printf("TEST ==   %c   %%   %d   %X   %x   %s   %i   %u\n",c ,n, n, n, str, 0x12, i));
	printf ("TRUE SIZE %d\n", printf("TRUE ==   %c   %%   %d   %X   %x   %s   %i   %u\n",c ,n, n, n, str, 0x12, i));
}
