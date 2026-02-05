/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   joind_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahel <hayat.ahel@learner.42.tech>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 09:46:36 by hahel             #+#    #+#             */
/*   Updated: 2026/02/03 09:46:36 by hahel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sawp_a_and_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (!stack_a || !*stack_a || !(*stack_a)->next ||!stack_b
		|| !*stack_b || !(*stack_b)->next)
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
		temp = (*stack_b);
		*stack_b = (*stack_b)->next;
		temp->next = (*stack_b)->next;
		temp->prev = (*stack_b);
		(*stack_b)->prev = NULL;
		(*stack_b)->next->prev = temp;
		(*stack_b)->next = temp;
	}
	write(1, "ss\n", 3);
}

void	rotate_a_and_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*t;
	t_list	*temp;

	if (ft_lstsize(*stack_a) <= 1 || ft_lstsize(*stack_b) <= 1)
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
		temp = (*stack_b);
		*stack_b = (*stack_b)->next;
		(*stack_b)->prev = NULL;
		t = ft_lstlast(*stack_b);
		t->next = temp;
		temp->prev = t;
		temp->next = NULL;
	}
	write(1, "rr\n", 3);
}

void	reverse_a_and_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*last;
	t_list	*temp;

	if (ft_lstsize(*stack_a) <= 1 || ft_lstsize(*stack_b) <= 1)
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
		temp = (*stack_b);
		last = ft_lstlast(*stack_b);
		last->prev->next = NULL;
		last->prev = NULL;
		last->next = temp;
		temp->prev = last;
		(*stack_b) = last;
	}
	write(1, "rrr\n", 4);
}
