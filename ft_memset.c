/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 21:35:22 by mmarzouk          #+#    #+#             */
/*   Updated: 2020/01/03 18:22:24 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memset(void *buf, int x, size_t count)
{
	char *s;

	s = (char*)buf;
	while (count > 0)
	{
		*s = x;
		s++;
		count--;
	}
	return (buf);
}
