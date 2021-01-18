/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 14:56:32 by gpaul             #+#    #+#             */
/*   Updated: 2021/01/18 19:40:36 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_para_zero(t_flags *flags, t_struct *list)
{
	while (flags->width)
	{
		write(1, " ", 1);
		flags->width = flags->width - 1;
		list->nbr_print = list->nbr_print + 1;
	}
}

void	ft_negati(t_struct *list, t_flags *flags)
{
	write(1, "-", 1);
	list->d_para = ft_str_minus(list);
	if (flags->preci != -1)
		flags->width = flags->width - 1;
}

void	ft_width_preci(t_struct *list, t_flags *flags, int size)
{
	int	temp;

	temp = flags->width - flags->preci;
	while (temp != 0 && flags->width > size && flags->minus == 0 && temp-- &&
	flags->width-- && ++list->nbr_print)
		write(1, " ", 1);
	while (flags->width - temp > size &&
	flags->width-- && ++list->nbr_print)
	{
		if (flags->dot == 1 || flags->zero == 1)
			write(1, "0", 1);
		else
			write(1, " ", 1);
	}
	write(1, list->d_para, size);
	while (flags->width > size && flags->minus == 1 &&
	flags->width-- && ++list->nbr_print)
	{
		write(1, " ", 1);
	}
	list->nbr_print = list->nbr_print + size;
}

void	ft_flags_nbr(t_struct *list, t_flags *flags, int size)
{
	if ((size == 1 && list->d_para[0] == '0' && flags->dot == 1 &&
	flags->preci == 0) || (flags->preci > 0 && flags->width > 0))
	{
		if (flags->preci != 0 && flags->width != 0)
			ft_width_preci(list, flags, size);
		else
			ft_para_zero(flags, list);
		return ;
	}
	if (flags->minus == 0 || flags->dot == 1)
	{
		if (list->d_para[0] == '-' && (flags->zero == 1 || flags->dot == 1 ||
		flags->minus == 1) && ++list->nbr_print && --size)
			ft_negati(list, flags);
		while (flags->width-- > size && ++list->nbr_print)
		{
			if (flags->dot == 1 || flags->zero == 1)
				write(1, "0", 1);
			else
				write(1, " ", 1);
		}
	}
	write(1, list->d_para, size);
	if (flags->minus == 1)
		while (flags->width-- > size && ++list->nbr_print)
			write(1, " ", 1);
	list->nbr_print = list->nbr_print + size;
}
