/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemeryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 14:11:05 by dsemeryc          #+#    #+#             */
/*   Updated: 2019/01/12 17:11:28 by dsemeryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void					del_last(t_list **list, t_list **to_del, t_list **new)
{
	t_list				*crawler;

	crawler = *list;
	while (crawler && crawler->next && crawler->next->next)
		crawler = crawler->next;
	free(*to_del);
	free(*new);
	crawler->next = NULL;
}

void					change_last(t_list **instruction,
		char *insert, t_list **to_del)
{
	(*instruction)->content = insert;
	free(*to_del);
}

void					optimisation(t_list **instructions, t_list **new)
{
	t_list				*crawler;

	crawler = *instructions;
	while (crawler->next)
		crawler = crawler->next;
	if (CHECK("sa", "sb"))
		change_last(&crawler, "ss", new);
	else if (CHECK("ra", "rb"))
		change_last(&crawler, "rr", new);
	else if (CHECK("rrb", "rra"))
		change_last(&crawler, "rrr", new);
	else if (CHECK("pb", "pa"))
		del_last(instructions, &crawler, new);
	else if (CHECK("pa", "pb"))
		del_last(instructions, &crawler, new);
	else if (CHECK("ra", "rra"))
		del_last(instructions, &crawler, new);
	else if (CHECK("rb", "rrb"))
		del_last(instructions, &crawler, new);
	else if (CHECK("rra", "ra"))
		del_last(instructions, &crawler, new);
	else if (CHECK("rrb", "rb"))
		del_last(instructions, &crawler, new);
	else
		ft_lstaddend(instructions, new);
}

void					add_instruction(t_stack **stack_a, t_stack **stack_b,
		t_list **instructions, char *instr)
{
	t_list				*new;

	peforme_instruction(switch_instruction(instr), stack_a, stack_b);
	new = ft_lstnew(NULL, 0);
	new->content = instr;
	if (*instructions)
		optimisation(instructions, &new);
	else
		ft_lstaddend(instructions, &new);
}
