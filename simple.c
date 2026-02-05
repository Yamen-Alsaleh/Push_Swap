/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahel <hayat.ahel@learner.42.tech>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:20:02 by hahel             #+#    #+#             */
/*   Updated: 2026/01/24 14:00:29 by yalsaleh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	bubble_sort(t_list **stack_a)
{
	int	size;
	int	swapped;
	int	i;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		size = ft_lstsize(*stack_a);
		i = 0;
		while (i < size - 1)
		{
			if ((*stack_a)->content > (*stack_a)->next->content)
			{
				swap_a(stack_a);
				swapped = 1;
			}
			rotate_a(stack_a);
			i++;
		}
		rotate_a(stack_a);
		if (swapped == 0)
			break ;
	}
}
