#include "push_swap.h"

void	rotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest_node)
{
	while (cheapest_node->cost_a > 0 && cheapest_node->cost_b > 0)
	{
		cheapest_node->cost_a--;
		cheapest_node->cost_b--;
		rr(stack_a, stack_b);
	}
	while (cheapest_node->cost_a < 0 && cheapest_node->cost_b < 0)
	{
		cheapest_node->cost_a++;
		cheapest_node->cost_b++;
		rrr(stack_a, stack_b);
	}
}

void	finish_rotation(t_stack **stack_a, t_stack **stack_b,t_stack *cheapest_node)
{
	while (cheapest_node->cost_a != 0)
    {
        if (cheapest_node->cost_a > 0)
        {
            ra(stack_a);
            cheapest_node->cost_a--;
        }
        else
        {
            rra(stack_a);
            cheapest_node->cost_a++;
        }
    }
    while (cheapest_node->cost_b != 0)
    {
        if (cheapest_node->cost_b > 0)
        {
            rb(stack_b);
            cheapest_node->cost_b--;
        }
        else
        {
            rrb(stack_b);
            cheapest_node->cost_b++;
        }
    }
}