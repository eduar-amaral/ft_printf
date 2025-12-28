/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamaral- <eamaral-student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 12:41:41 by eamara-           #+#    #+#             */
/*   Updated: 2025/12/28 21:09:55 by eamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_specifier(char c, va_list args);

int	ft_printf(const char *str, ...)
{
	int		printed_chars;
	int		result;
	va_list	args;

	printed_chars = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			result = ft_specifier(*(++str), args);
				if (result == -1)
					return (va_end(args), -1);
			printed_chars += result;
		}
		else
		{
			if (write(1, str, 1) == -1)
					return (va_end(args), -1);
			printed_chars++;
		}
		str++;
	}
	va_end(args);
	return (printed_chars);
}

static int	ft_specifier(const char c, va_list args)
{
	if (c == 'c')
		return (ft_printf_char(va_arg(args, int)));
	else if (c == 's')
		return(ft_printf_str(va_arg(args, char *)));
	else if (c == '%')
		return (ft_printf_char('%'));
	else if (c == 'd' || c == 'i')
		return (ft_printf_nbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_printf_nbr(va_arg(args, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_printf_hex(va_arg(args, unsigned int), c));
	else if (c == 'p')
		return (ft_printf_pointer(va_arg(args, unsigned long)));
	return (-1);
}
