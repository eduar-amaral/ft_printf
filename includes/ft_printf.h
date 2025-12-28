/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamara- <eamara-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 13:30:28 by eamara-           #+#    #+#             */
/*   Updated: 2025/12/27 23:26:16 by eamara-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_printf_str(va_list args);
int	ft_printf_nbr(va_list args);
int	ft_printf_nbr_helper(int n);
int	ft_printf_unsigned(va_list args);
int	ft_printf_unsigned_helper(unsigned int n);
int	ft_printf_hex(va_list args, char base);
int	ft_printf_hex_helper(unsigned long n, char base);
int	ft_printf_pointer(va_list args);

#endif