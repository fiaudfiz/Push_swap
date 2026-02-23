/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:05:10 by miouali           #+#    #+#             */
/*   Updated: 2026/02/23 17:05:21 by miouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
}

void	sa(t_stack *stack)
{
	swap(stack);
}

void	sb(t_stack *stack)
{
	swap(stack);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push_to_stack(stack_b, stack_a);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push_to_stack(stack_a, stack_b);
}
