/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 22:02:33 by szakarya          #+#    #+#             */
/*   Updated: 2025/05/16 22:03:34 by szakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_for_rev_rotate(t_stack **stk)
{
	t_stack	*last;

	if (!(*stk) || !(*stk)->next)
		return ;
	last = *stk;
	while (last->next != NULL)
		last = last->next;
	last->prev->next = NULL;
	last->next = *stk;
	last->prev = NULL;
	*stk = last;
	last->next->prev = last;
}

void	rra(t_stack **a)
{
	ft_for_rev_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	ft_for_rev_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	ft_for_rev_rotate(a);
	ft_for_rev_rotate(b);
	write(1, "rrr\n", 4);
}
