/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalsaleh <yalsaleh@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:41:02 by yalsaleh          #+#    #+#             */
/*   Updated: 2026/02/02 17:03:31 by yalsaleh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	general_checker(char **av, t_list **stack_a, int *mode, int *bench);

int		flag_check(char *flag);

float	disorder(t_list **stack_a);

void	fill_index(t_list **stack_a);

int		pos(t_list **stack, int index);

int	pos(t_list **stack, int index)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = (*stack);
	while (temp)
	{
		i++;
		if (temp->index == index)
			return (i);
		temp = temp->next;
	}
	return (0);
}

void	fill_index(t_list **stack_a)
{
	t_list	*min;
	t_list	*temp;
	int		i;

	i = 1;
	while (i <= ft_lstsize(*stack_a))
	{
		temp = (*stack_a);
		while (temp->index != 0 && temp)
			temp = temp->next;
		min = temp;
		temp = (*stack_a);
		while (temp)
		{
			if (temp->content <= min->content && temp->index == 0)
				min = temp;
			temp = temp->next;
		}
		min->index = i++;
	}
}

void	general_checker(char **av, t_list **stack_a, int *mode, int *bench)
{
	int	w;

	w = 1;
	while (av[w])
	{
		if (flag_check(av[w]) && w <= 2)
			*mode = flag_check(av[w]);
		else if (!ft_strncmp(av[w], "--bench", sizeof("--bench")) && w == 1)
			*bench = 1;
		else if (!word_checker(av[w]))
			insert(av[w], stack_a);
		else if (word_checker(av[w]) == 1)
			split_insert(av[w], stack_a);
		else
			error(stack_a);
		w++;
	}
}

int	flag_check(char *flag)
{
	if (!ft_strncmp(flag, "--simple", sizeof("--simple")))
		return (1);
	if (!ft_strncmp(flag, "--medium", sizeof("--medium")))
		return (2);
	if (!ft_strncmp(flag, "--complex", sizeof("--complex")))
		return (3);
	if (!ft_strncmp(flag, "--adaptive", sizeof("--adaptive")))
		return (4);
	return (0);
}

float	disorder(t_list **stack_a)
{
	float	disordered;
	float	tpairs;
	t_list	*i;
	t_list	*j;

	disordered = 0;
	tpairs = 0;
	i = *stack_a;
	while (i && i->next)
	{
		j = i->next;
		while (j)
		{
			tpairs += 1;
			if (i->content > j->content)
				disordered++;
			j = j->next;
		}
		i = i->next;
	}
	return (disordered / tpairs);
}
