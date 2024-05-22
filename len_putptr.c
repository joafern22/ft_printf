/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_putptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafern2 <joafern2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:43:54 by joafern2          #+#    #+#             */
/*   Updated: 2024/05/22 20:35:34 by joafern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_hexa(unsigned long long nbr, char *base)
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

int	write_ptr(unsigned long long ptr)
{
	char	*base;
	int		len;

	len = 0;
	base = "0123456789abcdef";
	if (ptr == 0)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	else if (ptr > 0)
		len += write_hexa(ptr, base);
	return (len);
}

int	len_putptr(void *ptr)
{
	if (ptr)
		return (len_putstr("0x") + write_ptr((unsigned long long)ptr));
	else
		return (write_ptr((unsigned long long)ptr));
}
/*
#include <stdio.h>

int main() {
    void *ptr = (void*)(NULL);
    int len = len_ptr(ptr);
    printf("\nLength: %d\n", len);
    return 0;
}*/
