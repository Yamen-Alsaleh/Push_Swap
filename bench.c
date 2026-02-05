/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahel <hahel@learner.42.tech>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 17:28:53 by hahel             #+#    #+#             */
/*   Updated: 2026/02/02 20:56:15 by yalsaleh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bench_(int mode, float dis)
{
	print_disorder(dis);
	write(2, "\n", 1);
	print_strategy(dis, mode);
	write(2, "\n", 1);
	print_total_ops();
	write(2, "\n", 1);
	print_ops();
}

void	print_disorder(float dis)
{
	int		dis2;
	char	digit;
	int		num;
	int		i;

	write(2, "[bench] disorder : ", 19);
	dis2 = (int)(dis * 10000);
	num = 0;
	i = 1000;
	if (dis == 1)
		write(2, "100%", 4);
	else
	{
		while (num < 4)
		{
			digit = ((dis2 / i) % 10) + '0';
			write(2, &digit, 1);
			if (num == 1)
				write(2, ".", 1);
			num++;
			i /= 10;
		}
	}
	write(2, "%", 1);
}

void	print_strategy(float dis, int mode)
{
	write(2, "[bench] strategy : ", 20);
	if (mode == 1)
		write(2, "simple (O(n^2))", 15);
	else if (mode == 2)
		write(2, "medium (O(n√n)", 16);
	else if (mode == 3)
		write(2, "complex (O(nlogn)", 17);
	else
	{
		write(2, "adaptive ", 9);
		if (dis < 0.2)
			write(2, "(O(n))", 6);
		else if (dis >= 0.2 && dis < 0.5)
			write(2, "(O(n√n))", 9);
		else
			write(2, "(O(nlogn))", 10);
	}
}

void	print_total_ops(void)
{
	int	total;

	total = bench_count_a(0) + bench_count_b(0);
	write(2, "[bench] total operations : ", 27);
	ft_putnbr_fd(total, 2);
}

void	print_ops(void)
{
	write(2, "[bench] sa : ", 13);
	ft_putnbr_fd(bench_count_a(-1), 2);
	write(2, " sb : ", 6);
	ft_putnbr_fd(bench_count_b(-1), 2);
	write(2, " ss : 0", 7);
	write(2, " pa : ", 6);
	ft_putnbr_fd(bench_count_a(-2), 2);
	write(2, " pb : ", 6);
	ft_putnbr_fd(bench_count_b(-2), 2);
	write(2, "\n[bench] ra : ", 14);
	ft_putnbr_fd(bench_count_a(-3), 2);
	write(2, " rb : ", 6);
	ft_putnbr_fd(bench_count_b(-3), 2);
	write(2, " rr : 0", 7);
	write(2, " rra : ", 7);
	ft_putnbr_fd(bench_count_a(-4), 2);
	write(2, " rrb : ", 7);
	ft_putnbr_fd(bench_count_b(-4), 2);
	write(2, "\n", 1);
}
