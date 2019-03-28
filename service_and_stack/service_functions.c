/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemeryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 14:50:21 by dsemeryc          #+#    #+#             */
/*   Updated: 2019/01/12 17:58:31 by dsemeryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		put_err_msg_exit(char *str)
{
	ft_putendl_fd(str, 2);
	exit(0);
}

int			check_for_mode(char *arg, int *mode)
{
	arg = "\0";
	*mode = 0;
	return (0);
}

int			str_arr_count(char **arr)
{
	int	count;

	count = 0;
	while (arr[++count])
		;
	return (count + 1);
}

void		is_sorted(t_stack *stack)
{
	t_stack	*crawler;

	crawler = stack;
	while (crawler && crawler->next)
	{
		if (crawler->data > crawler->next->data)
		{
			ft_putendl("KO");
			return ;
		}
		crawler = crawler->next;
	}
	ft_putendl("OK");
}

void		free_list(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*crawler;

	crawler = *stack;
	while (crawler)
	{
		tmp = crawler->next;
		free(crawler);
		crawler = tmp;
	}
	*stack = NULL;
}
