/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:27:20 by gpaul             #+#    #+#             */
/*   Updated: 2021/01/18 19:45:38 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_str_c(char format, t_struct *list, t_flags *flags)
{
	int size;

	size = 0;
	if (format == CONVERT[0] || format == CONVERT[8])
	{
		ft_putchar_fd(list->c_para, 1);
		list->nbr_print = list->nbr_print + 1;
	}
	else
	{
		size = ft_strlen(list->s_para);
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
