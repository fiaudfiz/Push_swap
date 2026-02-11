/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miouali <miouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 14:49:36 by miouali           #+#    #+#             */
/*   Updated: 2026/01/15 14:00:07 by miouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
void    ft_del_content(void *content)
{
    free(content);
}
*/

void	ft_lstdelone(t_stack *lst)
{
	if (lst == NULL)
		return ;
	free(lst);
}
/*
int	main()
{
	t_stack* head = NULL;
	char* delete = ft_strdup ("au revoir");
	t_stack* new_node = ft_lstnew(delete);
	ft_lstdelone(head, ft_del_content);
}
*/