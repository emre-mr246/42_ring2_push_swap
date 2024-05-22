# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/11 07:09:36 by emgul             #+#    #+#              #
#    Updated: 2024/05/22 11:56:51 by emgul            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES			=	checker_bonus	\
					utils_bonus

NAME			=	checker
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror -I $(LIBFT_PATH) -I $(PUSH_SWAP) -I $(PUSH_SWAP_UTILS_PATH) -I $(PUSH_SWAP_CMDS_PATH)
AR				=	ar rcs
RM				=	rm -rf

LIBFT_PATH				=	../lib/libft/
PUSH_SWAP_PATH			=	../src/
PUSH_SWAP_UTILS_PATH	=	../src/utils/
PUSH_SWAP_CMDS_PATH		=	../src/commands/

LIBFT			=	$(LIBFT_PATH)libft.a
PUSH_SWAP		=	../push_swap.a

SRCS			=	$(addsuffix .c, $(FILES))
OBJS			=	$(SRCS:.c=.o)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	@gcc $(OBJS) -o $(NAME) $(LIBFT) $(PUSH_SWAP)
	@$(RM) $(OBJS)
	@find . -name "*.dSYM" -type d | xargs $(RM)
	@$(RM) ../push_swap.a
	echo "$(GREEN)-== $(NAME) created! ==-$(DEFAULT)"

all: $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

# ANSI COLOR CODES
DEFAULT = \033[0m
RED = \033[1;31m
YELLOW = \033[1;33m
GREEN = \033[1;32m
BLUE = \033[1;36m