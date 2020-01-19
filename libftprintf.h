/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 17:02:34 by mmarzouk          #+#    #+#             */
/*   Updated: 2020/01/19 05:54:43 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>

int g_r;

typedef struct s_flag
{
	long x;
	long long y;
	int dash;
	int z;
	int p;
	int st1;
	int st2;
	int k;
	unsigned long long h;
}			t_flag;

int					ft_isdigit(int a);
int 				ft_printf(const char *s, ...);
void				all(char *s,va_list l);
void				itox(unsigned int x, char c);
void				ft_putnbr_fd(unsigned int n, int fd);
t_flag				check_flag(char *s , char *ss , va_list l);
void				ft_charset(int x, int count);
t_flag				stars(char *ss,va_list l, t_flag flag);
int					ft_atoi(const char *str, va_list l);
void				ft_putchar_fd(char c, int fd);
int 				nb(unsigned int x);
void        		ft_x(char *s,va_list l , char *ss);
char				*ft_strrchr(const char *str, int c);
void 				ft_d(char *s, va_list l, char *ss);
int 				comp(int x1,int x2);
int     			nbd(long x);
void 				m_jingle_it(t_flag flag);
void 				breakpoint(t_flag flag);
void				ft_putall_fd(int n, int fd);
void 				breakmoint(t_flag flag);
void 				ft_p(char *s,va_list l , char *ss);
void				ft_putstr_fd(char *s, int fd, int n);
void 				itop(unsigned long long x);
size_t				ft_strlen(const char *str);
void 				ft_s(char *s,va_list l , char *ss);
#endif
