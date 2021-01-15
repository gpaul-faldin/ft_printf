/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:29:24 by gpaul             #+#    #+#             */
/*   Updated: 2021/01/15 03:11:54 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int			ft_check_convert(char c)
{
	int i;

	i = 0;
	while (CONVERT[i])
	{
		if (c == CONVERT[i])
			return (0);
		i++;
	}
	return (1);
}

char		*ft_rev(char *re)
{
	int		i;
	int		n;
	char	temp;

	i = 0;
	n = ft_strlen(re);
	while (i < n)
	{
		n--;
		temp = re[i];
		re[i] = re[n];
		re[n] = temp;
		i++;
	}
	return (re);
}

int			size_count(unsigned int n)
{
	int		res;

	res = 0;
	while (n != 0)
	{
		n /= 10;
		res++;
	}
	return (res + 1);
}

int			size_ptr(long long int n)
{
	int		res;

	res = 0;
	while (n != 0)
	{
		n /= 10;
		res++;
	}
	return (res + 1);
}

char		*ft_strdup_flags(char *s1, int index)
{
	int		size;
	char	*s2;
	int		n;

	size = 0;
	n = 0;
	while (ft_check_convert(s1[index + size]) == 1)
		size++;
	if (!(s2 = malloc(sizeof(char) * (size + 1))))
		return (0);
	while (n < size)
	{
		s2[n] = s1[index + n];
		n++;
	}
	s2[n] = '\0';
	return (s2);
}
