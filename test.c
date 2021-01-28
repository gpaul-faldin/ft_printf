/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:11:33 by gpaul             #+#    #+#             */
/*   Updated: 2021/01/28 23:40:14 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int		main(void)
{
	//char c = 'C';
	//char *str = "hello World";
	//char *str2 = "world";
	//unsigned int	i	= 4294967295;
	//int		n = 1000;
	//void	*ptr = &n;

	//char *hide = "hi low\0don't print me lol\0";

	
	//ft_printf("this %u number", 0);
	//printf("\n");
	//printf("%7.7s%3.7s", "hello", "world");


	int		a = 3;
	int		b = -1;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";


	//printf ("TEST SIZE %d\n", ft_printf("%-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s\n", a, b, n, a, b, o, a, b, p, a, b, q, a, b, r, a, b, s, a, b, t, a, b, u));
	//printf ("TRUE SIZE %d\n", printf("%-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s\n", a, b, n, a, b, o, a, b, p, a, b, q, a, b, r, a, b, s, a, b, t, a, b, u));

	//printf ("TEST SIZE %d\n", ft_printf("%-*.*s, \n", 3, -1, n));
	//printf ("TRUE SIZE %d\n", printf("%-*.*s, \n", 3, -1, n));

	printf ("TEST SIZE %d\n", ft_printf("%0*.*d\n", 4, -1, -12));
	printf ("TRUE SIZE %d\n", printf("%0*.*d\n", 4, -1, -12));

	//printf ("TEST SIZE %d\n", ft_printf("{%05.*d}", -15, 42));
	//printf ("TRUE SIZE %d\n", printf("{%05.*d}", -15, 42));

}

//printf("zero == %d\n", flags->zero);


//printf("yooooooooooooo\n");
