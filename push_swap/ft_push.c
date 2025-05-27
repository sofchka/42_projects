/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 22:02:06 by szakarya          #+#    #+#             */
/*   Updated: 2025/05/16 22:02:13 by szakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_for_push(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!*b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->prev = NULL;
	tmp->prev = NULL;
	if (!*a)
	{
		*a = tmp;
		(*a)->next = NULL;
	}
	else
	{
		tmp->next = *a;
		tmp->next->prev = tmp;
		*a = tmp;
	}
}

void	pa(t_stack **a, t_stack **b)
{
	ft_for_push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	ft_for_push(b, a);
	write(1, "pb\n", 3);
}

int	ft_strlen_int(const char *str)
{
	int	i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	return (i);
}

int	ft_intlen(int a)
{
	int	res;

	res = 0;
	while (a > 0)
	{
		a = a / 10;
		res++;
	}
	return (res);
}
