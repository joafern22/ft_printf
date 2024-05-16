/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafern2 <joafern2@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:47:42 by joafern2          #+#    #+#             */
/*   Updated: 2024/05/16 19:41:17 by joafern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

int	print_format(va_list args, const char c)
{
	if (c == 'c')
		//ft_putchar_fd(va_arg(args, char), 1);
	else if (c == 's')
		//ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'p')
		
	else if (c == 'd' || c = 'i')
		//ft_putnbr_fd(va_arg(args, int), 1);
	else if (c == 'u')
		//ft_putnbr_fd(va_arg(args, unsigned int), 1);
	else if (c == 'X')
		//ft_putnbr_base(va_ar(args, int), "0123456789ABCDEF");
	else if (c == 'x')
		//ft_putnbr_base(va_ar(args, int), "0123456789abcdef");
	else if (c == '%')
		//ft_putchar_fd("%", 1);
	return (0);
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
	while (string[i++])
	{
		if (string[i] == "%")
			len =+ print_format(args, string[i++ + 1]);
		else 
			len += ft_putchar_fd(string[i], 1);
	}
	va_end(args);
	return (len);
}
