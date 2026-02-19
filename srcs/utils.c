#include "push_swap.h"

int		satck_size(t_stack *stack)
{
	int	i;
	t_stack	*temp;

	i = 0;
	if (!stack)
		return (0);
	temp = stack;
	while (1)
	{
		i++;
		temp = temp->next;
		if (temp == stack)
			break;
	}
	return (i);
}

void	set_position(t_stack *stack)
{
	int	i;
	int	mid;
	int	size;
	t_stack *tmp;

	if (!stack)
		return ;
	size = size_stack(stack);
	i = 0;
	mid = size / 2;
	tmp = stack;
	while (i < size)
	{
		tmp->pos = i;
		if (i <= mid)
			tmp->above_median = 1;
		else
			tmp->above_median = 0;
		tmp = tmp->next;
		i++;

	}
}