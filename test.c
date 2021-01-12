/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:11:33 by gpaul             #+#    #+#             */
/*   Updated: 2021/01/12 19:46:25 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int		main(void)
{
	char c = 'C';
	char *str = "salut";
	unsigned int	i	= 4294967295;
	int		n = 1000;
	void	*ptr = &n;


	printf ("TEST SIZE %d\n", ft_printf("TEST == %p %% %c %s %d %i %u %x %X\n",ptr, c, str, n, n, i, n, n));
	printf ("TRUE SIZE %d\n", printf("TRUE == %p %% %c %s %d %i %u %x %X\n",ptr, c, str, n, n, i, n, n));
}
