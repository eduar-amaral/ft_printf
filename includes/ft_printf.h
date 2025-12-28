/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamaral- <eamaral-student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 13:30:28 by eamara-           #+#    #+#             */
/*   Updated: 2025/12/28 21:18:04 by eamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_printf_char(char c);
int	ft_printf_str(char *str);
int	ft_printf_nbr(long nb);
int	ft_printf_hex(unsigned long nb, char base);
int	ft_printf_pointer(unsigned long ptr);

#endif