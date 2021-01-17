/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 14:56:32 by gpaul             #+#    #+#             */
/*   Updated: 2021/01/15 17:31:09 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_str_minus(t_struct *list)
{
	int		size;
	char	*s2;
	int		i;

	i = 0;
	size = ft_strlen(list->d_para) - 1;
	if (!(s2 = malloc(sizeof(char) * (size + 1))))
		return (0);
	while (list->d_para[1 + i])
	{
		s2[i] = list->d_para[1 + i];
		i++;
	}
	s2[i] = '\0';
	free(list->d_para);
	return (s2);
}

void	ft_flags_nbr(t_struct *list, t_flags *flags, int size)
{
	int	minus;

	minus = 0;
	if (flags->minus == 0 || flags->dot == 1)
	{
		//printf("width == %d size == %d\n", flags->width, size);
		if (list->d_para[0] == '-' && (flags->zero == 1 || flags->dot == 1 || flags->minus == 1))
		{
			minus = 1;
			write(1, "-", 1);
			list->d_para = ft_str_minus(list);
			list->nbr_print = list->nbr_print + 1;
			size--;
		}
		while (flags->width > size)
		{
			if (flags->dot == 1 || flags->zero == 1)
				write(1, "0", 1);
			else
				write(1, " ", 1);
			flags->width = flags->width - 1;
			list->nbr_print = list->nbr_print + 1;
		}
	}
		write(1, list->d_para, size);
	if (flags->minus == 1)
	{
		while (flags->width > size)
		{
			write(1, " ", 1);
			flags->width = flags->width - 1;
			list->nbr_print = list->nbr_print + 1;
		}
	}
	list->nbr_print = list->nbr_print + size;
}
