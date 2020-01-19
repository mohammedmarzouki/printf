/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 13:53:43 by mmarzouk          #+#    #+#             */
/*   Updated: 2020/01/18 06:00:01 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void jingle_it(t_flag flag)
{
	if (flag.x < 0 && flag.st2 >= flag.st1)
	{
		flag.x *= -1;
		ft_charset('-',1);
		ft_charset('0',flag.st2  - (flag.y - 1));
		ft_putnbr_fd(flag.x,1);
	}
	
	else if(flag.x < 0)
	{
		breakmoint(flag);
	}
	else
		breakpoint(flag);
}

static void 				dprtndash(t_flag flag, long l)
{
	flag.x = l;
	flag.y = nbd(flag.x);
	if (flag.p && !flag.st2 && flag.x == 0)
	{
		if (flag.st1 < 0)
			flag.st1 = flag.st1 * -1;
		ft_charset(' ', flag.st1);
	}
	else if (flag.y < flag.st1)
		jingle_it(flag);
	else if (flag.y >= flag.st1)
	{
		if (flag.x < 0)
		{
			flag.x *= -1;
			flag.y += -1;
			ft_charset('-',1);	
		}
		ft_charset('0', (flag.st2- flag.y));
		ft_putnbr_fd(flag.x, 1);
	}
}
static void 		prtdash(t_flag flag,long l)
{
	if (flag.st1 < 0)
		flag.st1 = flag.st1 * -1;
	flag.x = l;
	flag.y = nbd(flag.x);
	if (flag.p && !flag.st2 && flag.x == 0)
	{
		if (flag.st1 < 0)
			flag.st1 = flag.st1 * -1;
		ft_charset(' ', flag.st1);
	}
	else if (flag.y <= flag.st2)
	{
		m_jingle_it(flag);
		// ft_charset('0', (flag.st2 - y));
		// ft_putnbr_fd(x, 1);
		// ft_charset(' ', (flag.st1 - flag.st2));
	}
	else if (flag.y > flag.st2)
	{
		if (flag.x < 0)
		{
			flag.x *= -1;
			ft_charset('-',1);	
		}
		ft_putnbr_fd(flag.x, 1);
		ft_charset(' ', (flag.st1 - flag.y));
	}
}
static void dsmd(t_flag flag, long l)
{
    if (flag.dash || flag.st1 < 0)
		prtdash(flag, l);
	else
		dprtndash(flag, l);
}

void ft_d(char *s, va_list l, char *ss)
{
	if (*s != *ss)
	{

		if (*s == 'u')
			dsmd(check_flag(s, ss, l), va_arg(l, unsigned int));
		else
			dsmd(check_flag(s, ss, l), va_arg(l, int));
	}
	else if (*s == 'u')
		ft_putnbr_fd(va_arg(l, unsigned int), 1);
	else
		ft_putall_fd(va_arg(l, int), 1);
}
