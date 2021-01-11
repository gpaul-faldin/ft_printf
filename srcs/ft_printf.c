/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:21:15 by gpaul             #+#    #+#             */
/*   Updated: 2021/01/11 17:47:44 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"


void	ft_param(char conv, va_list param, st_list *list)
{
	if (conv == CONVERT[0])
		list->c_para = va_arg(param, int);
	else if (conv == CONVERT[1])
	{
		list->s_para = va_arg(param, char *);
		list->s_para = ft_strdup (list->s_para);
	}
	else if (conv == CONVERT[3] || conv == CONVERT[4])
		list->d_para = va_arg(param, int);
}

void	ft_str_c(char format, st_list *list ,va_list param)
{
	if (format == CONVERT[0])
	{
		ft_putchar_fd(list->c_para, 1);
		list->nbr_print = list->nbr_print + 1;
	}
	else
	{
		write(1, list->s_para, ft_strlen(list->s_para));
		list->nbr_print = list->nbr_print + ft_strlen(list->s_para);
		free (list->s_para);
	}
	
}

void	ft_nb(char format, st_list *list ,va_list param)
{
	int i;
	
	i = 0;
	while (list->d_para != 0)
	{
		list->d_para /= 10;
		list->nbr_print = list->nbr_print + 1;
	}
	ft_putnbr_fd(list->d_para, 1);
}

int		ft_print(char format, st_list *list, va_list param)
{
	if (format == CONVERT[0] || format == CONVERT[1])
		ft_str_c(format, list ,param);
	else if (format == CONVERT[3] || format == CONVERT[4])
		ft_nb(format, list, param);
	return (0);
}

int		ft_str(const char *format, st_list *list, va_list param)
{
	int i;

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
			ft_param(format[i + 1], param, list);
			ft_print(format[i + 1], list, param);
			i++;
		}
		i++;
	}
	return (0);
}

void	ft_init_struc(st_list *list)
{
	list->nbr_print = 0;
	list->c_para = 0;
	list->s_para = 0;
	list->d_para = 0;
	list->ui_para = 0;
}

int		ft_printf(const char *format, ...)
{
	va_list		param;
	st_list		list;

	ft_init_struc(&list);
	va_start(param, format);
	ft_str(format, &list, param);
	va_end(param);
	
	return (list.nbr_print);
}
