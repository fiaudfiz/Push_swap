/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 10:31:42 by miouali           #+#    #+#             */
/*   Updated: 2026/01/19 10:31:43 by miouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sa(t_stack *stack)
{
    swap(stack);
    write(1, "sa\n", 3);
}

void    sb(t_stack *stack)
{
    swap(stack);
    write(1, "sb\n", 3);
}

void    pa(t_stack **stack_a, t_stack **stack_b)
{
    push_to_stack(stack_b, stack_a);
    write(1, "pa\n", 3);
}

void    pb(t_stack **stack_a, t_stack **stack_b)
{
    push_to_stack(stack_a, stack_b);
    write(1, "pb\n", 3);
}

void    ra(t_stack  **stack_a)
{
    rotate(stack_a);
    write(1, "ra\n", 3);
}

void    rb(t_stack  **stack_b)
{
    rotate(stack_b);
    write(1, "rb\n", 3);
}

void    rra(t_stack  **stack_a)
{
    reverse_rotate(stack_a);
    write(1, "rra\n", 4);
}

void    rrb(t_stack  **stack_b)
{
    reverse_rotate(stack_b);
    write(1, "rrb\n", 4);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}