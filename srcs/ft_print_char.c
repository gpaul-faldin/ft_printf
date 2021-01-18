/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:27:20 by gpaul             #+#    #+#             */
/*   Updated: 2021/01/18 22:43:21 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_char_flag(t_struct *list, t_flags *flags)
{
	if (flags->minus == 0)
	{
		while (flags->width > 1)
		{
			write(1, " ", 1);
			flags->width--;
			list->nbr_print++;
		}
	}
	ft_putchar_fd(list->c_para, 1);
	if (flags->minus == 1)
	{
		while (flags->width > 1)
		{
			write(1, " ", 1);
			flags->width--;
			list->nbr_print++;
		}
	}
}

void	ft_str_c(char format, t_struct *list, t_flags *flags)
{
	int size;

	size = ft_strlen(list->s_para);
	if (format == CONVERT[0] || format == CONVERT[8])
	{
		if (flags->width > 0)
			ft_char_flag(list, flags);
		else
			ft_putchar_fd(list->c_para, 1);
		list->nbr_print++;
	}
	else
	{
		if (flags->width > 0)
		{
			size++;
			write(1, list->s_para, size - flags->width);
		}
		else
			write(1, list->s_para, size);
		if (flags->width > 0)
			list->nbr_print = list->nbr_print + (size - flags->width);
		else
			list->nbr_print = list->nbr_print + size;
		free(list->s_para);
	}
}
