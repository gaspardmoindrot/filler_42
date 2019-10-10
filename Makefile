# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmoindro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/11 16:44:33 by gmoindro          #+#    #+#              #
#    Updated: 2019/08/22 13:06:37 by gmoindro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### COMPILATION ###
CC	= gcc
FLAGS	= -Wall -Wextra -Werror -o
MAKE	= make -C

### EXECUTABLE ###
NAME	= gmoindro.filler

### INCLUDES ###
LIBFT	= libft/
OBJPATH	= objs/
INCPATH	= includes/
SRCPATH	= srcs/

### SOURCES ###
SRCS	= srcs/main.c \
		  srcs/ft_get.c \
		  srcs/ft_change.c \
		  srcs/ft_have_coord.c \
		  srcs/ft_have_coord_1.c \
		  srcs/ft_change_bis.c \
		  srcs/ft_get_1.c \
		  srcs/ft_have_coord_2.c

### OBJECTS ###
OBJS	= $(SRCS:%.c=%.o)

%.o: $(SRCPATH)%.c
	$(CC) $(FLAGS) $@ $<

### COLORS ###
C_CLEAR		= \033[2K
C_UP		= \033[A
C_NOCOLOR	= \033[0m
C_BOLD		= \033[1m
C_UNDERLINE	= \033[4m
C_BLINKING	= \033[5m
C_BLACK		= \033[1;30m
C_RED		= \033[1;31m
C_GREEN		= \033[1;32m
C_YELLOW	= \033[1;33m
C_BLUE		= \033[1;34m
C_VIOLET	= \033[1;35m
C_CYAN		= \033[1;36m
C_WHITE		= \033[1;37m

### RULES ###

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(C_YELLOW)Compiling... $(NAME) \033[0m$(C_NOCOLOR)"
	@$(MAKE) $(LIBFT) fclean && $(MAKE) $(LIBFT)
	@$(CC) $(FLAGS) $(NAME) $(OBJS) -I $(LIBFT)$(INCPATH) -L $(LIBFT) -lft
	@echo "$(C_GREEN)== $(NAME) == was successfully created$(C_NOCOLOR)"

clean:
	@echo "$(C_RED)Deleting object files...$(C_NOCOLOR)"
	@$(MAKE) $(LIBFT) clean
	@/bin/rm -f $(OBJS)
	@echo "$(C_GREEN)Object files were successfully deleted.$(C_NOCOLOR)"

fclean:
	@echo "$(C_RED)Deleting everything...$(C_NOCOLOR)"
	@$(MAKE) $(LIBFT) fclean
	@/bin/rm -f $(OBJS)
	@/bin/rm -f $(NAME)
	@echo "$(C_GREEN)Everything was successfully deleted.$(C_NOCOLOR)"

re: fclean all

.PHONY : clean fclean re
