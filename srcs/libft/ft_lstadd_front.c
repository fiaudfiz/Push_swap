/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miouali <miouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:10:34 by miouali           #+#    #+#             */
/*   Updated: 2026/01/15 13:51:56 by miouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"


void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (!new)
		return ;
	new -> next = *lst;
	*lst = new;
}
/*
int	main()
{
	int	i = 63;
	t_stack* head = NULL;
	t_stack*	new_node = ft_lstnew("test 1");
	head = ft_lstnew(&i);
	ft_lstadd_front(&head, new_node);
	printf("%s\n", (char*)head->content);
	printf("%d", *(int*)head->next->content);
}
*/