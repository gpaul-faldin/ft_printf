/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:21:52 by gpaul             #+#    #+#             */
/*   Updated: 2021/01/12 19:42:34 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define CONVERT "cspdiuxX%"
# include "../libft/libft.h"

# include <stdarg.h>
# include <stdio.h>

typedef	struct	s_struct
{
	int				nbr_print;
	int				c_para;
	char			*s_para;
	unsigned int	ui_para;
	int				d_para;
	char			*m_hexa;
	char			*h_hexa;
	unsigned int	hexa;
	void			*vd_ptr;
}				t_struct;

int				ft_printf(const char *format, ...);
void			ft_hexa_ui(t_struct *list, char format);
void			ft_nb(t_struct *list);
char			*ft_rev(char *re);
void			ft_str_c(char format, t_struct *list);
int				size_count(unsigned int n);
int				ft_check_convert(char c);
int				size_ptr(long long int n);

#endif
