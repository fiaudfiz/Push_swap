/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miouali <miouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:13:27 by miouali           #+#    #+#             */
/*   Updated: 2026/02/23 12:08:52 by miouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stddef.h>
# include <sys/types.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <string.h>
# include <strings.h>
# include <limits.h>
# include <stdarg.h>

typedef struct s_stack
{
	long			nbr;
	long			index;
	int				pos;
	int				cost_a;
	int				cost_b;
	int				above_median;
	int				cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

int		check_double(t_stack *stack, int nb);
char	**join_and_split(char **av);
int		ft_check_and_add(t_stack **stack_a, long nb, int *error);
int		parsing(char **av, t_stack **stack_a);
char	*ft_strbigjoin(char **str_tab);
void	ft_free_stack(t_stack **stack);
void	ft_free_tab(char **tab);
void	ft_free_all(t_stack **stack, char **tab);
int		ft_atoll(const char *str, int *error);
void	ft_display_stacks(t_stack *a, t_stack *b);
void	init_index(t_stack **stack_a);
void	push_to_stack(t_stack **src, t_stack **dest);
void	rotate(t_stack **src);
void	reverse_rotate(t_stack **src);
void	swap(t_stack *stack);
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rr(t_stack **a, t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	sort_three(t_stack **stack);
void	ft_lstadd_back_stack(t_stack **lst, t_stack *new);
t_stack	*ft_lstnew_stack(int nbr);
int		stack_size(t_stack *stack);
void	set_position(t_stack *stack);
t_stack	*find_max_stack(t_stack *stack);
void	set_target_a_to_b(t_stack *stack_a, t_stack *stack_b);
void	set_cost(t_stack *stack_a, t_stack *stack_b);
int		abs(int a);
int		max(int a, int b);
int		max_abs(int a, int b);
void	set_cheapest(t_stack *stack_a);
void	rotate_both(t_stack **stack_a, t_stack **stack_b,
			t_stack *cheapest_node);
void	finish_rotation(t_stack **stack_a, t_stack **stack_b,
			t_stack *cheapest_node);
t_stack	*get_cheapest(t_stack *stack);
void	move_a_to_b(t_stack **stack_a, t_stack **stack_b);
t_stack	*find_min_stack(t_stack *stack);
void	set_target_b_to_a(t_stack **stack_a, t_stack **stack_b);
void	finish_rotation_only_a(t_stack **stack_a, t_stack *target_node);
void	move_b_to_a(t_stack **stack_a, t_stack **stack_b);
int		is_sorted(t_stack *stack);
void	init_nodes_a(t_stack *stack_a, t_stack *stack_b);
void	init_nodes_b(t_stack *stack_a, t_stack *stack_b);
void	sort_stacks(t_stack **stack_a, t_stack **stack_b);
void	min_on_top(t_stack **a);
int		find_cost(t_stack *temp_a);

#endif
