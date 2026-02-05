/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahel <hayat.ahel@learner.42.tech>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 17:28:09 by hahel             #+#    #+#             */
/*   Updated: 2026/01/30 16:04:30 by yalsaleh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	chunk_sort(t_list **stack_a, t_list **stack_b);

int		ft_sqrt(t_list **stack_a);

void	sort_and_push(t_list **stack_b, t_list **stack_a);

void	find_and_ra(t_list **stack, int index);

int		in_range(int max, int min, t_list **stack_a);

int	ft_sqrt(t_list **stack_a)
{
	int	size;
	int	i;

	size = ft_lstsize(*stack_a);
	i = 1;
	while (i * i <= size)
		i++;
	return (i - 1);
}

void	chunk_sort(t_list **stack_a, t_list **stack_b)
{
	const int	chunk_size = ft_sqrt(stack_a);
	int			c;
	int			min;
	int			max;
	int			index;

	c = 0;
	min = 1;
	max = chunk_size;
	fill_index(stack_a);
	while (c <= chunk_size)
	{
		while (in_range(max, min, stack_a) != 0)
		{
			index = in_range(max, min, stack_a);
			find_and_ra(stack_a, index);
			push_b(stack_b, stack_a);
		}
		min = min + chunk_size;
		max = max + chunk_size;
		c++;
	}
	sort_and_push(stack_b, stack_a);
}

int	in_range(int max, int min, t_list **stack_a)
{
	t_list	*temp;

	temp = (*stack_a);
	while (temp)
	{
		if (temp->index >= min && temp->index <= max)
			return (temp->index);
		temp = temp->next;
	}
	return (0);
}

void	find_and_ra(t_list **stack_a, int index)
{
	int	size;
	int	ra;
	int	rra;

	size = ft_lstsize(*stack_a);
	ra = pos(stack_a, index);
	rra = size - pos(stack_a, index);
	if (ra <= rra)
	{
		while (--ra)
			rotate_a(stack_a);
	}
	else
	{
		rra++;
		while (rra--)
			revers_rotate_a(stack_a);
	}
}

void	find_and_rb(t_list **stack, int index)
{
	int	size;
	int	rb;
	int	rrb;

	size = ft_lstsize(*stack);
	rb = pos(stack, index);
	rrb = size - pos(stack, index);
	if (rb <= rrb)
	{
		while (--rb)
			rotate_b(stack);
	}
	else
	{
		rrb++;
		while (rrb--)
			revers_rotate_b(stack);
	}
}
