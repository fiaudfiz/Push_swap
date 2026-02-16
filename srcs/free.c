/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miouali <miouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 13:23:12 by miouali           #+#    #+#             */
/*   Updated: 2026/01/16 13:24:22 by miouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/includes/libft.h"

void ft_free_stack(t_stack **stack)
{
    t_stack *tmp;

    if (!stack || !*stack)
        return ;
    while (*stack)
    {
        tmp = (*stack)->next;
        free(*stack);
        *stack = tmp;
    }
}

void ft_free_tab(char **tab)
{
    int i;

    i = 0;
    if (!tab)
        return ;
    while (tab[i])
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}

void ft_free_all(t_stack **stack, char **tab)
{
    if (tab)
        ft_free_tab(tab);
    if (stack && *stack)
        ft_free_stack(stack);
}