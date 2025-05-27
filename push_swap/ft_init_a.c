/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 19:53:19 by szakarya          #+#    #+#             */
/*   Updated: 2025/05/17 19:55:09 by szakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_max(t_stack *a)
{
	long	max;
	t_stack	*max_node;
	t_stack	*curr;

	if (!a)
		return (NULL);
	max = LONG_MIN;
	curr = a;
	while (curr)
	{
		if (curr->data > max)
		{
			max = curr->data;
			max_node = curr;
		}
		curr = curr->next;
	}
	return (max_node);
}

void	set_target_a(t_stack *a, t_stack *b)
{
	t_stack	*curr_b;
	t_stack	*target;
	long	best_match;

	while (a)
	{
		best_match = LONG_MIN;
		curr_b = b;
		while (curr_b)
		{
			if (curr_b->data < a->data && curr_b->data > best_match)
			{
				best_match = curr_b->data;
				target = curr_b;
			}
			curr_b = curr_b->next;
		}
		if (best_match == LONG_MIN)
			a->target = find_max(b);
		else
			a->target = target;
		a = a->next;
	}
}

void	cost_a(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_median))
			a->push_cost = len_a - a->index;
		if (a->target->above_median)
			a->push_cost += a->target->index;
		else
			a->push_cost += len_b - a->target->index;
		a = a->next;
	}
}

void	set_cheapest(t_stack *stk)
{
	long		cheapest;
	t_stack		*cheapest_s;

	if (!stk)
		return ;
	cheapest = LONG_MAX;
	while (stk)
	{
		if (stk->push_cost < cheapest)
		{
			cheapest = stk->push_cost;
			cheapest_s = stk;
		}
		stk = stk->next;
	}
	cheapest_s->cheapest = 1;
}

void	init_a(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_a(a, b);
	set_cheapest(a);
}
