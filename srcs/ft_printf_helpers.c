/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamara- <eamara-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 20:44:55 by eamara-           #+#    #+#             */
/*   Updated: 2025/12/28 12:11:52 by eamara-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_printf_nbr_helper(int n)
{
	int		printed_chars;
	char	c;

	printed_chars = 0;
	if (n >= 10)
		printed_chars += ft_printf_nbr_helper(n / 10);
	c = (n % 10) + '0';
	printed_chars += write(1, &c, 1);
	return (printed_chars);
}

int	ft_printf_unsigned_helper(unsigned int n)
{
	char	c;
	int		printed_chars;

	printed_chars = 0;
	if (n >= 10)
		printed_chars += ft_printf_unsigned_helper(n / 10);
	c = (n % 10) + '0';
	printed_chars += write(1, &c, 1);
	return (printed_chars);
}

int	ft_printf_hex_helper(unsigned long n, char base)
{
	char	*hex;
	int		printed_chars;

	if (base == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	printed_chars = 0;
	if (n >= 16)
		printed_chars = ft_printf_hex_helper(n / 16, base);
	printed_chars += write(1, &hex[n % 16], 1);
	return (printed_chars);
}
