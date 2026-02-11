/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miouali <miouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:54:14 by miouali           #+#    #+#             */
/*   Updated: 2026/01/15 14:01:50 by miouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

#include <stdlib.h>
/*
void    ft_del_content(void *content)
{
    free(content);
}
*/
void	ft_lstclear(t_stack **lst)
{
	t_stack	*temp;

	if (lst == NULL || *lst == NULL)
		return ;
	while (*lst)
	{
		temp = (*lst) -> next;
		ft_lstdelone(*lst);
		*lst = temp;
	}
	*lst = NULL;
}
/*
int	main()
{
	char* content1;
	t_stack*	head = NULL;
	content1 = ft_strdup("Premier a libérer");
	head = ft_lstnew(content1);
	ft_lstclear(&head, ft_del_content);
}*/