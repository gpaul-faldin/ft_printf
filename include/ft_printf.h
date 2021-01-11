/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:21:52 by gpaul             #+#    #+#             */
/*   Updated: 2021/01/11 16:23:39 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H
# define FT_PRINT_H
# define CONVERT "cspdiuxX%"

# include "../libft/libft.h"
# include <stdarg.h>

#include <stdio.h>

typedef	struct	str_list
{
	int			nbr_print;
	int			c_para;
	char		*s_para;

}				st_list;

int		ft_printf(const char *format, ...);

#endif
