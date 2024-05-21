/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waterz <waterz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:47:42 by joafern2          #+#    #+#             */
/*   Updated: 2024/05/21 20:31:38 by waterz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

int	len_putchar(char c);
int len_putstr(char *s);
int len_putnbr(long n);
int len_putnbr_unsigned(unsigned int);
int	len_putnbr_hexa(int nbr, char format);
int len_putptr(void *ptr);

static int	print_format(va_list args, const char c)
{
	int len;

	len = 0;
	if (c == 'c')
		len = len_putchar(va_arg(args, int));
	else if (c == 's')
		len = len_putstr(va_arg(args, char *));
	else if (c == 'p')
		len = len_putptr(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		len = len_putnbr(va_arg(args, int));
	else if ( c == 'u')
		len = len_putnbr_unsigned(va_arg(args, unsigned int));
	else if (c == 'X' || c == 'x')
		len = len_putnbr_hexa(va_arg(args, int), c);
	else if (c == '%')
		len = len_putchar('%');
	return (len);
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int	len;
	int	i;

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

int main(){
	ft_printf("char: %c \nstring: %s\ninteger: %d\npercentage sign: %%\n", 'A', "Hello World", 42);
	ft_printf("%u\n", 2147483648);
	ft_printf("My memory address: %p\n", "Hello World");
	printf("Real memory address: %p\n", "Hello World");
	ft_printf("%%\n");
}
