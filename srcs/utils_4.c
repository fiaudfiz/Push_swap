#include "push_swap.h"

t_stack *get_cheapest(t_stack *stack)
{
    t_stack *start = stack;
    while (stack)
    {
        if (stack->cheapest == 1)
            return (stack);
        stack = stack->next;
        if (stack == start)
            break;
    }
    return (NULL);
}

void	move_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *cheapest_node;

	cheapest_node = get_cheapest(*stack_a);
	rotate_both(stack_a, stack_b, cheapest_node);
	finish_rotation(stack_a, stack_b, cheapest_node);
	pb(stack_a, stack_b);
}

void	set_target_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp_a = *stack_a;
	t_stack *target_node;
	int	best_index =INT_MAX;
	int		size_stack_a = stack_size(*stack_a);
	int	i = 0;

	while (i < size_stack_a)
	{
		if (temp_a->index > (*stack_b)->index && temp_a->index < best_index)
		{
			target_node = temp_a;
			best_index = temp_a->index;
		}
		i++;
		temp_a = temp_a->next;
	}
	if (best_index == INT_MAX)
		(*stack_b)->target_node = find_min_stack(*stack_a);
	else
		(*stack_b)->target_node = target_node;
}


void	finish_rotation_only_a(t_stack **stack_a, t_stack *target_node)
{
	t_stack *temp = *stack_a;

	while (*stack_a!= target_node)
	{
		if (target_node->above_median == 1)
			ra(stack_a);
		else
			rra(stack_a);
		temp = temp->next;
	}
}

void	move_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	finish_rotation_only_a(stack_a, (*stack_b)->target_node);
	pa(stack_a, stack_b);
}