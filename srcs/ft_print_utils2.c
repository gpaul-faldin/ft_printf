/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 21:00:00 by gpaul             #+#    #+#             */
/*   Updated: 2021/01/28 18:14:32 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char		*ft_str_minus(t_struct *list)
{
	int		size;
	char	*s2;
	int		i;

	i = 0;
	size = ft_strlen(list->d_para) - 1;
	if (!(s2 = malloc(sizeof(char) * (size + 1))))
		return (0);
	while (list->d_para[1 + i])
	{
		s2[i] = list->d_para[1 + i];
		i++;
	}
	s2[i] = '\0';
	free(list->d_para);
	return (s2);
}

int			ft_atoi_free(char *str)
{
	int	i;
	int	sign;
	int	re;

	re = 0;
	i = 0;
	sign = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		re = re * 10 + (str[i] - '0');
		i++;
	}
	free(str);
	if (sign == 1)
		return (-re);
	else
		return (re);
}

char		*ft_convert_hex(char *base, t_struct *list)
{
	char			*temp;
	int				i;
	int				size;

	size = size_count(list->hexa) - 1;
	i = 0;
	if (!(temp = malloc(sizeof(char) * size + 1)))
		return (0);
	if (list->hexa == 0)
		temp[i++] = '0';
	while (list->hexa)
	{
		temp[i++] = base[list->hexa % 16];
		list->hexa /= 16;
	}
	temp[i] = '\0';
	return (ft_rev(temp));
}

char		*ft_convert_ptr(unsigned long int nb, t_struct *list, t_flags *flags)
{
	char	*temp;
	int		i;
	int		size;

	size = size_count(nb) - 1;
	i = 0;
	if (!(temp = malloc(sizeof(char) * size)))
		return (0);
	if (nb == 0 && (flags->preci != 0 ||
		(flags->width != 0 && flags->dot == 0)))
		temp[i++] = '0';
	while (nb)
	{
		temp[i++] = list->x_hexa[nb % 16];
		nb /= 16;
	}
	temp[i] = '\0';
	return (ft_rev(temp));
}

char		*ft_base(t_struct *list, char format)
{
	if (format == CONVERT[6])
		return (list->x_hexa);
	else
		return (list->X_hexa);
}
