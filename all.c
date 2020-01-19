/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 13:53:43 by mmarzouk          #+#    #+#             */
/*   Updated: 2020/01/19 05:55:26 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void which(char *s , va_list l, int *i)
{
    char *ss;
    int b;

    ss = ++s;
    *i = 0;
    while(!ft_strrchr("xXidpu%cs",s[(*i)++]))
        b = 0;
    while(*s)
    {
        if (*s == 'd' || *s == 'i')
            return(ft_d(s , l , ss));
        /*else if (*s == 'c')
            return(ft_c(s , l , ss));*/
        else if (*s == 'u')
            return(ft_d(s , l , ss));
         if (*s == 'x' || *s == 'X')
            return(ft_x(s, l , ss));
        else if (*s == 's')
            return(ft_s(s , l , ss));
        else if (*s == 'p')
            return(ft_p(s , l , ss));
        /*else if (*s == '%')
            return(ft_pc(s , l , ss));*/
        s++; 
    }
}   


void all(char *s , va_list l)
{
    int i;

    i = 0;
    while (*s != '\0')
    {
        if (*s == '%')
        {
            which(s , l, &i);
            s = s + i + 1;
        }
        else
        {
            ft_putchar_fd(*s , 1);
            s++;
        }
    }
}
