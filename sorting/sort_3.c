/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemeryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 14:45:07 by dsemeryc          #+#    #+#             */
/*   Updated: 2019/01/12 14:50:12 by dsemeryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		move_to_top_b(t_stack **stack_b,
		t_stack *min, t_list **instructions)
{
	int		count_front;
	int		count_rev;
	t_stack	*crawler;

	crawler = *stack_b;
	count_front = 0;
	count_rev = 0;
	while (crawler->data != min->data)
	{
		crawler = crawler->next;
		count_front++;
	}
	while (crawler)
	{
		crawler = crawler->next;
		count_rev++;
	}
	if (count_rev < count_front)
		add_instruction(NULL, stack_b, instructions, "rrb");
	else
		add_instruction(NULL, stack_b, instructions, "rb");
}

int			int_sorted(t_stack *stack)
{
	t_stack	*crawler;

	crawler = stack;
	while (crawler->next)
	{
		if (crawler->data > crawler->next->data)
			return (0);
		crawler = crawler->next;
	}
	return (1);
}

int			int_sorted_b(t_stack *stack, int len)
{
	t_stack	*crawler;

	crawler = stack;
	while (crawler->next && len--)
	{
		if (crawler->data < crawler->next->data)
			return (0);
		crawler = crawler->next;
	}
	return (1);
}

t_stack		*find_min(t_stack *to_find)
{
	t_stack	*min;

	min = to_find;
	while (to_find)
	{
		if (to_find->data < min->data)
			min = to_find;
		to_find = to_find->next;
	}
	return (min);
}

t_stack		*find_last(t_stack *head)
{
	t_stack	*crawler;

	crawler = head;
	while (crawler && crawler->next)
		crawler = crawler->next;
	return (crawler);
}
