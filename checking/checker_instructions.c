/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemeryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 15:22:38 by dsemeryc          #+#    #+#             */
/*   Updated: 2019/01/12 15:26:24 by dsemeryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			switch_instruction(char *str)
{
	if ((ft_strcmp(str, "sa")) == 0)
		return (0);
	else if ((ft_strcmp(str, "sb")) == 0)
		return (1);
	else if ((ft_strcmp(str, "ss")) == 0)
		return (-2);
	else if ((ft_strcmp(str, "pa")) == 0)
		return (3);
	else if ((ft_strcmp(str, "pb")) == 0)
		return (4);
	else if ((ft_strcmp(str, "ra")) == 0)
		return (6);
	else if ((ft_strcmp(str, "rb")) == 0)
		return (5);
	else if ((ft_strcmp(str, "rr")) == 0)
		return (-7);
	else if ((ft_strcmp(str, "rra")) == 0)
		return (8);
	else if ((ft_strcmp(str, "rrb")) == 0)
		return (9);
	else if ((ft_strcmp(str, "rrr")) == 0)
		return (-10);
	else
		return (-1);
}

int			*validate_inst(char **instructions, int size)
{
	int		ind;
	int		*tab;
	int		inst;

	ind = -1;
	tab = (int *)malloc(sizeof(int) * size);
	while (instructions[++ind])
		(inst = switch_instruction(instructions[ind])) == -1
			? put_err_msg_exit("Error: incorect instrution")
			: (tab[ind] = inst);
	free_str_arr(instructions, size);
	return (tab);
}

int			*read_instructions(int *inst_count)
{
	char	**instructions;
	char	*string;
	char	buff[BUFF_SIZE + 1];
	int		ret;
	char	*tmp;

	string = ft_strnew(1);
	while ((ret = read(0, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		tmp = ft_strjoin(string, buff);
		free(string);
		string = tmp;
	}
	instructions = ft_strsplit(string, '\n');
	free(string);
	*inst_count = count_size(instructions);
	return (validate_inst(instructions, *inst_count));
}
