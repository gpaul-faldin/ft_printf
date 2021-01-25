/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:11:33 by gpaul             #+#    #+#             */
/*   Updated: 2021/01/22 18:51:16 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int		main(void)
{
	//char c = 'C';
	//char *str = "hello";
	//char *str2 = "world";
	//unsigned int	i	= 4294967295;
	//int		n = 1000;
	//void	*ptr = &n;

	//char *hide = "hi low\0don't print me lol\0";

	printf ("TEST SIZE %d\n", ft_printf("%%-5.3s LYDI == |%-5.3s|\n", "LYDI"));
	printf ("TRUE SIZE %d\n", printf("%%-5.3s LYDI == |%-5.3s|\n", "LYDI"));
	//ft_printf("this %u number", 0);
	//printf("\n");
	//printf("%7.7s%3.7s", "hello", "world");

}
