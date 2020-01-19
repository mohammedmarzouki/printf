/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 13:53:43 by mmarzouk          #+#    #+#             */
/*   Updated: 2020/01/19 05:41:37 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void 				hprtndash(t_flag flag, va_list l)
{
	flag.h = va_arg(l, int);
	flag.y = nb(flag.h);
	if (flag.p && !flag.st2 && flag.h == 0)
	{
		if (flag.st1 < 0)
			flag.st1 = flag.st1 * -1;
		ft_charset(' ', flag.st1 - 2);
        ft_putstr_fd("0x", 1, 2);
	}
		else if (flag.y < flag.st1 && flag.z)
	{
		if (flag.st2 < 0)
			flag.st2 = flag.st1;
		flag.k = comp(flag.y, flag.st2);
		ft_charset(' ', (flag.st1 - flag.k - 2));
        ft_putstr_fd("0x", 1, 2);
		ft_charset('0', (flag.st2 - flag.y));
		itop(flag.h);
	}
	else if (flag.y < flag.st1)
	{
		flag.k = comp(flag.y, flag.st2);
		ft_charset(' ', (flag.st1 - flag.k - 2));
        ft_putstr_fd("0x", 1, 2);
		ft_charset('0', (flag.st2 - flag.y));
		itop(flag.h);
	}
	else if (flag.y >= flag.st1)
	{
		ft_charset('0', (flag.st2 - flag.y));
        ft_putstr_fd("0x", 1, 2);
		itop(flag.h);
	}
}
int 				nbp(unsigned long long h)
{
	unsigned long long a;

	a = 0;
	if (h == 0)
		return (1);
	while (h != 0)
	{
		h = h / 16;
		a++;
	}
	return (a);
}
static void 		hprtdash(t_flag flag, va_list l)
{
	unsigned long long h;
	long long y;

	if (flag.st1 < 0)
		flag.st1 = flag.st1 * -1;
	h = va_arg(l, int);
	y = nb(h);
	if (flag.p && !flag.st2 && h == 0)
	{
		if (flag.st1 < 0)
			flag.st1 = flag.st1 * -1;
        ft_putstr_fd("0x", 1, 2);
		ft_charset(' ', flag.st1 - 2);
	}
	else if (y < flag.st2)
	{
        ft_putstr_fd("0x", 1 ,2);
		ft_charset('0', (flag.st2 - y));
		itop(h);
		ft_charset(' ', (flag.st1 - flag.st2 - 2));
	}
	else if (y >= flag.st2)
	{
        ft_putstr_fd("0x", 1, 2);
		itop(h);
		ft_charset(' ', (flag.st1 - y - 2));
	}
}
static void 		dsmp(t_flag flag, va_list l)
{

	if (flag.dash || flag.st1 < 0)
		hprtdash(flag, l);
	else
		hprtndash(flag, l);
}
void ft_p(char *s,va_list l , char *ss)
{
    if (*s != *ss)
    {
        dsmp(check_flag(s, ss, l), l);
    }
    else
    {
        ft_putstr_fd("0x", 1, 2);
        itop(va_arg(l,unsigned long long));
    }
}