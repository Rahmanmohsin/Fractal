/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:38:31 by mohrahma          #+#    #+#             */
/*   Updated: 2024/03/26 14:12:24 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

size_t		ft_strlen(const char *s);
int			ft_printfs(char *s, int *p_count);
int			ft_printfspec(int *p_count);
int			ft_printfc(unsigned char c, int *p_count);
int			ft_printfd(int i, int *p_count);
int			ft_printfp(unsigned long n, int *p_count);
int			ft_printx(unsigned int n, int *p_count);
int			ft_printfxcap(unsigned int n, int *p_count);
int			ft_printfu(unsigned int i, int *p_count);
char		*ft_memcalc_x(unsigned int n);
char		*ft_setp(unsigned long n);
char		*ft_strdup(const char *s1);
char		*ft_itoa(int n);
char		*ft_itoa_u(unsigned int n);
char		*ft_memcalc_xcap(unsigned int n);
int			ft_memcalc_d(int n);
int			analysise_str(char c, va_list arg_list, int *p_count);
int			ft_printf(const char *input, ...);
int			ft_memcalc_p(int memspace, unsigned long n);

#endif