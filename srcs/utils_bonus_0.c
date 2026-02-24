/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:19:59 by miouali           #+#    #+#             */
/*   Updated: 2026/02/23 17:20:00 by miouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	is_an_instruction(char *line)
{
	if (ft_strcmp(line, "sa") == 0)
		return (1);
	if (ft_strcmp(line, "sb") == 0)
		return (1);
	if (ft_strcmp(line, "ss") == 0)
		return (1);
	if (ft_strcmp(line, "pa") == 0)
		return (1);
	if (ft_strcmp(line, "pb") == 0)
		return (1);
	if (ft_strcmp(line, "ra") == 0)
		return (1);
	if (ft_strcmp(line, "rb") == 0)
		return (1);
	if (ft_strcmp(line, "rr") == 0)
		return (1);
	if (ft_strcmp(line, "rra") == 0)
		return (1);
	if (ft_strcmp(line, "rrb") == 0)
		return (1);
	if (ft_strcmp(line, "rrr") == 0)
		return (1);
	return (0);
}

void	execute_instruction(char *line, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(line, "sa") == 0)
		sa(*stack_a);
	if (ft_strcmp(line, "sb") == 0)
		sb(*stack_b);
	if (ft_strcmp(line, "ss") == 0)
		ss(*stack_a, *stack_b);
	if (ft_strcmp(line, "pa") == 0)
		pa(stack_a, stack_b);
	if (ft_strcmp(line, "pb") == 0)
		pb(stack_a, stack_b);
	if (ft_strcmp(line, "ra") == 0)
		ra(stack_a);
	if (ft_strcmp(line, "rb") == 0)
		rb(stack_b);
	if (ft_strcmp(line, "rr") == 0)
		rr(stack_a, stack_b);
	if (ft_strcmp(line, "rra") == 0)
		rra(stack_a);
	if (ft_strcmp(line, "rrb") == 0)
		rrb(stack_b);
	if (ft_strcmp(line, "rrr") == 0)
		rrr(stack_a, stack_b);
}

int	fetch_and_execute(char *line, t_stack **stack_a, t_stack **stack_b)
{
	line[ft_strlen(line) - 1] = '\0';
	if (is_an_instruction(line) != 1)
		return (free(line), -1);
	execute_instruction(line, stack_a, stack_b);
	free(line);
	return (0);
}

int	read_and_execute(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (fetch_and_execute(line, stack_a, stack_b) == -1)
		{
			get_next_line(-1);
			free_stacks(stack_a, stack_b);
			return (-1);
		}
		line = get_next_line(0);
	}
	get_next_line(-1);
	return (0);
}