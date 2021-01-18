/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 21:00:00 by gpaul             #+#    #+#             */
/*   Updated: 2021/01/18 21:00:58 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_str_minus(t_struct *list)
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
