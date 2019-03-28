/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemeryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 10:56:19 by dsemeryc          #+#    #+#             */
/*   Updated: 2019/01/12 17:21:39 by dsemeryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "printf.h"
# include <stdlib.h>
# define BUFF_SIZE 32
# define EQL(a, b) !ft_strcmp(a, b)
# define CHECK(a, b) EQL(crawler->content, a) && EQL((*new)->content, b)
# define CAN_PUSH_A	can_push(*stack_a, num_to_sort - count, pivot, 0)
# define CAN_PUSH_B can_push(*stack_b, num_to_sort - count, pivot, 1)

typedef	struct		s_stack
{
	int				data;
	struct s_stack	*next;
}					t_stack;
void				push(t_stack **stack_one, t_stack **stack_two);
t_stack				*find_last(t_stack *head);
void				swap(t_stack **stack_a, t_stack **stack_b);
void				rotate(t_stack **head, t_stack **head_b);
void				rev_rotate(t_stack **head, t_stack **head_b);
t_stack				*create_stack(int *data, int size);
void				free_list(t_stack **stack);
void				is_sorted(t_stack *stack);
int					parse_arguments(char **arguments, int size, int tab[]);
void				sort_three_b(t_stack **stack, t_list **instructions);
void				sort_three_a(t_stack **stack, t_list **instructions);
void				put_err_msg_exit(char *str);
int					*read_instructions(int *inst_count);
void				peforme(int *arr, int size,
					int *instructions, int inst_count);
void				sort(int *arr, int size);
void				quick_sort_a(t_stack **stack_a, t_stack **stack_b,
					int num_to_sort, t_list **instructions);
int					stack_size(t_stack *stack);
t_stack				*find_max(t_stack *to_find);
void				sort_up_to_three_a(t_stack **stack,
					int num_to_sort, t_list **instructions);
void				sort_up_to_three_b(t_stack **stack,
					int num_to_sort, t_list **instructions);
void				move_to_top_b(t_stack **stack, t_stack *min,
					t_list **instructions);
void				insertion_sort_b(t_stack **stack_a, t_stack **stack_b,
					int num_to_sort, t_list **instructions);
void				peforme_instruction(int inst, t_stack **stack_a,
					t_stack **stack_b);
int					switch_instruction(char *str);
void				add_instruction(t_stack **stack_a, t_stack **stack_b,
					t_list **instructions, char *instr);
void				print_list(t_list *stack);
int					str_arr_count(char **arr);
void				free_str_arr(char **arr, int size);
int					check_for_mode(char *arg, int *mode);
int					count_size(char **arr);
int					can_push(t_stack *stack, int length, int pivot, int order);
void				give_numbers(t_stack *stack, int *a, int *b, int *c);
t_stack				*find_before_last(t_stack *head);
void				sort_tree_spec_a(t_stack **stack_a,
					int num_to_sort, t_list **instructions);
void				sort_tree_spec_b(t_stack **stack_b,
					int num_to_sort, t_list **instructions);
int					int_sorted(t_stack *stack);
#endif
