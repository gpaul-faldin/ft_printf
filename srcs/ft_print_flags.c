/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 23:44:05 by gpaul             #+#    #+#             */
/*   Updated: 2021/01/15 02:32:37 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_init_struct_flags(t_flags *flags)
{
	flags->zero = 0;
	flags->minus = 0;
	flags->star = 0;
	flags->dot = 0;
	flags->width = 0;
	flags->type = 0;
	flags->error = 0;
}

void	ft_check_error(t_flags *flags)
{
	if (flags->minus == 1 && flags->zero == 1)
		flags->error = 1;
	else if (flags->dot == 1 && flags->zero == 1)
	{
		if (flags->type == 'i' || flags->type == 'd' || flags->type == 'u' ||
			flags->type == 'x' || flags->type == 'X')
		{
			flags->zero = 0;
		}
	}
	else if (flags->dot == 1 && flags->type == 'c')
		flags->dot = 0;
}

void	ft_flags(const char *format, t_flags *flags, t_struct *list, va_list param)
{
	int		n;
	int		i;

	i = list->index;
	n = 1;
	while (ft_check_convert(format[i + n]) == 1)
	{
		if (format[i + n] == '0')
			flags->zero = 1;
		else if (format[i + n] == '-')
			flags->minus = 1;
		else if (format[i + n] == '.')
		{
			flags->dot = 1;
			n++;
			if (format[i + n] == '*')
				flags->width = va_arg(param, int);
			else
				flags->width = ft_atoi(ft_strdup_flags((char*)format, i + n));
			while (ft_check_convert(format[i + n]) == 1)
				n++;
			n--;
		}
		else if (format[i + n] == '*')
		{
			flags->width = va_arg(param, int);
			flags->star = 1;
		}
		n++;
	}
	if (n != 0)
	{
		flags->type = format[i + n];
		ft_check_error(flags);
	}
}
