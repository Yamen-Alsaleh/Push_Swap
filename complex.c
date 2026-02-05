/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalsaleh <yalsaleh@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 19:48:56 by yalsaleh          #+#    #+#             */
/*   Updated: 2026/01/31 17:21:10 by yalsaleh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_list **stack_a, t_list **stack_b);

int		get_max(t_list **stack_a);

int	get_max(t_list **stack_a)
{
	int		count;
	int		max;
	t_list	*temp;

	count = 0;
	max = (*stack_a)->index;
	temp = (*stack_a);
	while (temp)
	{
		if (temp->index > max)
			max = temp->index;
		temp = temp->next;
	}
	while (max != 0)
	{
		max = max / 2;
		count++;
	}
	return (count);
}

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	int		size;
	int		count;
	t_list	*temp;
	int		i;

	i = 1;
	fill_index(stack_a);
	count = get_max(stack_a);
	while (count)
	{
		size = ft_lstsize(*stack_a);
		while (size)
		{
			temp = (*stack_a);
			if ((temp->index / i) % 2 == 0)
				push_b(stack_b, stack_a);
			else
				rotate_a(stack_a);
			size--;
		}
		while (*stack_b)
			push_a(stack_b, stack_a);
		i *= 2;
		count--;
	}
}
