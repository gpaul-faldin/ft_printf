/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 23:44:05 by gpaul             #+#    #+#             */
/*   Updated: 2021/01/25 19:32:48 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_init_struct_flags(t_flags *flags)
{
	flags->zero = 0;
	flags->minus = 0;
	flags->dot = 0;
	flags->width = 0;
	flags->preci = 0;
	flags->type = 0;
	flags->error = 0;
	flags->index = 0;
}

int		ft_check_error(t_flags *flags)
{
	if (flags->width < 0)
	{
		if (flags->minus == 0)
			flags->minus = 1;
		flags->width = -flags->width;
	}
	if (flags->dot == 1 && flags->type == 'c')
		flags->dot = 0;
	return (1);
}

int		ft_dot(const char *format, t_flags *flags,
	int index, va_list param)
{
	int		n;

	n = 0;
	if (format[index] == '*')
		flags->preci = va_arg(param, int);
	else
		flags->preci = ft_atoi_free(ft_strdup_flags((char*)format, index));
	while (ft_check_convert(format[index + n + 1]) == 1)
		n++;
	return (n);
}

int		ft_width(const char *format, t_flags *flags, int i, int n)
{
	while (format[i + n + flags->index] >= '0' &&
		format[i + n + flags->index] <= '9')
		flags->index++;
	flags->width = ft_atoi_free(ft_strdup_flags((char*)format, i + n));
	return (flags->index - 1);
}

void	ft_flags(const char *format, t_flags *flags,
	t_struct *list, va_list param)
{
	int		n;
	int		i;

	i = list->index;
	n = 1;
	while (ft_check_convert(format[i + n]) == 1 && format[i + n])
	{
		
		if (format[i + n] == '0')
			flags->zero = 1;
		else if (format[i + n] == '-')
			flags->minus = 1;
		else if (format[i + n] == '.' && ++flags->dot && n++)
			n += ft_dot(format, flags, i + n, param);
		else if (format[i + n] >= '0' && format[i + n] <= '9')
			n += ft_width(format, flags, i, n);
		else if (format[i + n] == '*')
			flags->width = va_arg(param, int);
		n++;
	}
	flags->type = format[i + n];
	ft_check_error(flags);
}
