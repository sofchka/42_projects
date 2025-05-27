/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 21:52:51 by szakarya          #+#    #+#             */
/*   Updated: 2025/05/17 19:25:46 by szakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_b2a(t_stack **a, t_stack **b)
{
	prep_for_push(a, (*b)->target, 'a');
	pa(a, b);
}

t_stack	*find_min(t_stack *stack)
{
	long	min;
	t_stack	*min_node;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->data < min)
		{
			min = stack->data;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

void	set_target_b(t_stack *a, t_stack *b)
{
	t_stack	*cur_a;
	t_stack	*target;
	long	best_index;

	while (b)
	{
		best_index = LONG_MAX;
		cur_a = a;
		while (cur_a)
		{
			if (cur_a->data > b->data && cur_a->data < best_index)
			{
				best_index = cur_a->data;
				target = cur_a;
			}
			cur_a = cur_a->next;
		}
		if (best_index == LONG_MAX)
			b->target = find_min(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	init_b(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	set_target_b(a, b);
}
