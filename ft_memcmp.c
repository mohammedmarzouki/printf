/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 21:48:22 by mmarzouk          #+#    #+#             */
/*   Updated: 2020/01/03 17:46:12 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int	ft_memcmp(const void *buf1, const void *buf2, size_t count)
{
	unsigned char	*pbuf1;
	unsigned char	*pbuf2;
	size_t			i;

	i = 0;
	pbuf1 = (unsigned char*)buf1;
	pbuf2 = (unsigned char*)buf2;
	while (i < count)
	{
		if (pbuf1[i] != pbuf2[i])
			return (pbuf1[i] - pbuf2[i]);
		i++;
	}
	return (0);
}
