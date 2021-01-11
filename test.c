/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:11:33 by gpaul             #+#    #+#             */
/*   Updated: 2021/01/11 16:39:15 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int		main(void)
{
	char c = 'C';
	char *str = "salut";
	int	i		= 0;

	i = ft_printf("TEST == %s   %c\n", str, c);
	printf ("TRUE %d\n", printf("TRUE == %s   %c\n", str, c));
	printf("%d\n", i);
}
