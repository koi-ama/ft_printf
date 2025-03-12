NAME    = libftprintf.a
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
AR      = ar rcs
RM      = rm -f

# Mandatory source files (placed directly in src/)
SRC     = src/ft_printf.c \
          src/ft_printf_conversion.c \
          src/ft_printf_print.c \
          src/ft_printf_number.c
OBJ     = $(SRC:.c=.o)

# Bonus source files (placed directly in src/)
BONUS_SRC = src/conversion_bonus.c \
            src/bonus_int_helpers.c \
            src/bonus_conv_extra.c
BONUS_OBJ = $(BONUS_SRC:.c=.o)

INCLUDES = includes

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INCLUDES)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

bonus: $(OBJ) $(BONUS_OBJ)
	$(AR) $(NAME) $(OBJ) $(BONUS_OBJ)

clean:
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re

