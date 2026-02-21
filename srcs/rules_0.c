/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miouali <miouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 10:31:42 by miouali           #+#    #+#             */
/*   Updated: 2026/02/21 15:07:58 by miouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack)
{
	swap(stack);
	write(1, "sa\n", 3);
}

void	sb(t_stack *stack)
{
	swap(stack);
	write(1, "sb\n", 3);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push_to_stack(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push_to_stack(stack_a, stack_b);
	write(1, "pb\n", 3);
}

void	ra(t_stack  **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}
