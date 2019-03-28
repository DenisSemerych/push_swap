# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsemeryc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/21 19:58:50 by dsemeryc          #+#    #+#              #
#    Updated: 2019/01/12 16:35:08 by dsemeryc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CHECKER = checker

NAME_PUSH = push_swap

OBJ_PUSH = checker_instructions.o instructions.o service_functions2.o service_functions.o stack_func.o stack_func_2.o sort.o sort_2.o sort_3.o quicksort_part.o checker_peforming.o push_swap.o argument_validation.o

OBJ_CHECK = checker_instructions.o instructions.o service_functions2.o service_functions.o stack_func.o stack_func_2.o sort.o sort_2.o sort_3.o quicksort_part.o checker_peforming.o checker_p1.o argument_validation.o

SRCS = sorting/*.c checking/*.c service_and_stack/*.c

CFLAGS = -Wall -Wextra -Werror

all:
	make -C libft/
	@gcc -c $(CFLAGS) $(SRCS) -I includes/
	@gcc -o $(NAME_CHECKER) $(CFLAGS) $(OBJ_CHECK) libft/libftprintf.a -I includes/
	@gcc -o $(NAME_PUSH) $(CFLAGS) $(OBJ_PUSH) libft/libftprintf.a -I includes/
	@echo "Ready for action"

clean:
	@make clean -C libft
	@rm -rf $(OBJ_CHECK) $(OBJ_PUSH)

fclean: clean
	@make fclean -C libft
	@rm -rf $(NAME_CHECKER) $(NAME_PUSH)

re: fclean all
