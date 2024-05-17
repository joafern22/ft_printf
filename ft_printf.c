/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waterz <waterz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:47:42 by joafern2          #+#    #+#             */
/*   Updated: 2024/05/17 22:15:08 by waterz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

int	len_putchar(char c);
int len_putstr(char *s);
int len_putnbr(long n);
int	ft_strlen(char *string);

static int	print_format(va_list args, const char c)
{
	int len;

	len = 0;
	if (c == 'c')
		len = len_putchar(va_arg(args, int));
	else if (c == 's')
		len = len_putstr(va_arg(args, char *));
	else if (c == 'p')
		return 0;
	else if (c == 'd' || c == 'i')
		len = len_putnbr(va_arg(args, int));
	else if (c == 'u')
		return 0;
		//ft_putnbr_fd(va_arg(args, unsigned int), 1);
	else if (c == 'X')
		return 0;
		//ft_putnbr_base(va_ar(args, int), "0123456789ABCDEF");
	else if (c == 'x')
		return 0;
		//ft_putnbr_base(va_ar(args, int), "0123456789abcdef");
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
			len += print_format(args, string[i++ + 1]);
		else 
			len += len_putchar(string[i]);
		i++;
	}
	va_end(args);
	return (len);
}

int main(){
	ft_printf("char: %c \nstring: %s\ninteger: %d\npercentage sign: %%\n", 'A', "Hello World", 42);
	ft_printf("%s\n", "Hello World");
	ft_printf("%d\n", 42);
	ft_printf("%%\n");
}
