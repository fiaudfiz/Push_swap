#include "push_swap.h"


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

void    ft_lst_add_front(t_stack **lst, t_stack *new)
{
    if (!new)
        return ;
    new -> next = *lst;
    *lst = new;
}

void    ft_lst_clear(t_stack **lst)
{
    t_stack *temp;

    if(lst == NULL || *lst == NULL)
        return ;
    while (*lst)
    {
        temp = (*lst) -> next;
        ft_lstdelone(*lst);
        *lst = temp;
    }
    *lst = temp;
}

void ft_lstdelone(t_stack *lst)
{
    if (lst == NULL)
        return ;
    free (lst);
}

ft_lstlast(t_stack *lst)
{
    if (!lst)
        return (NULL);
    while (lst -> next)
        lst = lst -> next;
    return (lst);
}

void *ft_lstnew(int nbr)
{
    t_stack *new;

    new = malloc(sizeof(t_stack));
    if (!new)
        return (NULL);
    new ->nbr = nbr;
    new -> index = -1;
    new -> next = NULL;
    return (new);
}

int ft_lstsize(t_stack *lst)
{
    int len;
    t_stack *node;

    node = lst;
    len = 0;
    while (node != NULL)
    {
        node = node -> next;
        len++;
    }
    return (len);
    
}