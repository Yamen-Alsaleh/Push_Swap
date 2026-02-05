/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahel <hahel@learner.42.tech>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 16:15:15 by hahel             #+#    #+#             */
/*   Updated: 2026/02/02 13:33:03 by yalsaleh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bench_count_a(int i)
{
	static int	s;
	static int	p;
	static int	r;
	static int	rr;

	if (i == 0)
		return (s + p + r + rr);
	else if (i == 1)
		return (s++);
	else if (i == 2)
		return (p++);
	else if (i == 3)
		return (r++);
	else if (i == 4)
		return (rr++);
	else if (i == -1)
		return (s);
	else if (i == -2)
		return (p);
	else if (i == -3)
		return (r);
	else if (i == -4)
		return (rr);
	return (0);
}

int	bench_count_b(int i)
{
	static int	s;
	static int	p;
	static int	r;
	static int	rr;

	if (i == 0)
		return (s + p + r + rr);
	else if (i == 1)
		return (s++);
	else if (i == 2)
		return (p++);
	else if (i == 3)
		return (r++);
	else if (i == 4)
		return (rr++);
	else if (i == -1)
		return (s);
	else if (i == -2)
		return (p);
	else if (i == -3)
		return (r);
	else if (i == -4)
		return (rr);
	return (0);
}
