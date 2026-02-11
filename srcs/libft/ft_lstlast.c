/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miouali <miouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 14:15:02 by miouali           #+#    #+#             */
/*   Updated: 2026/01/15 14:07:06 by miouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"


t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next)
			lst = lst -> next;
	return (lst);
}
/*
int	main()
{
	t_stack* head = NULL;
	t_stack* node1 = ft_lstnew("hello");
	t_stack* node2 = ft_lstnew("la");
	t_stack* node3 = ft_lstnew("team");
	ft_lstadd_front(&head, node1);
	ft_lstadd_front(&head, node2);
	ft_lstadd_front(&head, node3);
	printf("%s", (char*)ft_lstlast(head)-> content);
}*/