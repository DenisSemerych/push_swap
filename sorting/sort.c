/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemeryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 15:00:51 by dsemeryc          #+#    #+#             */
/*   Updated: 2019/01/12 15:12:15 by dsemeryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_a(t_stack **stack_a, t_list **instructions)
{
	int	a;
	int	b;
	int	c;

	give_numbers(*stack_a, &a, &b, &c);
	if (a > b && b > c)
	{
		add_instruction(stack_a, NULL, instructions, "sa");
		add_instruction(stack_a, NULL, instructions, "rra");
	}
	else if (a > c && c > b)
		add_instruction(stack_a, NULL, instructions, "ra");
	else if (c > a && a > b)
		add_instruction(stack_a, NULL, instructions, "sa");
	else if (b > c && c > a)
	{
		add_instruction(stack_a, NULL, instructions, "rra");
		add_instruction(stack_a, NULL, instructions, "sa");
	}
	else if (b > c && c < a)
		add_instruction(stack_a, NULL, instructions, "rra");
}

void	sort_tree_spec_a(t_stack **stack_a,
		int num_to_sort, t_list **instructions)
{
	while (num_to_sort > 1)
	{
		if ((*stack_a)->data > (*stack_a)->next->data)
			add_instruction(stack_a, NULL, instructions, "sa");
		add_instruction(stack_a, NULL, instructions, "ra");
		num_to_sort--;
	}
	while (num_to_sort < 3)
	{
		add_instruction(stack_a, NULL, instructions, "rra");
		if ((*stack_a)->data > (*stack_a)->next->data)
			add_instruction(stack_a, NULL, instructions, "sa");
		num_to_sort++;
	}
	if ((*stack_a)->data > (*stack_a)->next->data)
		add_instruction(stack_a, NULL, instructions, "sa");
}

void	sort_tree_spec_b(t_stack **stack_b,
		int num_to_sort, t_list **instructions)
{
	while (num_to_sort > 1)
	{
		if ((*stack_b)->data < (*stack_b)->next->data)
			add_instruction(NULL, stack_b, instructions, "sb");
		add_instruction(NULL, stack_b, instructions, "rb");
		num_to_sort--;
	}
	while (num_to_sort < 3)
	{
		add_instruction(NULL, stack_b, instructions, "rrb");
		if ((*stack_b)->data < (*stack_b)->next->data)
			add_instruction(NULL, stack_b, instructions, "sb");
		num_to_sort++;
	}
	if ((*stack_b)->data < (*stack_b)->next->data)
		add_instruction(NULL, stack_b, instructions, "sb");
}

void	sort_three_b(t_stack **stack_b, t_list **instructions)
{
	int	a;
	int	b;
	int	c;

	give_numbers(*stack_b, &a, &b, &c);
	if (a < b && b < c)
	{
		add_instruction(NULL, stack_b, instructions, "sb");
		add_instruction(NULL, stack_b, instructions, "rrb");
	}
	else if (a < c && c < b)
	{
		add_instruction(NULL, stack_b, instructions, "rb");
	}
	else if (c < a && a < b)
		add_instruction(NULL, stack_b, instructions, "sb");
	else if (b < c && c < a)
	{
		add_instruction(NULL, stack_b, instructions, "rrb");
		add_instruction(NULL, stack_b, instructions, "sb");
	}
	else if (b < c && c > a)
		add_instruction(NULL, stack_b, instructions, "rrb");
}

void	insertion_sort_b(t_stack **stack_a, t_stack **stack_b,
		int num_to_sort, t_list **instructions)
{
	t_stack	*max;

	while (num_to_sort--)
	{
		max = find_max(*stack_b);
		while ((*stack_b) != max)
			move_to_top_b(stack_b, max, instructions);
		add_instruction(stack_a, stack_b, instructions, "pa");
	}
}
