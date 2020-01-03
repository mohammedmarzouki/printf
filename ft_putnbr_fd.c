/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 21:41:17 by mmarzouk          #+#    #+#             */
/*   Updated: 2020/01/03 20:48:24 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	putnbr(unsigned int n, int fd)
{
	if (n <= 9)
		ft_putchar_fd(n + 48, fd);
	else
	{
		putnbr(n / 10, fd);
		putnbr(n % 10, fd);
	}
}

void		ft_putnbr_fd(int n, int fd , char c)
{
	if (n < 0 && c)//c != 0 for U conversion
	{
		ft_putchar_fd('-', fd);
		putnbr(n * -1, fd);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd(n + 48, fd);
		else
			putnbr(n, fd);
	}
}
