/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamara- <eamara-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 12:41:41 by eamara-           #+#    #+#             */
/*   Updated: 2025/12/28 12:12:15 by eamara-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int	ft_specifier(char c, va_list args);

int	ft_printf(const char *str, ...)
{
	int		i;
	int		printed_chars;
	va_list	args;

	if (!str)
		return (0);
	i = 0;
	printed_chars = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			printed_chars += ft_specifier(str[++i], args);
		else
			printed_chars += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (printed_chars);
}

static int	ft_specifier(char c, va_list args)
{
	int		printed_chars;
	char	ch;

	printed_chars = 0;
	if (c == 'c')
	{
		ch = va_arg(args, int);
		printed_chars += write(1, &ch, 1);
	}
	else if (c == 's')
		printed_chars += ft_printf_str(args);
	else if (c == '%')
		printed_chars += write(1, "%", 1);
	else if (c == 'd' || c == 'i')
		printed_chars += ft_printf_nbr(args);
	else if (c == 'u')
		printed_chars += ft_printf_unsigned(args);
	else if (c == 'x' || c == 'X')
		printed_chars += ft_printf_hex(args, c);
	else if (c == 'p')
		printed_chars += ft_printf_pointer(args);
	return (printed_chars);
}
