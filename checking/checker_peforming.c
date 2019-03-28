/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_peforming.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemeryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 15:26:54 by dsemeryc          #+#    #+#             */
/*   Updated: 2019/01/12 18:43:44 by dsemeryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		peforme_instruction(int inst, t_stack **stack_a, t_stack **stack_b)
{
	void	(*p_arr[11]) (t_stack **stack_a, t_stack **stack_b);

	p_arr[0] = swap;
	p_arr[1] = swap;
	p_arr[2] = swap;
	p_arr[3] = push;
	p_arr[4] = push;
	p_arr[5] = rotate;
	p_arr[6] = rotate;
	p_arr[7] = rotate;
	p_arr[8] = rev_rotate;
	p_arr[9] = rev_rotate;
	p_arr[10] = rev_rotate;
	if (inst < 0)
		p_arr[inst * -1](stack_a, stack_b);
	else if (inst == 3)
		p_arr[inst](stack_a, stack_b);
	else if (inst == 4)
		p_arr[inst](stack_b, stack_a);
	else if (inst % 2)
		p_arr[inst](stack_b, NULL);
	else if (!(inst % 2))
		p_arr[inst](stack_a, NULL);
}

void		peforme(int *arr, int size, int *instructions, int inst_count)
{
	t_stack *stack_a;
	t_stack *stack_b;
	int		ind;

	stack_a = create_stack(arr, size);
	stack_b = NULL;
	ind = 0;
	while (ind < inst_count)
		peforme_instruction(instructions[ind++], &stack_a, &stack_b);
	if (stack_size(stack_a) != size)
		ft_putendl("KO");
	else
		is_sorted(stack_a);
	free_list(&stack_a);
	free_list(&stack_b);
}
