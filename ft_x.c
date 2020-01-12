/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 13:53:43 by mmarzouk          #+#    #+#             */
/*   Updated: 2020/01/12 18:01:47 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 				comp(int x1,int x2)
{
	if (x1 > x2)
		return (x1);
	else
		return (x2);
}
void 				prtndash(t_flag *flag, va_list l, char *ss)
{
	flag->x = va_arg(l, int);
	flag->y = nb(flag->x);
	if (flag->p && !flag->st2 && flag->x == 0)
	{
		if (flag->st1 < 0)
			flag->st1 = flag->st1 * -1;
		ft_charset(' ', flag->st1);
	}
	else if (flag->y < flag->st1)
	{
		flag->k = comp(flag->y, flag->st2);
		ft_charset(' ', (flag->st1 - flag->k));
		ft_charset('0', (flag->st2 - flag->y));
		itox(flag->x,*ss);
	}
	else if (flag->y >= flag->st1)
	{
		ft_charset(' ', (flag->st1 - flag->y));
		itox(flag->x, *ss);
	}
}
int 				nb(unsigned int x)
{
	int a;

	a = 0;
	if (x == 0)
		return (1);
	while (x != 0)
	{
		x = x / 16;
		a++;
	}
	return (a);
}
static void 		prtdash(t_flag *flag, va_list l, char *ss)
{
	int x;
	int y;

	if (flag->st1 < 0)
		flag->st1 = flag->st1 * -1;
	x = va_arg(l, int);
	y = nb(x);
	if (flag->p && !flag->st2 && x == 0)
	{
		if (flag->st1 < 0)
			flag->st1 = flag->st1 * -1;
		ft_charset(' ', flag->st1);
	}
	else if (y < flag->st2)
	{
		ft_charset('0', (flag->st2 - y));
		itox(x,*ss);
		ft_charset(' ', (flag->st1 - flag->st2));
	}
	else if (y >= flag->st2)
	{
		itox(x, *ss);
		ft_charset(' ', (flag->st1 - y));
	}
}
static void 		dsmx(char *ss, t_flag *flag, va_list l)
{

	if (flag->dash || flag->st1 < 0)
		prtdash(flag, l, ss);
	else
		prtndash(flag, l, ss);
}

void				ft_x(char *s,va_list l , char *ss)
{

	if (*s != *ss)
	{
		dsmx(s, check_flag(s, ss, l), l);
	}
	else
		itox(va_arg(l, int), *ss);
}