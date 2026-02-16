/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_stacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 10:56:49 by miouali           #+#    #+#             */
/*   Updated: 2026/01/19 10:57:21 by miouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/includes/libft.h"

void    ft_display_stacks(t_stack *stack_a, t_stack *stack_b)
{
    ft_printf("-----STACK_A-----\n");
    while (stack_a != NULL)
    {
        ft_printf ("%d\n", stack_a -> nbr);
        stack_a = stack_a -> next;
    }
    ft_printf ("-----STACK_B-----\n");
    while (stack_b != NULL)
    {
        ft_printf ("%d\n", stack_b -> nbr);
        stack_b = stack_b -> next;
    }
}
