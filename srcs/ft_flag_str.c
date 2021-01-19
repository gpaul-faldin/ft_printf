/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:05:58 by gpaul             #+#    #+#             */
/*   Updated: 2021/01/19 20:11:59 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_width_preci_str(t_struct *list, t_flags *flags, int size)
{
	int	temp;

	temp = flags->width - flags->preci;
	while (temp > 0 && flags->minus == 0)
	{
		write(1, " ", 1);
		flags->width--;
		list->nbr_print++;
		temp--;
	}
	if (temp < 0 || flags->width - temp > size)
		write(1, list->s_para, size);
	else
		write(1, list->s_para, flags->width - temp);
	while ((temp > 0 || flags->width > size) && flags->minus == 1)
	{
		write(1, " ", 1);
		flags->width--;
		list->nbr_print++;
		temp--;
	}
	if (temp != 0)
		list->nbr_print = list->nbr_print + size;
	else
		list->nbr_print = list->nbr_print + flags->width;
}

void	ft_write_p_w(t_struct *list, t_flags *flags, int size)
{
	if (flags->width < size && flags->width != 0)
	{
		write(1, list->s_para, flags->width);
		list->nbr_print += flags->width;
	}
	else if (flags->preci < size)
	{
		write(1, list->s_para, flags->preci);
		list->nbr_print += flags->preci;
	}
	else
	{
		write(1, list->s_para, size);
		list->nbr_print += size;
	}
}

void	ft_flag_str(t_struct *list, t_flags *flags, int size)
{
	while (flags->width > size && flags->minus == 0)
	{
		if (flags->zero == 0)
			write(1, " ", 1);
		else
			write(1, "0", 1);
		flags->width--;
		list->nbr_print++;
	}
	if (flags->preci > 0 && flags->width > 0)
	{
		ft_width_preci_str(list, flags, size);
		return ;
	}
	if (flags->dot == 0)
		write(1, list->s_para, size);
	else
	{
		ft_write_p_w(list, flags, size);
		return ;
	}
	while (flags->width-- > size && flags->minus == 1 && ++list->nbr_print)
		write(1, " ", 1);
	list->nbr_print += size;
}
