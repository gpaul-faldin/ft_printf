/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 17:54:46 by gpaul             #+#    #+#             */
/*   Updated: 2021/01/08 11:50:44 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*str;
	char				*re;
	unsigned int		i;

	i = 0;
	str = (char*)s;
	if (!s)
		return (NULL);
	if (!(re = malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (NULL);
	while (s[i])
	{
		re[i] = f(i, str[i]);
		i++;
	}
	re[i] = '\0';
	return (re);
}
