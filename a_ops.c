/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_ops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalsaleh <yalsaleh@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:11:21 by yalsaleh          #+#    #+#             */
/*   Updated: 2026/02/02 13:55:28 by yalsaleh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list **stack_a)
{
	t_list	*temp;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	else
	{
		temp = (*stack_a);
		*stack_a = (*stack_a)->next;
		temp->next = (*stack_a)->next;
		temp->prev = (*stack_a);
		(*stack_a)->prev = NULL;
		(*stack_a)->next->prev = temp;
		(*stack_a)->next = temp;
	}
	bench_count_a(1);
	write(1, "sa\n", 3);
}

void	push_a(t_list **stack_b, t_list **stack_a)
{
	t_list	*temp;

	if (!stack_b || !*stack_b || ft_lstsize(*stack_b) < 1)
		return ;
	else
	{
		temp = (*stack_b);
		(*stack_b) = (*stack_b)->next;
		if (*stack_b)
			(*stack_b)->prev = NULL;
		temp->next = (*stack_a);
		if (*stack_a)
			(*stack_a)->prev = temp;
		(*stack_a) = temp;
	}
	bench_count_a(2);
	write(1, "pa\n", 3);
}

void	rotate_a(t_list **stack_a)
{
	t_list	*t;
	t_list	*temp;

	if (ft_lstsize(*stack_a) <= 1)
		return ;
	else
	{
		temp = (*stack_a);
		*stack_a = (*stack_a)->next;
		(*stack_a)->prev = NULL;
		t = ft_lstlast(*stack_a);
		t->next = temp;
		temp->prev = t;
		temp->next = NULL;
	}
	bench_count_a(3);
	write(1, "ra\n", 3);
}

void	revers_rotate_a(t_list **stack_a)
{
	t_list	*last;
	t_list	*temp;

	if (ft_lstsize(*stack_a) <= 1)
		return ;
	else
	{
		temp = (*stack_a);
		last = ft_lstlast(*stack_a);
		last->prev->next = NULL;
		last->prev = NULL;
		last->next = temp;
		temp->prev = last;
		(*stack_a) = last;
	}
	bench_count_a(4);
	write(1, "rra\n", 4);
}
