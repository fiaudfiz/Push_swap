/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miouali <miouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:23:01 by miouali           #+#    #+#             */
/*   Updated: 2026/02/23 21:01:32 by miouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../libft/includes/libft.h"

typedef struct s_stack
{
	long			nbr;
	long			index;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
	int				pos;
	int				cost_a;
	int				cost_b;
	int				above_median;
	int				cheapest;
}	t_stack;

//Parsing and validation
char	**join_and_split(char **av);
char	*ft_strbigjoin(char **str_tab);
int		ft_atoll(const char *str, int *error);
int		parsing(char **av, t_stack **stack_a);

//Memory Management
void	ft_free_stack(t_stack **stack);
void	free_stacks(t_stack **a, t_stack **b);

//Linked List Management
void	init_index(t_stack **stack_a);
void	send_to_stack(t_stack **dest, t_stack *temp);
int		stack_size(t_stack *stack);

//Core Instructions
void	push_to_stack(t_stack **src, t_stack **dest);
void	rotate(t_stack **src);
void	reverse_rotate(t_stack **src);
void	swap(t_stack *stack);

//Checker Rules
void	ss(t_stack *stack_a, t_stack *stack_b);
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

//Instruction Handling
void	execute_instruction(char *line, t_stack **stack_a, t_stack **stack_b);
int		is_an_instruction(char *line);
int		fetch_and_execute(char *line, t_stack **stack_a, t_stack **stack_b);
int		read_and_execute(t_stack **stack_a, t_stack **stack_b);

//Verification
int		is_sorted(t_stack *stack);

#endif
