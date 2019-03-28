/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemeryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 15:12:57 by dsemeryc          #+#    #+#             */
/*   Updated: 2019/01/12 18:24:15 by dsemeryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int argc, char **argv)
{
	int		*arr;
	int		mode;
	char	**arguments;
	int		size;

	if (argc > 1)
	{
		argc == 2 ? (arguments = ft_strsplit(argv[1], ' ')) :
			(arguments = &argv[1]);
		size = str_arr_count(arguments);
		arr = (int *)malloc(sizeof(int) * size);
		mode = parse_arguments(arguments, size, arr);
		sort(arr, size - 1);
	}
}

void		sort(int *arr, int size)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_list	*instructions;

	stack_a = create_stack(arr, size);
	stack_b = NULL;
	instructions = NULL;
	if (!int_sorted(stack_a))
		quick_sort_a(&stack_a, &stack_b, stack_size(stack_a), &instructions);
	print_list(instructions);
	ft_lstdel(&instructions, NULL);
	free_list(&stack_a);
	free_list(&stack_b);
}
