/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_part.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemeryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 14:26:01 by dsemeryc          #+#    #+#             */
/*   Updated: 2019/01/12 14:36:26 by dsemeryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse(t_stack **stack, int moved, int order, t_list **instructions)
{
	if (stack_size(*stack) / 2 < moved)
	{
		while (stack_size(*stack) - moved++ > 0)
			add_instruction(stack, stack, instructions, order ? "rb" : "ra");
	}
	else
		while (moved--)
			add_instruction(stack, stack, instructions, order ? "rrb" : "rra");
}

int		give_pivot(t_stack *stack, int length)
{
	int	*arr;
	int	tmp;

	arr = (int *)malloc(sizeof(int) * length);
	tmp = 0;
	while (tmp < length)
	{
		arr[tmp++] = stack->data;
		stack = stack->next;
	}
	arr = ft_insertion(arr, length);
	tmp = arr[length / 2];
	free(arr);
	return (tmp);
}

void	quick_sort_b(t_stack **stack_a, t_stack **stack_b,
		int num_to_sort, t_list **instructions)
{
	int pivot;
	int num_pushed;
	int count;
	int rotation;

	if (num_to_sort < 4)
		return (sort_up_to_three_b(stack_b, num_to_sort, instructions));
	else if (num_to_sort < 30 && stack_size(*stack_b) == num_to_sort)
		return (insertion_sort_b(stack_a, stack_b, num_to_sort, instructions));
	count = 0;
	num_pushed = 0;
	rotation = 0;
	pivot = give_pivot(*stack_b, num_to_sort);
	while (CAN_PUSH_B && count++ != num_to_sort)
	{
		if ((*stack_b)->data > pivot && ++num_pushed)
			add_instruction(stack_a, stack_b, instructions, "pa");
		else if (++rotation)
			add_instruction(stack_a, stack_b, instructions, "rb");
	}
	quick_sort_a(stack_a, stack_b, num_pushed, instructions);
	reverse(stack_b, rotation, 1, instructions);
	quick_sort_b(stack_a, stack_b, num_to_sort - num_pushed, instructions);
	while (num_pushed--)
		add_instruction(stack_a, stack_b, instructions, "pb");
}

void	quick_sort_a(t_stack **stack_a, t_stack **stack_b,
		int num_to_sort, t_list **instructions)
{
	int pivot;
	int num_pushed;
	int count;
	int rotation;

	if (num_to_sort < 4)
		return (sort_up_to_three_a(stack_a, num_to_sort, instructions));
	pivot = give_pivot(*stack_a, num_to_sort);
	rotation = 0;
	count = 0;
	num_pushed = 0;
	while (CAN_PUSH_A && count++ != num_to_sort)
	{
		if ((*stack_a)->data < pivot && ++num_pushed)
			add_instruction(stack_a, stack_b, instructions, "pb");
		else if (++rotation)
			add_instruction(stack_a, stack_b, instructions, "ra");
	}
	reverse(stack_a, rotation, 0, instructions);
	quick_sort_a(stack_a, stack_b, num_to_sort - num_pushed, instructions);
	quick_sort_b(stack_a, stack_b, num_pushed, instructions);
	while (num_pushed--)
		add_instruction(stack_a, stack_b, instructions, "pa");
}
