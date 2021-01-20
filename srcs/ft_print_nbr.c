/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:27:24 by gpaul             #+#    #+#             */
/*   Updated: 2021/01/20 18:22:44 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int			ft_print_hex(unsigned int nb, char *base, t_struct *list)
{
	char	*temp;
	int		i;
	int		size;

	size = size_count(nb) - 1;
	i = 0;
	list->nbr_print = list->nbr_print + size - 1;
	if (!(temp = malloc(sizeof(char) * size)))
		return (1);
	while (nb)
	{
		temp[i++] = base[nb % 16];
		nb /= 16;
	}
	temp[i] = '\0';
	write(1, ft_rev(temp), ft_strlen(temp));
	free(temp);
	return (0);
}

int			ft_print_ptr(long long int nb, char *base, t_struct *list)
{
	char	*temp;
	int		i;
	int		size;

	size = size_ptr(nb) - 1;
	i = 0;
	list->nbr_print = list->nbr_print + size - 1;
	if (!(temp = malloc(sizeof(char) * size)))
		return (1);
	while (nb)
	{
		temp[i++] = base[nb % 16];
		nb /= 16;
	}
	temp[i] = '\0';
	write(1, "0x", 2);
	write(1, ft_rev(temp), ft_strlen(temp));
	free(temp);
	free(list->vd_ptr);
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
		ft_print_ptr((long long int)list->vd_ptr, list->h_hexa, list);
	else if (format == CONVERT[6])
		ft_print_hex(list->hexa, list->h_hexa, list);
	else
		ft_print_hex(list->hexa, list->m_hexa, list);
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
