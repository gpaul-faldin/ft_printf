/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:27:20 by gpaul             #+#    #+#             */
/*   Updated: 2021/01/14 23:40:48 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_str_c(char format, t_struct *list)
{
	if (format == CONVERT[0] || format == CONVERT[8])
	{
		ft_putchar_fd(list->c_para, 1);
		list->nbr_print = list->nbr_print + 1;
	}
	else
	{
		write(1, list->s_para, ft_strlen(list->s_para));
		list->nbr_print = list->nbr_print + ft_strlen(list->s_para);
		free(list->s_para);
	}
}
