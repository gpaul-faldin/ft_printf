/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 14:56:32 by gpaul             #+#    #+#             */
/*   Updated: 2021/01/18 11:38:38 by gpaul            ###   ########.fr       */
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

void	ft_para_zero(t_flags *flags, t_struct *list)
{
	while(flags->width)
	{
		write(1, " ", 1);
		flags->width = flags->width - 1;
		list->nbr_print = list->nbr_print + 1;
	}
}


void	ft_width_preci(t_struct *list, t_flags *flags, int size)
{
	
	
}

void	ft_flags_nbr(t_struct *list, t_flags *flags, int size)
{
	int	minus;

	minus = 0;
		//printf("width == %d size == %d\n", flags->width, size);
	if (size == 1 && list->d_para[0] == '0' && flags->dot == 1 && flags->preci == 0)
	{
		ft_para_zero(flags, list);
		return ;
	}
	if (flags->preci != 0 && flags->width != 0)
	{
		ft_width_preci(list, flags, size);
		return ;
	}
	if (flags->minus == 0 || flags->dot == 1)
	{
		if (list->d_para[0] == '-' && (flags->zero == 1 || flags->dot == 1 || flags->minus == 1))
		{
			minus = 1;
			write(1, "-", 1);
			list->d_para = ft_str_minus(list);
			list->nbr_print = list->nbr_print + 1;
			flags->width = flags->width - 1;
			size--;
		}
		while (flags->preci > size || flags->width > size)
		{
			if (flags->dot == 1 || flags->zero == 1)
				write(1, "0", 1);
			else
				write(1, " ", 1);
			if (flags->width > size)
				flags->width = flags->width - 1;
			else 
				flags->preci = flags->preci - 1;
			list->nbr_print = list->nbr_print + 1;
		}
	}
		

	if (flags->width != 0 || flags->preci != 0)
		write(1, list->d_para, size);
	if (flags->minus == 1)
	{
		while (flags->preci > size || flags->width > size)
		{
			write(1, " ", 1);
			if (flags->width > size)
				flags->width = flags->width - 1;
			else
				flags->preci = flags->preci - 1;
			list->nbr_print = list->nbr_print + 1;
		}
	}
	if (flags->width != 0 || flags->preci != 0)
		list->nbr_print = list->nbr_print + size;
}
