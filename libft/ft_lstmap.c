/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 18:25:42 by gpaul             #+#    #+#             */
/*   Updated: 2021/01/06 15:25:35 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void*))
{
	t_list	*re;

	if (lst)
	{
		if ((re = ft_lstnew(f(lst->content))) == NULL)
			return (NULL);
		re->next = ft_lstmap(lst->next, f, del);
		return (re);
	}
	return (NULL);
}
