#include "push_swap.h"

void	ft_lstadd_back_stack(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		new->next = new;
		new->prev = new;
		return ;
	}
	last = (*lst)->prev;
	last->next = new;
	new->prev = last;
	new->next = *lst;
	(*lst)->prev = new;
}

t_stack	*ft_lstnew_stack(int nbr)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->nbr = nbr;
	new->index = -1;
	new->pos = -1;
	new->cheapest = 0;
	new->target_node = NULL;
	new->next = new;
	new->prev = new;
	return (new);
}

int		stack_size(t_stack *stack)
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
	size = stack_size(stack);
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

t_stack *find_max_stack(t_stack *stack)
{
	t_stack *temp = stack;
	int max = INT_MIN;
	int	len = stack_size(stack);
	int	i = 0;
	t_stack *max_node;

	while (i < len)
	{
		if (temp->index > max)
		{
			max = temp->index;
			max_node = temp;
		}
		temp = temp->next;
		i++;
	}
	return (max_node);
	
}

void	set_target_a_to_b(t_stack *stack_a, t_stack *stack_b)
{
	long	size_stack_a = stack_size(stack_a);
	long	size_stack_b = stack_size(stack_b);
	long	i = 0;
	long	j = 0;
	t_stack *temp_a = stack_a;
	t_stack	*temp_b = stack_b;
	long	best_match_index = LONG_MIN;
	t_stack	*target_node;

	while ( i < size_stack_a)
	{
		j = 0;
		temp_b = stack_b;
		while (j < size_stack_b)
		{
			if (temp_b->index < temp_a->index && temp_b->index > best_match_index)
			{
				target_node = temp_b;
				best_match_index = temp_b->index;
			}
			j++;
			temp_b = temp_b -> next;
		}
		if (best_match_index == LONG_MIN)
			temp_a->target_node = find_max_stack(stack_b);
		else
			temp_a->target_node = target_node;
		i++;
		temp_a = temp_a->next;
	}
}

void	set_cost(t_stack *stack_a, t_stack *stack_b)
{
	int	size_stack_a = stack_size(stack_a);
	int	size_stack_b = stack_size(stack_b);
	int	i = 0;
	t_stack *temp_a = stack_a;
	t_stack *temp_b = stack_b;

	while (i < size_stack_a)
	{
		if (temp_a->above_median  == 1)
			temp_a->cost_a = temp_a->pos;
		else
			temp_a->cost_a = -(size_stack_b - temp_a->target_node->pos);
		if (temp_b->above_median == 1)
			temp_a->cost_b = temp_a->target_node->pos;
		else
			temp_a->cost_b = -(size_stack_b - temp_a->target_node->pos);	
		temp_a = temp_a->next;
	}
}

int abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int max_abs(int a, int b)
{
	if (abs(a) > abs(b))
		return (abs(a));
	return (abs(b));
}
void	set_cheapest(t_stack *stack_a)
{
	int size_stack_a = stack_size(stack_a);
	int	i = 0;
	int	lowest_cost = 0;
	t_stack	*temp_a;
	int 	current_cost;
	t_stack *best_node;

	if (!stack_a)
		return ;
	lowest_cost = INT_MAX;
	temp_a = stack_a;
	while (i < size_stack_a)
	{
		if (temp_a->cost_a > 0 && temp_a->cost_b > 0)
			current_cost = max(temp_a->cost_a, temp_a->cost_b);
		else if (temp_a->cost_a < 0 && temp_a->cost_b < 0)
			current_cost = max_abs(temp_a->cost_a, temp_a->cost_b);
		else
			current_cost = abs(temp_a->cost_a) + abs(temp_a->cost_b);
		if (current_cost < lowest_cost)
		{

			lowest_cost = current_cost;
			best_node = temp_a;
		}
		temp_a = temp_a->next;
		i++;
	}
	best_node->cheapest = 1;
}

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

t_stack *get_cheapest(t_stack *stack)
{
	while (stack)
	{
		if(stack->cheapest == 1)
			return (stack);
		stack = stack->next;
	}
	return(NULL);
}

void	move_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *cheapest_node;

	cheapest_node = get_cheapest(*stack_a);
	rotate_both(stack_a, stack_b, cheapest_node);
	finish_rotation(stack_a, stack_b, cheapest_node);
	pb(stack_a, stack_b);
}

t_stack *find_min_stack(t_stack *stack)
{
	t_stack *temp = stack;
	int min = INT_MAX;
	int	len = stack_size(stack);
	int	i = 0;
	t_stack *min_node;

	while (i < len)
	{
		if (temp->index < min)
		{
			min = temp->index;
			min_node = temp;
		}
		temp = temp->next;
		i++;
	}
	return (min_node);
	
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
		temp_a->target_node = find_min_stack(*stack_a);
	else
		temp_a->target_node = target_node;
}


void	finish_rotation_only_a(t_stack **stack_a, t_stack *target_node)
{
	t_stack *temp = *stack_a;

	while (temp->target_node != target_node)
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

int	is_sorted(t_stack *stack)
{
	t_stack *temp = stack;
	int	size_stack = stack_size(stack);

	while (--size_stack > 0)
	{
		if (temp->index > temp->next->index)
			return (0);
		temp = temp->next;
	}
	return(1);
}

void	init_nodes_a(t_stack *stack_a, t_stack *stack_b)
{
	set_position(stack_a);
	set_position(stack_b);
	set_target_a_to_b(stack_a, stack_b);
	set_cost(stack_a, stack_b);
	set_cheapest(stack_a);
}

void	init_nodes_b(t_stack *stack_a, t_stack *stack_b)
{
	set_position(stack_a);
	set_position(stack_b);
	set_target_b_to_a(&stack_a, &stack_b);
}

void	min_on_top(t_stack **a)
{
	t_stack	*min_node;
	int		size;

	if (!a || !*a)
		return ;
	min_node = find_min_stack(*a);
	size = stack_size(*a);
	set_position(*a); 
	while ((*a)->index != min_node->index)
	{
		if (min_node->above_median)
			ra(a);
		else
			rra(a);
	}
}

void	sort_stacks(t_stack **stack_a, t_stack **stack_b)
{
	int 	len_a;

	len_a = stack_size(*stack_a);
	if (len_a-- > 3 && is_sorted(*stack_a) == 0)
		pb(stack_a, stack_b);
	if (len_a-- > 3 && is_sorted(*stack_a) == 0)
		pb (stack_a, stack_b);
	while (len_a-- > 3 && is_sorted(*stack_a) == 0)
	{
		init_nodes_a(*stack_a, *stack_b);
		move_a_to_b(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		init_nodes_b(*stack_a, *stack_b);
		move_b_to_a(stack_a, stack_b);
	}
	set_position(*stack_a);
	min_on_top(stack_a);
}
