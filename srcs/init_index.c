#include "push_swap.h"

void	init_index(t_stack **stack_a)
{
	int	i;
	int	j;
	int	k;
	int	count;
	t_stack	*check;

	k = 0;
	j = stack_size(stack);
	i = 0;
	while (i < j)
	{
		count = 0;
		check = stack;
		k = 0;
		while (k < j)
		{
			if (check->nbr < stack->nbr)
				count++;
			check = check->next;
			k++;	
		}
		stack->index = count;
		stack = stack->next;
		i++;
	}
}	
