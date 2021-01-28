/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:27:24 by gpaul             #+#    #+#             */
/*   Updated: 2021/01/28 18:13:30 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char		*ft_print_hex(char *base, t_struct *list)
{
	char			*temp;
	int				i;
	int				size;

	size = size_count(list->hexa);
	if (list->hexa != 0 || list->hexa != -0)
		size--;
	i = 0;
	if (!(temp = malloc(sizeof(char) * size + 1)))
		return (0);
	if (list->hexa == 0)
	{
		temp[i++] = '0';
		list->nbr_print++;
	}
	while (list->hexa)
	{
		temp[i++] = base[list->hexa % 16];
		list->hexa /= 16;
		list->nbr_print++;
	}
	temp[i] = '\0';
	write(1, ft_rev(temp), ft_strlen(temp));
	free(temp);
	return (0);
}

int			ft_print_ptr(unsigned long int nb, char *base, t_struct *list)
{
	char	*temp;
	int		i;
	int		size;

	size = size_count(nb) - 1;
	i = 0;
	if (!(temp = malloc(sizeof(char) * size)))
		return (1);
	if (nb == 0)
		temp[i++] = '0';
	while (nb)
	{
		temp[i++] = base[nb % 16];
		nb /= 16;
	}
	temp[i] = '\0';
	temp = ft_strjoin("0x", ft_rev(temp));
	write(1, temp, ft_strlen(temp));
	list->nbr_print += ft_strlen(temp);
	free(temp);
	return (0);
}

void		ft_unsigned_print(t_struct *list)
{
	int		size;

	size = ft_strlen(list->ui_para);
	write(1, list->ui_para, size);
	list->nbr_print += size;
}

void		ft_hexa_ui(t_struct *list, char format, t_flags *flags)
{
	if (format == CONVERT[5])
	{
		if (flags->dot == 0 && flags->width <= (int)ft_strlen(list->ui_para))
			ft_unsigned_print(list);
		else
			ft_flag_ui(list, flags, (int)ft_strlen(list->ui_para));
		free(list->ui_para);
	}
	else if (format == CONVERT[2])
	{
		if (flags->dot == 0 && flags->width == 0 && flags->preci == 0)
			ft_print_ptr(list->vd_ptr, list->x_hexa, list);
		else
			free(ft_flag_ptr(list, flags));
	}
	else
	{
		if ((format == CONVERT[6] || format == CONVERT[7]) && flags->dot == 0 &&
			flags->width == 0 && flags->preci == 0)
			ft_print_hex(ft_base(list, format), list);
		else
			free(ft_flag_hexa(list, flags, format));
	}
}

void		ft_nb(t_struct *list, t_flags *flags)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(list->d_para);
	if (flags->dot == 0 && flags->width <= size)
	{
		list->nbr_print = list->nbr_print + size;
		write(1, list->d_para, size);
		free(list->d_para);
		return ;
	}
	if (flags->preci > 0 && flags->width == 0)
	{
		flags->width = flags->preci;
		flags->preci = -1;
	}
	ft_flags_nbr(list, flags, size);
	free(list->d_para);
}
