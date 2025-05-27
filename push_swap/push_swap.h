/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 22:08:00 by szakarya          #+#    #+#             */
/*   Updated: 2025/05/17 19:49:51 by szakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int					index;
	int					data;
	int					cheapest;
	int					above_median;
	int					push_cost;
	struct s_stack		*target;
	struct s_stack		*next;
	struct s_stack		*prev;
}					t_stack;

int					stack_sorted(t_stack *stack);
int					stack_len(t_stack *a);
void				ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack				*ft_lstnew(int content);
int					ft_fill_stack(t_stack **a, char **str);
void				sort_two(t_stack **a);
void				sort_three(t_stack **a);
void				min_on_top(t_stack **a);
void				sort_stacks(t_stack **a, t_stack **b);
void				init_a(t_stack *a, t_stack *b);
void				init_b(t_stack *a, t_stack *b);
void				current_index(t_stack *a);
void				move_a2b(t_stack **a, t_stack **b);
void				move_b2a(t_stack **a, t_stack **b);
t_stack				*find_min(t_stack *stack);
t_stack				*find_max(t_stack *a);
void				prep_for_push(t_stack **stk, t_stack *top, char name);
long int			ft_atoi(const char *str);
size_t				ft_strlen(const char *str);
char				**ft_split(char *s, char c);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
char				*ft_strjoin(char *s1, char const *s2);
char				*ft_strdup(const char *s);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				free_split(char **arr);
int					ft_strlen_int(const char *str);
int					ft_intlen(int a);
int					free_errors(t_stack **a, char **str);
void				free_stack(t_stack *stack);
int					error_duplicate(t_stack *a, int n);
int					error_syntax(char *str_n);
int					no_num(char *argv);
void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);
// sa/sb: Swap top 2 elements of stack a/b (do nothing if <2 elements)
// ss: sa and sb at the same time
// pa: Push top of b to a (do nothing if b is empty)
// pb: Push top of a to b (do nothing if a is empty)
// ra/rb: Rotate stack a/b up by 1 (first becomes last)
// rr: ra and rb at the same time
// rra/rrb: Reverse rotate stack a/b (last becomes first)
// rrr: rra and rrb at the same time

#endif
