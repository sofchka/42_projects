/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 19:57:30 by szakarya          #+#    #+#             */
/*   Updated: 2025/05/17 19:57:49 by szakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_for_rotate(t_stack **stk)
{
	t_stack	*last;

	if (!(*stk) || !(*stk)->next)
		return ;
	last = *stk;
	while (last->next != NULL)
		last = last->next;
	last->next = *stk;
	*stk = (*stk)->next;
	(*stk)->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
}

void	ra(t_stack **a)
{
	ft_for_rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	ft_for_rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	ft_for_rotate(a);
	ft_for_rotate(b);
	write(1, "rr\n", 3);
}
