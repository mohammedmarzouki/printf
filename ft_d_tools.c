/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 21:38:01 by mmarzouk          #+#    #+#             */
/*   Updated: 2020/01/18 06:01:40 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void breakmoint(t_flag flag)//st1>st2 && x<0 flag->z
{
	if ((flag.z && flag.st2 < 0 )|| !flag.p)//05.;5,-5,-15;05
	{
		flag.x *= -1;
		ft_charset('-',1);
		ft_charset('0',flag.st1 - flag.y);
		ft_putnbr_fd(flag.x,1);
	}
	else
	{
		if (flag.st2 > (flag.y - 1))
			ft_charset(' ', (flag.st1 - (flag.st2 - (flag.y - 1) + flag.y)));
		else
			ft_charset(' ',flag.st1 - flag.y);
		flag.x *= -1;
		ft_charset('-',1);
		ft_charset('0',flag.st2 - (flag.y - 1));
		ft_putnbr_fd(flag.x,1);
	}
}

int     nbd(long x)
{
	int a;

	a = 0;
    if (x < 0)
        a = 1;
	if (x == 0)
		return (1);
	while (x != 0)
	{
		x = x / 10;
		a++;
	}
	return (a);
}
int 	comp(int x1,int x2)
{
	if (x1 > x2)
		return (x1);
	else
		return (x2);
}
void m_jingle_it(t_flag flag)
{
		if (flag.x < 0 && flag.st2 > flag.st1)
	{
		flag.x *= -1;
		ft_charset('-',1);
		ft_charset('0',flag.st2 - (flag.y - 1));
		ft_putnbr_fd(flag.x,1);
	}
	else if(flag.x < 0)
	{
		flag.x *= -1;
		
		ft_charset('-',1);
		ft_charset('0', (flag.st2 - (flag.y - 1)));
		ft_putnbr_fd(flag.x,1);
		ft_charset(' ', (flag.st1 - (flag.st2 + (flag.y + 1)) + flag.y));
	}
	else//-5.5
	{
		ft_charset('0', (flag.st2 - flag.y));
		ft_putnbr_fd(flag.x, 1);
		ft_charset(' ', (flag.st1 - comp(flag.st2, flag.y)));
	}
}
void breakpoint(t_flag flag)
{
    if(!flag.z || (flag.p && flag.st2 >= 0))//04.3,5.0
    {
        ft_charset(' ', (flag.st1 - comp(flag.y, flag.st2)));
		ft_charset('0',flag.st2 - (flag.y));
		ft_putnbr_fd(flag.x, 1);
    }
    else//%06
    {
		ft_charset('0',comp(flag.st1,flag.st2) - flag.y);
		ft_putnbr_fd(flag.x, 1);
    }
    
}