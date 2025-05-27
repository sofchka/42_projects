/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 19:52:01 by szakarya          #+#    #+#             */
/*   Updated: 2025/05/17 19:52:53 by szakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **a)
{
	if ((*a)->data > (*a)->next->data)
		sa(a);
}

void	sort_three(t_stack **a)
{
	t_stack	*biggest;

	biggest = find_max(*a);
	if (biggest == *a)
		ra(a);
	else if ((*a)->next == biggest)
		rra(a);
	if ((*a)->data > (*a)->next->data)
		sa(a);
}

void	min_on_top(t_stack **a)
{
	while ((*a)->data != find_min(*a)->data)
	{
		if (find_min(*a)->above_median)
			ra(a);
		else
			rra(a);
	}
}

void	current_index(t_stack *a)
{
	int	start;
	int	median;

	if (!a)
		return ;
	start = 0;
	median = stack_len(a) / 2;
	while (a)
	{
		a->index = start;
		if (start <= median)
			a->above_median = 1;
		else
			a->above_median = 0;
		a = a->next;
		start++;
	}
}

void	sort_stacks(t_stack **a, t_stack **b)
{
	int	len;

	len = stack_len(*a);
	if (len-- > 3 && !stack_sorted(*a))
		pb(a, b);
	if (len-- > 3 && !stack_sorted(*a))
		pb(a, b);
	while (len-- > 3 && !stack_sorted(*a))
	{
		init_a(*a, *b);
		move_a2b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_b(*a, *b);
		move_b2a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}
