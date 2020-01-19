/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 11:18:37 by mmarzouk          #+#    #+#             */
/*   Updated: 2020/01/19 07:44:03 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int main()
{

    //int st1 = -9;
    int st2 = -5;
    char *d = "abc";
     printf("%d\n",(printf("|%.*s|\n",st2,d))-3);
     printf("%d\n",(ft_printf("|%.*s|\n",st2,d))-3);
    return (0);
}
