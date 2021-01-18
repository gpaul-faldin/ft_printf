/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:27:24 by gpaul             #+#    #+#             */
/*   Updated: 2021/01/18 11:26:45 by gpaul            ###   ########.fr       */
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

void		ft_unsigned_print(unsigned int n, t_struct *list)
{
	char	*re;
	int		i;
	int		size;

	i = 0;
	size = size_count(n);
	list->nbr_print = list->nbr_print + size - 1;
	if (!(re = malloc(sizeof(char) * size + 1)))
		return ;
	if (n == 0)
	{
		re[i] = '0';
		i++;
	}
	while (n > 0)
	{
		re[i++] = ((n % 10) + '0');
		n = n / 10;
	}
	re[i] = '\0';
	write(1, ft_rev(re), ft_strlen(re));
	free(re);
}

void		ft_hexa_ui(t_struct *list, char format)
{
	if (format == CONVERT[5])
		ft_unsigned_print(list->ui_para, list);
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
	//printf("size == %d\n", size);
	if (flags->dot == 0 && flags->width <= size)
	{
		list->nbr_print = list->nbr_print + size;
		write(1, list->d_para, size);
		free(list->d_para);
		return ;
	}
	ft_flags_nbr(list, flags, size);
	free(list->d_para);
}
