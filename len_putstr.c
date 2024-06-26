/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_putstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafern2 <joafern2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:44:01 by joafern2          #+#    #+#             */
/*   Updated: 2024/05/22 20:56:33 by joafern2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

int	len_putstr(char *s)
{
	int	len;

	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	write (1, s, len);
	return (len);
}
/*
int	main(){
	len_putstr("Hello World");
}*/
