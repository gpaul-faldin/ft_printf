/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:11:33 by gpaul             #+#    #+#             */
/*   Updated: 2021/01/15 03:04:35 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int		main(void)
{
	//char c = 'C';
	char *str = "salut";
	//unsigned int	i	= 4294967295;
	int		n = 1000;
	//void	*ptr = &n;

	printf ("TEST SIZE %d\n", ft_printf("TEST == %.*s    %s    %-*d\n", 3, str, str, 6, n));
	printf ("TRUE SIZE %d\n", printf("TRUE == %.*s    %s    %-*d\n", 3, str, str, 6, n));
}
