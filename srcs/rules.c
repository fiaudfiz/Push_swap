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

#include "../../includes/push_swap.h"

void    sa(t_stack *stack)
{
    swap(stack);
}

void    sb(t_stack *stack)
{
    swap(stack);
}

void    pa(t_stack **stack_a, t_stack **stack_b)
{
    push(stack_b, stack_a);
}

void    pb(t_stack **stack_a, t_stack **stack_b)
{
    push(stack_a, stack_b);
}

void    ra(t_stack  **stack_a)
{
    rotate(stack_a);
}

void    rb(t_stack  **stack_b)
{
    rotate(stack_b);
}

void    rra(t_stack  **stack_a)
{
    reverse_rotate(stack_a);
}

void    rrb(t_stack  **stack_b)
{
    reverse_rotate(stack_b);
}