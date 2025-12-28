# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eamaral- <eamaral-student.42lisboa.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/20 15:11:43 by eamara-           #+#    #+#              #
#    Updated: 2025/12/28 19:01:19 by eamaral-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ========================
# 📚LIBFTPRINTF VARIABLES
# ========================

#NAME OF THE LIBRARY
NAME = libftprintf.a

# SOURCE FILES DIRECTORY
SRC_DIR = srcs

# SOURCE FILES
SRCS = $(SRC_DIR)/ft_printf.c \
		$(SRC_DIR)/ft_printf_functions.c

# OBJECT FILES
OBJS = $(SRCS:.c=.o)

# Header FILES PATH
INCLUDES = includes

# COMPILER AND FLAGS
#Wall: show all warnings
#Wextra: show extra warnings
#Werror: treat warnings as errors
#i: include directory for header files
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDES)

# ARCHIVER
#rcs: replace or create with index
AR = ar rcs

# REMOVE COMMAND
RM = rm -f

# ========================
#      🎨COLOR CODES
# ========================

# ANSI magic to make the terminal pop.
GREEN = \033[5;4;32m # Success vibes
YELLOW = \033[1;33m # Compilation hype
CYAN = \033[1;36m # File names
CRAZY_YELLOW = \033[5;3;7;33m # Cleanup rage
RESET = \033[0m # Back to default. Boring but necessary.

# ========================
#        🛠TARGETS
# ========================

# Default target
all: $(NAME)
$(NAME): $(OBJS)
	@echo "$(GREEN)✅ Creating library:$(RESET) $(CYAN)$(NAME)$(RESET)"
	@$(AR) $(NAME) $(OBJS)

# Compiling each .c file to .o
%.o: %.c
	@echo "⚙️$(YELLOW)Compiling:$(RESET) $(CYAN)$<$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

# ============================
# CLEANUP and REBUILD TARGETS
# ============================

# Cleanup targets
clean:
	@echo "$(CRAZY_YELLOW)🧹 Cleaning up object files...$(RESET)"
	@$(RM) $(OBJS)

# Full cleanup target
fclean: clean
	@echo "$(CRAZY_YELLOW)🧹 Cleaning up library file...$(RESET)"
	@$(RM) $(NAME)

# Rebuild target
re: fclean all

# Prevent conflicts with files named 'all', 'clean', etc.
.PHONY: all clean fclean re