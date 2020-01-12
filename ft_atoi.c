/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 21:38:01 by mmarzouk          #+#    #+#             */
/*   Updated: 2020/01/11 21:12:33 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	condition(long resultat, int signe)
{
	if (resultat > 2147483648 && signe == -1)
		return (0);
	if (resultat > 2147483647 && signe == 1)
		return (-1);
	return (0);
}

int			ft_atoi(const char *str, va_list l)
{
	int		signe;
	int		i;
	long	resultat;

	resultat = 0;
	i = 0;
	signe = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	if (str[i] == '*')
		return(va_arg(l, int));
	while (str[i] >= '0' && str[i] <= '9')
	{
		resultat = resultat * 10 + str[i] - '0';
		i++;
		if ((resultat > 2147483647 && signe == 1)
				|| (resultat > 2147483648 && signe == -1))
			return (condition(resultat, signe));
	}
	return (resultat * signe);
}
/*int main()
{
	printf("%d",ft_atoi("213"));
	return 0;
}*/
