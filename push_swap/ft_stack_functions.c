/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 19:55:36 by szakarya          #+#    #+#             */
/*   Updated: 2025/05/17 19:57:00 by szakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	stack_len(t_stack *a)
{
	t_stack	*current;
	int		len;

	len = 0;
	if (a == NULL || a == NULL)
		return (0);
	current = a;
	while (current)
	{
		len++;
		current = current->next;
	}
	return (len);
}

t_stack	*ft_lstnew(int data)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->data = data;
	new->cheapest = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*current;

	if (!new || !lst)
		return ;
	if (!(*lst))
	{
		*lst = new;
	}
	else
	{
		current = *lst;
		while (current->next)
			current = current->next;
		current->next = new;
		new->prev = current;
	}
}

int	ft_fill_stack(t_stack **a, char **str)
{
	t_stack	*new;
	int		i;
	long	n;

	i = 0;
	while (str[i])
	{
		if (error_syntax(str[i]))
			return (free_errors(a, str));
		n = ft_atoi(str[i]) + 1;
		if (error_duplicate(*a, n) || n > INT_MAX || n < INT_MIN)
		{
			return (free_errors(a, str));
		}
		new = ft_lstnew(n);
		if (!new)
			return (free_errors(a, str));
		ft_lstadd_back(a, new);
		i++;
	}
	return (0);
}
