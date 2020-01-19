/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itox.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 13:53:43 by mmarzouk          #+#    #+#             */
/*   Updated: 2020/01/14 17:51:15 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void itox(unsigned int x, char c)
{
    int d;
    
    d = x % 16;
    x = x / 16;
    if(x > 0)
        itox(x , c); 
    if (d <= 9)
        ft_putchar_fd(d + 48 , 1);
    else if (d > 9 && c == 'x')
        ft_putchar_fd((d + 87) , 1);//c = x for lowercase
    else
    {
        ft_putchar_fd((d + 55) , 1);//c != x for uppercase
    }
    return;
}