/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafern2 <joafern2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:59:36 by joafern2          #+#    #+#             */
/*   Updated: 2024/05/22 20:55:52 by joafern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int	ft_printf(const char *string, ...);
int	len_putchar(char c);
int	len_putstr(char *s);
int	len_putnbr(int n);
int	len_putnbr_unsigned(unsigned int nbr);
int	len_putnbr_hexa(unsigned int nbr, char format);
int	len_putptr(void *ptr);
#endif
