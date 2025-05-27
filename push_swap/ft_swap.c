/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 22:01:30 by szakarya          #+#    #+#             */
/*   Updated: 2025/05/16 22:01:41 by szakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_for_swap(t_stack **swap)
{
	if (!*swap || !(*swap)->next)
		return ;
	*swap = (*swap)->next;
	(*swap)->prev->prev = *swap;
	(*swap)->prev->next = (*swap)->next;
	if ((*swap)->next)
		(*swap)->next->prev = (*swap)->prev;
	(*swap)->next = (*swap)->prev;
	(*swap)->prev = NULL;
}

void	sa(t_stack **a)
{
	ft_for_swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	ft_for_swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	ft_for_swap(a);
	ft_for_swap(b);
	write(1, "ss\n", 3);
}

void	free_split(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}
