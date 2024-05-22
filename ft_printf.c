/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafern2 <joafern2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:47:42 by joafern2          #+#    #+#             */
/*   Updated: 2024/05/22 20:52:37 by joafern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_format(va_list args, const char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = len_putchar(va_arg(args, int));
	else if (c == 's')
		len = len_putstr(va_arg(args, char *));
	else if (c == 'p')
		len = len_putptr(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		len = len_putnbr(va_arg(args, int));
	else if (c == 'u')
		len = len_putnbr_unsigned(va_arg(args, unsigned int));
	else if (c == 'X' || c == 'x')
		len = len_putnbr_hexa(va_arg(args, unsigned int), c);
	else if (c == '%')
		len = len_putchar('%');
	return (len);
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		len;
	int		i;

	if (!string)
		return (-1);
	len = 0;
	i = 0;
	va_start(args, string);
	while (string[i])
	{
		if (string[i] == '%')
			len += print_format(args, string[++i]);
		else 
			len += len_putchar(string[i]);
		i++;
	}
	va_end(args);
	return (len);
}
/*
int main(){
	ft_printf("%x\n", 9223372036854775807);
	printf("%x\n", 9223372036854775807);
	ft_printf("My memory address: %p\n", "Hello World");
	printf("Real memory address: %p\n", "Hello World");
	ft_printf("%p\n", (void *)'\0');
	printf("%p\n", (void *)'\0');
	ft_printf(" NULL %s NULL \n", (char *)NULL);
	printf(" NULL %s NULL \n", (char *)NULL);
}*/
