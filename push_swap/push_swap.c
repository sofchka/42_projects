/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 19:20:17 by szakarya          #+#    #+#             */
/*   Updated: 2025/05/17 19:26:07 by szakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**split_all_args(int argc, char **argv)
{
	char	*joined;
	int		i;
	char	**res;

	joined = ft_strdup("");
	i = 1;
	while (i < argc)
	{
		if (no_num(argv[i]))
		{
			free(joined);
			return (NULL);
		}
		joined = ft_strjoin(joined, " ");
		joined = ft_strjoin(joined, argv[i]);
		i++;
	}
	res = ft_split(joined, ' ');
	if (!res)
		return (NULL);
	return (res);
}

int	main_2(t_stack *a, t_stack *b, char *args[])
{
	if (ft_fill_stack(&a, args))
		return (1);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sort_two(&a);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**args;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (1);
	args = split_all_args(argc, argv);
	if (!args)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (main_2(a, b, args))
	{
		free_stack(a);
		free_stack(b);
		return (1);
	}
	free_stack(a);
	free_stack(b);
	return (0);
}
