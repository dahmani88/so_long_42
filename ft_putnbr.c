/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdahman <abdahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:51:24 by abdahman          #+#    #+#             */
/*   Updated: 2025/04/09 09:56:06 by abdahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
	return ;
}

void	ft_putnbr(int n)
{
	long	l;

	l = n;
	if (l < 0)
	{
		ft_putchar('-');
		l = -l;
	}
	if (l > 9)
		ft_putnbr((l / 10));
	ft_putchar(((l % 10) + 48));
}
