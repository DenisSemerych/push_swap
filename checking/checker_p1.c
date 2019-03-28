/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_p1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemeryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 14:58:13 by dsemeryc          #+#    #+#             */
/*   Updated: 2019/01/12 18:24:32 by dsemeryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int argc, char **argv)
{
	int		*arr;
	int		*instructions;
	int		inst_count;
	int		size;
	char	**arguments;

	inst_count = 0;
	if (argc > 1)
	{
		arguments = (argc == 2 ? ft_strsplit(argv[1], ' ') : &argv[1]);
		size = str_arr_count(arguments);
		arr = (int *)malloc(sizeof(int) * size);
		parse_arguments(arguments, size, arr);
		instructions = read_instructions(&inst_count);
		peforme(arr, size - 1, instructions, inst_count);
	}
}
