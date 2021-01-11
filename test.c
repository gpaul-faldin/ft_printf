/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:11:33 by gpaul             #+#    #+#             */
/*   Updated: 2021/01/11 16:56:48 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int		main(void)
{
	char c = 'C';
	char *str = "salut";
	int	i		= 250;
	int res		= 0;

	res = ft_printf("TEST == %s   %c   %d\n", str, c, i);
	printf ("TRUE %d\n", printf("TRUE == %s   %c   %d\n", str, c, i));
	printf("%d\n", res);
}
