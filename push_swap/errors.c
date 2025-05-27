/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 22:03:56 by szakarya          #+#    #+#             */
/*   Updated: 2025/05/16 22:07:24 by szakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	no_num(char *argv)
{
	int	j;

	if (!argv)
		return (1);
	j = 0;
	while (argv[j])
	{
		if (argv[j] >= '0' && argv[j] <= '9')
			return (0);
		j++;
	}
	return (1);
}

int	error_syntax(char *str_n)
{
	if (!(*str_n == '+' || *str_n == '-'
			|| (*str_n >= '0' && *str_n <= '9')))
		return (1);
	if ((*str_n == '+' || *str_n == '-')
		&& !(str_n[1] >= '0' && str_n[1] <= '9'))
		return (1);
	while (*++str_n)
	{
		if (!(*str_n >= '0' && *str_n <= '9'))
			return (1);
	}
	return (0);
}

int	error_duplicate(t_stack *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->data == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

int	free_errors(t_stack **a, char **str)
{
	int	i;

	free_stack(*a);
	i = 0;
	if (str)
	{
		while (str[i])
			free(str[i++]);
		free(str);
	}
	write(2, "Error\n", 6);
	return (1);
}
