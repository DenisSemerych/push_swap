/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemeryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 14:03:26 by dsemeryc          #+#    #+#             */
/*   Updated: 2019/01/12 16:05:35 by dsemeryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void					check_dup(int *tab, int num, int size)
{
	int					ind;

	ind = 0;
	while (ind < size)
		num == tab[ind] ? (put_err_msg_exit("Error: found duplicate numbers"))
			: ind++;
}

void					check_for_add_sym(char *str)
{
	char				*tmp;

	tmp = str;
	while (*tmp)
		!ft_isdigit(*tmp) ?
			(put_err_msg_exit("Error: found non-integer symbol"))
			: tmp++;
}

int						spec_atoi(const char *str)
{
	char				*tmp;
	unsigned long int	num;
	int					isn;

	num = 0;
	isn = 1;
	tmp = (char *)str;
	if (*tmp == 45)
		isn = -1;
	if (*tmp == 45 || *tmp == 43)
		tmp++;
	check_for_add_sym(tmp);
	while (*tmp > 47 && *tmp < 58)
	{
		num = (*tmp - 48) + (num * 10);
		if (num > 2147483647 && isn == 1)
			put_err_msg_exit("Error: number more int-max value");
		else if (num > 2147483648 && isn == -1)
			put_err_msg_exit("Error: number less int-min value");
		tmp++;
	}
	return ((int)(num * isn));
}

int						parse_arguments(char **arguments, int size, int *tab)
{
	int					ind;
	int					mode;

	ind = 1;
	check_for_mode(arguments[ind], &mode) ? ind += 2 : ind;
	while (ind < size)
	{
		tab[ind - 1] = spec_atoi(arguments[ind - 1]);
		check_dup(tab, tab[ind - 1], ind - 1);
		ind++;
	}
	return (mode);
}
