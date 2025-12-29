*This project has been created as part of the 42 curriculum by eamaral-.*

# FT_PRINTF

## Description

The **ft_printf** project is a copy of the C function `printf()`. The goal is to learn how functions with many arguments work and how to print different types of data.

This function prints text to the screen and returns how many characters it printed.

**What it can print:**
- `%c` - one character
- `%s` - text (string)
- `%p` - memory address (pointer)
- `%d` / `%i` - numbers with sign
- `%u` - numbers without sign
- `%x` - hexadecimal (small letters)
- `%X` - hexadecimal (big letters)
- `%%` - the % symbol

---

## Instructions

**How to compile:**

```bash
make
```

This creates the library file `libftprintf.a`.

**Other commands:**
```bash
make clean    # Delete temporary files
make fclean   # Delete everything
make re       # Compile again from zero
```

**How to use it:**

Put this at the top of your code: 
```c
#include "ft_printf.h"
```

Compile your program like this: 
```bash
cc -Wall -Wextra -Werror your_file.c libftprintf.a
```

**Example:**
```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Text: %s\n", "Hello");
    ft_printf("Number:  %d\n", 42);
    ft_printf("Hex: %x\n", 255);
    return (0);
}
```

 **Quick Test :**

Download the test file:

```bash
# Using curl
curl -O https://raw.githubusercontent.com/eduar-amaral/ft_printf/main/main.c
```

---

## Algorithm and Data Structure

**How it works:**

The function reads the format string letter by letter. When it finds `%`, it checks the next letter to know what type of data to print. 

**Steps:**
1. Read each character in the format string
2. When you find `%`, look at the next character
3. Call the right function for that type (`%d`, `%s`, etc.)
4. That function gets the data and prints it
5. Count how many characters were printed
6. Return the total count

**Project structure:**

The code is organized in 3 files:

- **ft_printf.c** - Contains the main function `ft_printf()` and the static function `ft_specifier()` that decides which function to call for each conversion type

- **ft_printf_functions.c** - Contains the main conversion functions: 
  - `ft_printf_str()` for `%s`
  - `ft_printf_nbr()` for `%d` and `%i`
  - `ft_printf_unsigned()` for `%u`
  - `ft_printf_hex()` for `%x` and `%X`
  - `ft_printf_pointer()` for `%p`

**Data structure:**

I use `va_list` (from `<stdarg.h>`) to handle many arguments. This is the normal way in C to make functions that can take different numbers of arguments.

**Why I chose this:**

For numbers (`%d`, `%u`, `%x`), I use **recursion** in the helper functions to print digits.  This means the function calls itself to print one digit at a time from left to right.

I chose recursion because:
- It is simple to understand
- It does not need arrays or extra memory
- It prints digits in the correct order

For `%c` and `%%`, the conversion is simple and done directly in `ft_specifier()` without needing a separate function.

For pointers (`%p`), I first check if it is NULL (zero). If yes, I print `(nil)`. If no, I print `0x` and then the address in hexadecimal using the same helper as `%x`.

The code is split into 3 files to keep it organized:
- Main logic in one file
- Conversion functions in another
- Helper functions (recursion) in the third

This makes the code easier to read and maintain.

---

## Resources

**Documentation:**
- `man 3 printf` - How the real printf works
- `man stdarg` - How to use functions with many arguments
- `man write` - How to write to the screen

**Tutorials:**
- [Variadic Functions in C](https://www.geeksforgeeks.org/variadic-functions-in-c/)

**AI Usage:**

I used AI for:
- **Finding documentation:** AI helped me find online resources and tutorials faster
- **README formatting:** AI helped organize and format this README file in markdown

---