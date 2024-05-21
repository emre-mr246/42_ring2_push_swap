# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/11 07:09:36 by emgul             #+#    #+#              #
#    Updated: 2024/05/21 16:46:04 by emgul            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES			=	push_swap \
					sort_stack	\
					init_a_to_b	\
					init_b_to_a	\
					utils/check	\
					utils/error	\
					utils/find_node	\
					utils/free	\
					utils/utils	\
					utils/get_node_to_top	\
					utils/stack_utils	\
					commands/push	\
					commands/swap	\
					commands/rotate	\
					commands/rev_rotate

NAME			=	push_swap
AR_NAME			=	push_swap.a

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror -I $(LIBFT_PATH) 
AR				=	ar rcs
RM				=	rm -rf

LIBFT_PATH		=	lib/libft/
LIBFT			=	$(LIBFT_PATH)libft.a

CHECKER_PATH	=	checker/
CHECKER_NAME	=	checker

FILES_PATH		=	src

SRCS			=	$(addprefix $(FILES_PATH)/, $(addsuffix .c, $(FILES)))
OBJS			=	$(SRCS:.c=.o)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(LIBFT) $(OBJS) 
	@gcc $(OBJS) -o $(NAME) $(LIBFT)
	@echo "$(GREEN)-== $(NAME) created! ==-$(DEFAULT)"

$(LIBFT):
	@make -s -C $(LIBFT_PATH)

$(AR_NAME): $(LIBFT) $(OBJS) 
	@$(AR) $(AR_NAME) $(OBJS)

bonus:	$(AR_NAME)
	@make -s -C $(CHECKER_PATH)

all: $(NAME)
	
clean:
	@$(RM) $(OBJS)
	@make -s -C $(CHECKER_PATH) clean
	@echo "$(YELLOW)-== all created object files deleted! -==$(DEFAULT)"

fclean: clean libclean
	@$(RM) $(NAME)
	@$(RM) $(AR_NAME)
	@make -s -C $(CHECKER_PATH) fclean
	@echo "$(RED)-== all created files deleted! -==$(DEFAULT)"

libclean:
	@make -s -C $(LIBFT_PATH) fclean
	@make -s -C $(CHECKER_PATH) fclean
	@echo "$(BLUE)-== all created files deleted in libraries! -==$(DEFAULT)"

re: fclean all

.PHONY: all clean fclean re bonus

# ANSI COLOR CODES
DEFAULT = \033[0m
RED = \033[1;31m
YELLOW = \033[1;33m
GREEN = \033[1;32m
BLUE = \033[1;36m