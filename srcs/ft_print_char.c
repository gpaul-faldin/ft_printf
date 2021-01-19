/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:27:20 by gpaul             #+#    #+#             */
/*   Updated: 2021/01/19 19:44:59 by gpaul            ###   ########.fr       */
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
		size = ft_strlen(list->s_para);
		if ((flags->width == 0 && flags->dot == 0 && flags->minus == 0))
		{
			if (list->s_para != NULL)
			{
				write(1, list->s_para, size);
				list->nbr_print += size;
			}
		}
		else
			ft_flag_str(list, flags, size);
		free(list->s_para);
	}
}
