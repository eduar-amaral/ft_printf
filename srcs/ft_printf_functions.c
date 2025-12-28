/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamara- <eamara-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 13:31:50 by eamara-           #+#    #+#             */
/*   Updated: 2025/12/28 12:12:07 by eamara-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_printf_str(va_list args)
{
	int		printed_chars;
	char	*str;

	str = va_arg(args, char *);
	printed_chars = 0;
	if (!str)
		str = "(null)";
	while (str[printed_chars])
	{
		write(1, &str[printed_chars], 1);
		printed_chars++;
	}
	return (printed_chars);
}

int	ft_printf_nbr(va_list args)
{
	int	printed_chars;
	int	n;

	printed_chars = 0;
	n = va_arg(args, int);
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		printed_chars += write(1, "-", 1);
		n = -n;
	}
	printed_chars += ft_printf_nbr_helper(n);
	return (printed_chars);
}

int	ft_printf_unsigned(va_list args)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	return (ft_printf_unsigned_helper(n));
}

int	ft_printf_hex(va_list args, char base)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	return (ft_printf_hex_helper((unsigned long)n, base));
}

int	ft_printf_pointer(va_list args)
{
	unsigned long	ptr;
	int				printed_chars;

	ptr = (unsigned long)va_arg(args, void *);
	if (ptr == 0)
		return (write(1, "(nil)", 5));
	printed_chars = 0;
	printed_chars += write(1, "0x", 2);
	printed_chars += ft_printf_hex_helper(ptr, 'x');
	return (printed_chars);
}
