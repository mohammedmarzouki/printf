/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 21:33:23 by mmarzouk          #+#    #+#             */
/*   Updated: 2020/01/03 17:46:16 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
void	*ft_memcpy(void *to, const void *from, size_t n)
{
	unsigned int	i;
	char			*pto;
	const char		*pfrom;

	i = 0;
	pto = (char *)to;
	pfrom = (char *)from;
	if (pto == 0 && pfrom == 0)
		return (0);
	while (i < n)
	{
		pto[i] = pfrom[i];
		i++;
	}
	return (to);
}
