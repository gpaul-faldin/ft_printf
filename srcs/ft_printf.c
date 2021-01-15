/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:21:15 by gpaul             #+#    #+#             */
/*   Updated: 2021/01/15 03:10:55 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_param(char conv, va_list param, t_struct *list)
{
	if (conv == CONVERT[0])
		list->c_para = va_arg(param, int);
	else if (conv == CONVERT[1])
	{
		list->s_para = va_arg(param, char *);
		list->s_para = ft_strdup(list->s_para);
	}
	else if (conv == CONVERT[2])
	{
		list->vd_ptr = va_arg(param, void*);
		list->vd_ptr = ft_strdup(list->vd_ptr);
	}
	else if (conv == CONVERT[3] || conv == CONVERT[4])
		list->d_para = ft_itoa(va_arg(param, int));
	else if (conv == CONVERT[6] || conv == CONVERT[7])
		list->hexa = va_arg(param, unsigned int);
	else if (conv == CONVERT[5])
		list->ui_para = va_arg(param, unsigned int);
	else if (conv == CONVERT[8])
		list->c_para = 37;
}

int		ft_print(char format, t_struct *list, t_flags *flags)
{
	if (format == CONVERT[0] || format == CONVERT[1] || format == CONVERT[8])
	{
		ft_str_c(format, list, flags);
		return (1);
	}
	else if (format == CONVERT[3] || format == CONVERT[4])
	{
		ft_nb(list, flags);
		return (1);
	}
	else if (format == CONVERT[6] || format == CONVERT[7] ||
		format == CONVERT[5] || format == CONVERT[2])
	{
		ft_hexa_ui(list, format);
		return (1);
	}
	return (0);
}

int		ft_str(const char *format, t_struct *list, va_list param)
{
	int		i;
	t_flags	flags;

	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
		{
			ft_putchar_fd(format[i], 1);
			list->nbr_print++;
		}
		else
		{
			ft_init_struct_flags(&flags);
			list->index = i;
			ft_flags(format, &flags, list, param);
			i++;
			while (ft_check_convert(format[i]) == 1)
				i++;
			ft_param(format[i], param, list);
			ft_print(format[i], list, &flags);
		}
		i++;
	}
	return (0);
}

void	ft_init_struc(t_struct *list)
{
	list->nbr_print = 0;
	list->c_para = 0;
	list->s_para = 0;
	list->d_para = 0;
	list->ui_para = 0;
	list->m_hexa = "0123456789ABCDEF";
	list->h_hexa = "0123456789abcdef";
	list->hexa = 0;
	list->vd_ptr = 0;
}

int		ft_printf(const char *format, ...)
{
	va_list			param;
	t_struct		list;

	ft_init_struc(&list);
	va_start(param, format);
	ft_str(format, &list, param);
	va_end(param);
	return (list.nbr_print);
}
