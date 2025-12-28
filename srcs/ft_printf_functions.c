/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamaral- <eamaral-student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 13:31:50 by eamara-           #+#    #+#             */
/*   Updated: 2025/12/28 21:22:05 by eamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_char(char c)
{
	return (write(1, &c, 1));
}

int	ft_printf_str(char *str)
{
	int		printed_chars;

	printed_chars = 0;
	if (!str)
		str = "(null)";
	while (str[printed_chars])
	{
		if (write(1, &str[printed_chars], 1) == -1)
			return (-1);
		printed_chars++;
	}
	return (printed_chars);
}

int	ft_printf_nbr(long nb)
{
	int		printed_chars;
	int		result;

	printed_chars = 0;
	if (nb < 0)
	{
		result = write(1, "-", 1);
		if (result == -1)
			return (-1);
		printed_chars += result;
		nb = -nb;
	}
	if (nb >= 10)
	{
		result = ft_printf_nbr(nb / 10);
		if (result == -1)
			return (-1);
		printed_chars += result;
	}
	result = ft_printf_char((nb % 10) + '0');
		if (result == -1)
			return (-1);
	printed_chars += result;
	return (printed_chars);
}

int	ft_printf_hex(unsigned long nb, char base)
{
	char	*hex;
	int		printed_chars;
	int		result;

	hex = "0123456789abcdef";
	if (base == 'X')
		hex = "0123456789ABCDEF";
	printed_chars = 0;
	if (nb >= 16)
	{
		result = ft_printf_hex(nb / 16, base);
		if (result == -1)
			return (-1);
		printed_chars += result;
	}
	result = write(1, &hex[nb % 16], 1);
	if (result == -1)
		return (-1);
	printed_chars += result;
	return (printed_chars);
}

int	ft_printf_pointer(unsigned long ptr)
{
	int	printed_chars;
	int	result;

	printed_chars = 0;
	if (ptr == 0)
	{
		result = write(1, "(nil)", 5);
		if (result == -1)
			return (-1);
		return (printed_chars += result);
	}
	result = write(1, "0x", 2);
	if (result == -1)
		return (-1);
	printed_chars += result;
	result = ft_printf_hex(ptr, 'x');
	if (result == -1)
		return (-1);
	printed_chars += result;
	return (printed_chars);
}
