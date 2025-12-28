/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamara- <eamara-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 21:01:41 by eamara-           #+#    #+#             */
/*   Updated: 2025/12/28 00:49:23 by eamara-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

// Function to wait for user to press Enter
static void	wait_for_enter(void)
{
	ft_printf("Press Enter to continue...\n");
	while (getchar() != '\n')
		;
}

static void	start_banner(void)
{
	ft_printf("|================================|\n");
	ft_printf("|      FT_PRINTF TESTING         |\n");
	ft_printf("|================================|\n\n");
}

static void	test_specifiers(unsigned int num, void *ptr, char *str)
{
	int				printed_chars[8];
	char			c;
	int				i[0];

	i[0] = 0;
	c = 'A';
	ft_printf("|================================|\n");
	ft_printf("|        SPECIFIER TESTS         |\n");
	ft_printf("|================================|\n\n");
	printed_chars[0] = ft_printf("1° Signed decimal (%%d/%%i): %d %i\n", num,
			-num);
	printed_chars[1] = ft_printf("2° Unsigned decimal (%%u): %u\n", num);
	printed_chars[2] = ft_printf("3° Lowercase hex (%%x): %x\n", num);
	printed_chars[3] = ft_printf("4° Uppercase hex (%%X): %X\n", num);
	printed_chars[4] = ft_printf("5° Pointer address (%%p): %p\n", ptr);
	printed_chars[5] = ft_printf("6° String (%%s): %s\n", str);
	printed_chars[6] = ft_printf("7° Character (%%c): %c\n", c);
	ft_printf("\nSummary of printed characters:\n");
	while (i[0] < 7)
	{
		ft_printf("Test %d printed %d characters.\n", i[0] + 1,
			printed_chars[i[0]]);
		i[0]++;
	}
}

static void	end_banner(void)
{
	ft_printf("\n|================================|\n");
	ft_printf("|        TESTING COMPLETE        |\n");
	ft_printf("|================================|\n");
}

int	main(void)
{
	int	value;

	value = 42;
	start_banner();
	wait_for_enter();
	ft_printf("Testing ft_printf with NULL string and empty string:\n");
	ft_printf("Result: %s\n", (char *) NULL);
	ft_printf("Result: '%s'\n", "");
	wait_for_enter();
	test_specifiers(2147483647, &value, "test string");
	wait_for_enter();
	ft_printf("All tests already tested specifier \"%%\" previously.\n");
	end_banner();
	return (0);
}
