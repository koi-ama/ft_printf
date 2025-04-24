NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs
INCLUDES = -I ./includes

SRCS_DIR = ./src
SRCS    = $(wildcard $(SRCS_DIR)/*.c)

OBJS = $(SRCS:.c=.o)

LIBFT_PATH = ./src/libft/
LIBFT_NAME = libft.a

RESET = \033[0m
BOLD = \033[1m
YELLOW = \033[93m
LIGHT_BLUE = \033[94m

all: $(NAME)

.c.o:
	@echo "$(BOLD)$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	
$(NAME): $(OBJS)
	@echo "$(BOLD)$(LIGHT_BLUE)Linking objects...$(RESET)"
	@$(MAKE) -C $(LIBFT_PATH)
	@mv $(LIBFT_PATH)/$(LIBFT_NAME) $(NAME)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(BOLD)$(LIGHT_BLUE)$(NAME) created successfully!$(RESET)"

clean:
	@echo "$(BOLD)$(LIGHT_BLUE)Cleaning objects...$(RESET)"
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(RM) $(OBJS)
	@echo "$(BOLD)$(LIGHT_BLUE)Complete clean!$(RESET)"

fclean: clean
	@echo "$(BOLD)$(LIGHT_BLUE)Cleaning $(NAME)...$(RESET)"
	@$(RM) $(NAME)
	@echo "$(BOLD)$(LIGHT_BLUE)Complete fclean!$(RESET)"

re: fclean all

.PHONY: all clean fclean re
