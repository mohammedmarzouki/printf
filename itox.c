/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itox.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 13:53:43 by mmarzouk          #+#    #+#             */
/*   Updated: 2020/01/03 20:44:26 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void itox(long long x, char c)
{
    int d; 
    d = x % 16;
    x = x / 16;
    if(x != 0)
        itox(x , c); 
    if (d <= 9)
        ft_putchar_fd(d + 48 , 1);
    else if (d > 9 && !c)
        ft_putchar_fd(d + 87 , 1);//c = 0 for lowercase
    else
    {
        ft_putchar_fd(d + 55 , 1);//c != 0 for uppercase
    }
    return;
}