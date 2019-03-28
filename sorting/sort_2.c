/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemeryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 15:11:33 by dsemeryc          #+#    #+#             */
/*   Updated: 2019/01/12 16:18:53 by dsemeryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_up_to_three_b(t_stack **stack_b,
		int num_to_sort, t_list **instructions)
{
	if (num_to_sort == 2)
	{
		if ((*stack_b)->data < (*stack_b)->next->data)
			add_instruction(NULL, stack_b, instructions, "sb");
	}
	else if (stack_size(*stack_b) == 3)
		sort_three_b(stack_b, instructions);
	else
		sort_tree_spec_b(stack_b, num_to_sort, instructions);
}

void	sort_up_to_three_a(t_stack **stack_a,
		int num_to_sort, t_list **instructions)
{
	if (num_to_sort == 2)
	{
		if ((*stack_a)->data > (*stack_a)->next->data)
			add_instruction(stack_a, NULL, instructions, "sa");
	}
	else if (stack_size(*stack_a) == 3)
		sort_three_a(stack_a, instructions);
	else if (num_to_sort != 1)
		sort_tree_spec_a(stack_a, num_to_sort, instructions);
}
