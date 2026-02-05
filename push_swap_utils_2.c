/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalsaleh <yalsaleh@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 15:51:04 by yalsaleh          #+#    #+#             */
/*   Updated: 2026/02/02 12:59:23 by hahel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_and_push(t_list **stack_b, t_list **stack_a);

void	sort_and_push(t_list **stack_b, t_list **stack_a)
{
	t_list		*temp;
	t_list		*max;
	int			i;
	const int	size = ft_lstsize(*stack_b);

	i = 0;
	while (i < size)
	{
		temp = (*stack_b);
		max = (*stack_b);
		while (temp)
		{
			if (temp->index > max->index)
				max = temp;
			temp = temp->next;
		}
		find_and_rb(stack_b, max->index);
		push_a(stack_b, stack_a);
		i++;
	}
}
