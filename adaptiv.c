/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptiv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalsaleh <yalsaleh@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 11:18:36 by yalsaleh          #+#    #+#             */
/*   Updated: 2026/02/01 11:25:45 by yalsaleh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive(t_list **stack_a, t_list **stack_b)
{
	float	dis;

	dis = disorder(stack_a);
	if (dis < 0.2)
		bubble_sort(stack_a);
	else if (dis >= 0.2 && dis < 0.5)
		chunk_sort(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}
