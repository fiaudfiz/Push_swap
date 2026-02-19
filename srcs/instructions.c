/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miouali <miouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:20:33 by miouali           #+#    #+#             */
/*   Updated: 2026/02/19 17:36:11 by miouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/includes/libft.h"

void    push_to_stack(t_stack **src, t_stack **dest)
{
        t_stack     *temp;
        int         lst_size_src;
        int         lst_size_dest;

        if (!(*src))
            return ;
        lst_size_src  = ft_lst_size(src);
        lst_size_dest = ft_lst_size(dest);
        temp = *src;
        if (lst_size_src > 1)
        {
            (*src)->prev->next = (*src)-> next;
            (*src)->next->prev = (*src)->prev;
            *src = (*src)->next;

        }
        else if (lst_size_src == 1)
        {
            *src = NULL;
        }
        if (lst_size_dest == 0)
        {
            *dest = temp;
            (*dest)->next = temp;
            (*dest)->prev = temp;
        }
        else
        {
            temp->next = *dest;
            temp->prev = (*dest)->prev;
            (*dest)->prev->next = temp;
            (*dest)->prev = temp;
            *dest = temp;
        }
}

void    rotate(t_stack **src)
{
    if (!*src || ((*src)->next == *src))
        return;
    *src = (*src)->next;
}

void reverse_rotate(t_stack **src)
{
    if (!*src || (*src)->next == *src)
        return ;
    *src = (*src)->prev;
}