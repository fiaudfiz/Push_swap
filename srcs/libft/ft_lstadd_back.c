/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miouali <miouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 14:27:53 by miouali           #+#    #+#             */
/*   Updated: 2026/01/15 14:04:42 by miouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"


void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*node;

	if (!new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	node = *lst;
	while (node -> next != NULL)
		node = node -> next;
	node -> next = new;
	new -> next = NULL;
}
/*
int	main()
{
	int	i = 63;
	t_stack* head = NULL;
	t_stack*	new_node = ft_lstnew("test 1");
	head = ft_lstnew(&i);
	ft_lstadd_back(&head, new_node);
	printf("%d\n", *(int*)head->content);
	printf("%s", (char*)head->next->content);
}
*/