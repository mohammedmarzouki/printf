/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 21:41:17 by mmarzouk          #+#    #+#             */
/*   Updated: 2020/01/14 20:47:19 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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

void		ft_putnbr_fd(unsigned int n, int fd)
{

	if (n <= 9)
		ft_putchar_fd(n + 48, fd);
	else
		putnbr(n, fd);
}
static void	putnb(unsigned int n, int fd)
{
	if (n <= 9)
		ft_putchar_fd(n + 48, fd);
	else
	{
		putnb(n / 10, fd);
		putnb(n % 10, fd);
	}
}

void		ft_putall_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		putnb(n * -1, fd);
	}

	else if (n <= 9)
		ft_putchar_fd(n + 48, fd);
	else
		putnb(n, fd);
}