#include "push_swap.h"

void	sort_three(t_stack **stack)
{
	int	a;
	int	b;
	int	c;
	
	a = (*stack)->index;
	b = (*stack)->next->index;
	c = (*stack)->next->next->index;
	if (a > b && a > c)
        ra(stack);
    else if (b > a && b > c)
        rra(stack);
    a = (*stack)->index;
    b = (*stack)->next->index;

    if (a > b)
        sa(*stack);
}