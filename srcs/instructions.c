/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   essai.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miouali <miouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:20:33 by miouali           #+#    #+#             */
/*   Updated: 2026/01/16 15:12:44 by miouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/includes/libft.h"

void push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	if (!*src | !*src)
    	return ;
	tmp = *src;
	*src = tmp->next;
	if (*src)
        (*src) -> prev = NULL;
    tmp -> prev = NULL;
    if (!*dest)
    {
        *dest = tmp;
        tmp -> next = NULL;
    }
    else
    {
        tmp -> next = *dest;
        (*dest) -> prev = tmp;
        *dest = tmp;
    }
}

void    swap(t_stack *src)
{
    long    tmp;
    long    temp_index;

    if (!src || !src->next)
        return;
    tmp = src->nbr;
    src->nbr = src->next->nbr;
    src->next->nbr = tmp;
    temp_index = src->index;
	src->index = src->next->index;
	src->next->index = temp_index;

}

void rotate(t_stack **src)
{
    t_stack     *first;
    t_stack     *last;

    if (!*src || !(*src)->next)
        return ;
    first = *src;
    last = *src;
    while (last->next)
        last = last->next;
    *src = first->next;
    (*src)->prev = NULL;
    last->next = first;
    first->prev = last;
    first->next = NULL;
}

void reverse_rotate(t_stack **src)
{
    t_stack *last;

    if (!*src || !(*src)->next)
        return ;
    last = *src;
    while (last->next)
        last = last->next;
    if (last -> prev)
        last -> prev -> next = NULL;
    last->next = *src;
    (*src)->prev = last;
    *src = last;
    last -> prev = NULL;
}

/*regles du parsing
on lui envoie un argument de type char*
on decoupe les espaces avec split
on envoie a atoi
on dit si cest un bon nombre genre pas trop grand
controle de doublon
on l'ajoute a la pile et maj des index*/



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