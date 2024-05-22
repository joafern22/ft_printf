/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_putnbr_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafern2 <joafern2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:43:12 by joafern2          #+#    #+#             */
/*   Updated: 2024/05/22 20:51:44 by joafern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_hexa(unsigned int nbr, char *base)
{
	int	len;

	len = 0;
	if (nbr >= 16)
	{
		len = write_hexa(nbr / 16, base);
		write (1, &base[nbr % 16], 1);
	}
	else if (nbr < 16)
		write (1, &base[nbr], 1);
	len++;
	return (len);
}

int	len_putnbr_hexa(unsigned int nbr, char format)
{
	char			*base;
	int				len;

	len = 0;
	base = "0123456789abcdef";
	if (format == 'X')
		base = "0123456789ABCDEF";
	if (nbr == 0)
	{
		write (1, &base[0], 1);
		return (1);
	}
	else if (nbr > 0)
		len += write_hexa(nbr, base);
	return (len);
}
/*
int main()
{
    printf("\n%d\n", len_putnbr_hexa(-1, 'x'));
}*/
