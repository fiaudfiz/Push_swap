/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miouali <miouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 14:13:14 by miouali           #+#    #+#             */
/*   Updated: 2026/02/22 08:48:19 by miouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_on_top(t_stack **a)
{
	t_stack	*min_node;

	if (!a || !*a)
		return ;
	min_node = find_min_stack(*a);
	set_position(*a);
	while ((*a)->index != min_node->index)
	{
		if (min_node->above_median)
			ra(a);
		else
			rra(a);
	}
}

void	init_nodes_a(t_stack *stack_a, t_stack *stack_b)
{
	set_position(stack_a);
	set_position(stack_b);
	set_target_a_to_b(stack_a, stack_b);
	set_cost(stack_a, stack_b);
	set_cheapest(stack_a);
}

void	init_nodes_b(t_stack *stack_a, t_stack *stack_b)
{
	set_position(stack_a);
	set_position(stack_b);
	set_target_b_to_a(&stack_a, &stack_b);
}

void	sort_stacks(t_stack **stack_a, t_stack **stack_b)
{
	int	len_a;

	len_a = stack_size(*stack_a);
	if (len_a-- > 3 && is_sorted(*stack_a) == 0)
		pb(stack_a, stack_b);
	if (len_a-- > 3 && is_sorted(*stack_a) == 0)
		pb (stack_a, stack_b);
	while (len_a-- > 3 && is_sorted(*stack_a) == 0)
	{
		init_nodes_a(*stack_a, *stack_b);
		move_a_to_b(stack_a, stack_b);
		ft_display_stacks(*stack_a, *stack_b);
	}
	sort_three(stack_a);
	ft_display_stacks(*stack_a, *stack_b);
	while (*stack_b)
	{
		init_nodes_b(*stack_a, *stack_b);
		move_b_to_a(stack_a, stack_b);
		ft_display_stacks(*stack_a, *stack_b);
	}
	set_position(*stack_a);
	min_on_top(stack_a);
}
