/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miouali <miouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:20:33 by miouali           #+#    #+#             */
/*   Updated: 2026/02/21 14:55:17 by miouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/includes/libft.h"

void	send_to_stack(t_stack **dest, t_stack *temp)
{
	temp->next = *dest;
	temp->prev = (*dest)->prev;
	(*dest)->prev->next = temp;
	(*dest)->prev = temp;
	*dest = temp;
}

void	push_to_stack(t_stack **src, t_stack **dest)
{
	t_stack		*temp;

	if (!(*src))
		return ;
	temp = *src;
	if (stack_size(*src) > 1)
	{
		(*src)->prev->next = (*src)-> next;
		(*src)->next->prev = (*src)->prev;
		*src = (*src)->next;
	}
	else if (stack_size(*src) == 1)
		*src = NULL;
	if (stack_size(*dest) == 0)
	{
		*dest = temp;
		(*dest)->next = temp;
		(*dest)->prev = temp;
	}
	else
		send_to_stack(dest, temp);
}

void	rotate(t_stack **src)
{
	if (!*src || ((*src)->next == *src))
		return ;
	*src = (*src)->next;
}

void	reverse_rotate(t_stack **src)
{
	if (!*src || (*src)->next == *src)
		return ;
	*src = (*src)->prev;
}

void	swap(t_stack *stack)
{
	long	tmp_nbr;
	long	tmp_index;

	if (!stack || stack->next == stack)
		return ;
	tmp_nbr = stack->nbr;
	stack->nbr = stack->next->nbr;
	stack->next->nbr = tmp_nbr;
	tmp_index = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp_index;
}
