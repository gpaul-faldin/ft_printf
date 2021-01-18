/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:21:52 by gpaul             #+#    #+#             */
/*   Updated: 2021/01/18 10:21:38 by gpaul            ###   ########.fr       */
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
	int				index;
	int				nbr_print;
	int				c_para;
	char			*s_para;
	unsigned int	ui_para;
	char			*d_para;
	char			*m_hexa;
	char			*h_hexa;
	unsigned int	hexa;
	void			*vd_ptr;
}				t_struct;

typedef	struct	s_flags
{
	int			zero;
	int			minus;
	int			star;
	int			dot;
	int			width;
	int			preci;
	char		type;
	int			error;
}				t_flags;

int				ft_printf(const char *format, ...);
void			ft_hexa_ui(t_struct *list, char format);
void			ft_nb(t_struct *list, t_flags *flags);
char			*ft_rev(char *re);
void			ft_str_c(char format, t_struct *list, t_flags *flags);
int				size_count(unsigned int n);
int				ft_check_convert(char c);
int				size_ptr(long long int n);
void			ft_flags(const char *format, t_flags *flags, t_struct *list, va_list param);
char			*ft_strdup_flags(char *s1, int index);
void			ft_init_struct_flags(t_flags *flags);
void			ft_flags_nbr(t_struct *list, t_flags *flags, int size);

#endif
