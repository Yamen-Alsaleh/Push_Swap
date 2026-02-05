/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_ops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahel <hayat.ahel@learner.42.tech>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 00:24:46 by hahel             #+#    #+#             */
/*   Updated: 2026/02/02 13:55:48 by yalsaleh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_b(t_list **stack_b)
{
	t_list	*temp;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	else
	{
		temp = (*stack_b);
		*stack_b = (*stack_b)->next;
		temp->next = (*stack_b)->next;
		temp->prev = (*stack_b);
		(*stack_b)->prev = NULL;
		(*stack_b)->next->prev = temp;
		(*stack_b)->next = temp;
	}
	bench_count_b(1);
	write(1, "sb\n", 3);
}

void	push_b(t_list **stack_b, t_list **stack_a)
{
	t_list	*temp;

	if (!stack_a || !*stack_a || ft_lstsize(*stack_a) < 1)
		return ;
	else
	{
		temp = (*stack_a);
		(*stack_a) = (*stack_a)->next;
		if (*stack_a)
			(*stack_a)->prev = NULL;
		temp->next = (*stack_b);
		if (*stack_b)
			(*stack_b)->prev = temp;
		(*stack_b) = temp;
	}
	bench_count_b(2);
	write(1, "pb\n", 3);
}

void	rotate_b(t_list **stack_b)
{
	t_list	*t;
	t_list	*temp;

	if (ft_lstsize(*stack_b) <= 1)
		return ;
	else
	{
		temp = (*stack_b);
		*stack_b = (*stack_b)->next;
		(*stack_b)->prev = NULL;
		t = ft_lstlast(*stack_b);
		t->next = temp;
		temp->prev = t;
		temp->next = NULL;
	}
	bench_count_b(3);
	write(1, "rb\n", 3);
}

void	revers_rotate_b(t_list **stack_b)
{
	t_list	*last;
	t_list	*temp;

	if (ft_lstsize(*stack_b) <= 1)
		return ;
	else
	{
		temp = (*stack_b);
		last = ft_lstlast(*stack_b);
		last->prev->next = NULL;
		last->prev = NULL;
		last->next = temp;
		temp->prev = last;
		(*stack_b) = last;
	}
	bench_count_b(4);
	write(1, "rrb\n", 4);
}
