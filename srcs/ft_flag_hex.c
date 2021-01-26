/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 19:22:55 by gpaul             #+#    #+#             */
/*   Updated: 2021/01/26 01:27:24 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void		ft_para_zero(t_flags *flags, t_struct *list)
{
	while (flags->width)
	{
		if (flags->zero == 0)
			write(1, " ", 1);
		flags->width = flags->width - 1;
		list->nbr_print = list->nbr_print + 1;
	}
}

static void		ft_width_preci(t_struct *list, t_flags *flags,
	int size, char *cpy)
{
	int	temp;

	temp = flags->width - flags->preci;
	while (temp != 0 && flags->width > size && flags->minus == 0 && temp-- &&
	++list->nbr_print && flags->width--)
		write(1, " ", 1);
	while (flags->width - temp > size && ++list->nbr_print)
	{
		if (flags->dot == 1 || flags->zero == 1)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		flags->width--;
	}
	write(1, cpy, size);
	while (flags->width-- > size && flags->minus == 1 && ++list->nbr_print)
		write(1, " ", 1);
	list->nbr_print = list->nbr_print + size;
}

static int		ft_flags_hexa_2(t_struct *list, t_flags *flags, int size)
{
	if (flags->width != 0 && flags->minus == 0)
	{
		while (flags->width > size)
		{
			if (flags->zero == 1)
				write(1, "0", 1);
			else
				write(1, " ", 1);
			flags->width--;
			list->nbr_print++;
		}
	}
	else
	{
		while (flags->preci > size)
		{
			if (flags->dot == 1 || flags->zero == 1)
				write(1, "0", 1);
			else
				write(1, " ", 1);
			flags->preci--;
			list->nbr_print++;
		}
	}
	return (size);
}

char			*ft_flag_hexa(t_struct *list, t_flags *flags)
{
	char	*cpy;
	int		size;

	if (flags->type == 'x')
		cpy = ft_convert_hex(list->h_hexa, list);
	else
		cpy = ft_convert_hex(list->m_hexa, list);
	size = ft_strlen(cpy);
	if ((size == 1 && cpy[0] == '0' && flags->dot == 1 &&
	flags->preci == 0) || (flags->preci > 0 && flags->width > 0))
	{
		if (flags->preci != 0 && flags->width != 0)
			ft_width_preci(list, flags, size, cpy);
		else
			ft_para_zero(flags, list);
		return (cpy);
	}
	if (flags->minus == 0 || flags->dot == 1)
		size = ft_flags_hexa_2(list, flags, size);
	write(1, cpy, size);
	if (flags->minus == 1)
		while (flags->width-- > size && ++list->nbr_print)
			write(1, " ", 1);
	list->nbr_print = list->nbr_print + size;
	return (cpy);
}
