/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_stacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miouali <miouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 10:56:49 by miouali           #+#    #+#             */
/*   Updated: 2026/08/26 14:21:07 by miouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	ft_display_stacks(t_stack *a, t_stack *b)
{
	t_stack	*tmp;
	int		size;

	printf("\n--- DEBUG STACKS ---\n");
	size = stack_size(a);
	printf("Stack A: ");
	tmp = a;
	while (size-- > 0)
	{
		printf("[%ld] ", tmp->nbr);
		tmp = tmp->next;
	}
	size = stack_size(b);
	printf("\nStack B: ");
	tmp = b;
	while (size-- > 0)
	{
		printf("[%ld] ", tmp->nbr);
		tmp = tmp->next;
	}
	printf("\n--------------------\n\n");
}
