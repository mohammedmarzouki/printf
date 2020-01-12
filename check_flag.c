/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 13:53:43 by mmarzouk          #+#    #+#             */
/*   Updated: 2020/01/12 16:56:50 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
static int anum(char *ss)
{
    int i;
    
    i = 0;
    if(*ss == '*')
        return (1);
    else
    {
        while(ft_isdigit(*ss))
        {
            i++;
            ss++;
        }
    }
    return (i);
}
static void init(t_flag *flag)
{
    flag->dash = 0;
    flag->z = 0;
    flag->p = 0;
    flag->st1 = 0;
    flag->st2 = 0;
    flag->k = 0;
}
t_flag  *check_flag(char *s, char *ss, va_list l)
{
    t_flag *flag;

    flag = malloc(sizeof(t_flag));
    init(flag);
    if (*ss && *ss != *s)
    {
        while (*ss == '-' && ++(flag->dash))
            ss++;
        while (*ss == '0' && ++(flag->z))
            ss++;
        if (*ss == '*' || ft_isdigit(*ss))
        {
            
            flag->st1 = ft_atoi(ss,l);
            ss = ss + (anum(ss));
            
        }
        if (*ss == '.' && ++(flag->p))
            ss++;
        if (*ss == '*' || ft_isdigit(*ss) || *ss == '-')
        {
            flag->st2 = ft_atoi(ss,l);
            ss++;  
        }
    }
    return (flag);
}