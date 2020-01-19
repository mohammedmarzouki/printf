/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 13:53:43 by mmarzouk          #+#    #+#             */
/*   Updated: 2020/01/19 07:45:35 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

    void 				ndash(t_flag flag, va_list l)
{
	char *x;

	x = va_arg(l, char *);
	if (x == NULL)
		x = "(null)";
	flag.y = ft_strlen(x);
	if (flag.y < flag.st2)
	{
		ft_charset(' ', (flag.st1 - flag.y));
		ft_putstr_fd(x, 1, flag.y);
	}
	else if (flag.y >= flag.st2 && flag.p && flag.st2 >= 0)
	{
		ft_charset(' ', (flag.st1 - flag.st2));
		ft_putstr_fd(x, 1, flag.st2);
	}
	else
	{
		ft_charset(' ', (flag.st1 - flag.y));
		ft_putstr_fd(x, 1, flag.y);		
	}
	
}

static void 		prtdash(t_flag flag, va_list l)
{
	char *x;

	if (flag.st1 < 0)
		flag.st1 = flag.st1 * -1;
	x = va_arg(l, char *);
	if (!x)
		x = "(null)";
	flag.y = ft_strlen(x);
	if (flag.y < flag.st2)
	{
		ft_putstr_fd(x, 1, flag.y);
		ft_charset(' ', (flag.st1 - flag.y));
	}
	else if (flag.y >= flag.st2 && flag.p && flag.st2 >= 0)
	{
		ft_putstr_fd(x, 1, flag.st2);
		ft_charset(' ', (flag.st1 - flag.st2));
	}
	else
	{
		ft_putstr_fd(x, 1, flag.y);
		ft_charset(' ', (flag.st1 - flag.y));
	}
}
static void 		dsms(t_flag flag, va_list l)
{

	if (flag.dash || flag.st1 < 0)
		prtdash(flag, l);
	else
		ndash(flag, l);
}

void ft_s(char *s,va_list l , char *ss)
{

	if (*s != *ss)
		dsms(check_flag(s, ss, l), l);
	else
	{
        s = (va_arg(l,char *));
        if (!s)
            ft_putstr_fd("(null)",1 ,6);
        else
            ft_putstr_fd(s, 1,ft_strlen(s));
    }
}