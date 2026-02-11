/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miouali <miouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 14:04:41 by miouali           #+#    #+#             */
/*   Updated: 2026/01/15 13:51:56 by miouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"


int	ft_lstsize(t_stack *lst)
{
	int		len;
	t_stack	*node;

	node = lst;
	len = 0;
	while (node != NULL)
	{
		node = node -> next;
		len++;
	}
	return (len);
}
/*
int	main()
{
	int	taille;
	t_stack* head = NULL;
	head = ft_lstnew("Test 1");
	taille = ft_lstsize(head);
	printf("%d", taille);
}
*/