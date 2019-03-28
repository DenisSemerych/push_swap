/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service_functions2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemeryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 14:54:31 by dsemeryc          #+#    #+#             */
/*   Updated: 2019/01/12 17:59:06 by dsemeryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		free_str_arr(char **arr, int size)
{
	int		ind;

	ind = 0;
	while (ind < size)
		ft_strdel(&arr[ind++]);
	free(arr);
	arr = NULL;
}

int			count_size(char **arr)
{
	char	**tmp;
	int		size;

	size = 0;
	tmp = arr;
	while (tmp[size])
		size++;
	return (size);
}

int			can_push(t_stack *stack, int length, int pivot, int order)
{
	t_stack	*tmp;

	tmp = stack;
	while (length--)
	{
		if (order && pivot < tmp->data)
			return (1);
		else if (!order && pivot > tmp->data)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void		print_list(t_list *stack)
{
	t_list	*crawler;

	crawler = stack;
	while (crawler)
	{
		ft_putendl(crawler->content);
		crawler = crawler->next;
	}
}

void		give_numbers(t_stack *stack, int *a, int *b, int *c)
{
	*a = stack->data;
	stack->next ? (*b = stack->next->data) :
		(*b = 0);
	stack->next->next ? (*c = stack->next->next->data) :
		(*c = 0);
}
