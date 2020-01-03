/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 13:53:43 by mmarzouk          #+#    #+#             */
/*   Updated: 2020/01/03 22:56:49 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void which(char *s , va_list l)
{
    char *ss;

    ss = ++s;
    while(s)
    {
        if (*s == 'd' || *s == 'i')
            return(ft_d(s , l , ss));
        else if (*s == 'c')
            return(ft_c(s , l , ss));
        else if (*s == 'u')
            return(ft_u(s , l , ss));
        else if (*s == 'x' || *s == 'X')
            return(ft_x(s , l , ss));
        else if (*s == 's')
            return(ft_s(s , l , ss));
        else if (*s == 'p')
            return(ft_p(s , l , ss));
        else if (*s == '%')
            return(ft_pc(s , l , ss));
        s++;
    }
}   


void all(char *s , va_list l)
{
    if (s == NULL)
    {
        g_r = -1;
        return;
    }
    while (*s != '\0')
    {
        if (*s == %)
            which(s , l);
        else
        {
            ft_putchar_fd(s , 1);
            s++;
        }
    }
}
