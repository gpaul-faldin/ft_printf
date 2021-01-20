/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:21:52 by gpaul             #+#    #+#             */
/*   Updated: 2021/01/20 21:28:25 by gpaul            ###   ########.fr       */
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
	char			*ui_para;
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
	int			dot;
	int			width;
	int			preci;
	char		type;
	int			error;
	int			index;
}				t_flags;

int				ft_printf(const char *format, ...);
void			ft_hexa_ui(t_struct *list, char format, t_flags *flags);
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
char			*ft_str_minus(t_struct *list);
void			ft_flag_str(t_struct *list, t_flags *flags, int size);
int				ft_atoi_free(char *str);
void			ft_flag_ui(t_struct *list, t_flags *flags, int size);
char			*ft_itoa_ui(unsigned int n);
void			ft_flag_hexa(t_struct *list, t_flags *flags);
char			*ft_print_hex(char *base, t_struct *list);
char			*ft_convert_hex(char *base, t_struct *list);

#endif
