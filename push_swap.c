/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahel <hayat.ahel@learner.42.tech>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 15:20:42 by hahel             #+#    #+#             */
/*   Updated: 2026/02/04 15:27:12 by yalsaleh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		insert(char *num, t_list **stack_a);

void	error(t_list **stack_a);

void	split_insert(char *arg, t_list **stack_a);

int		word_checker(char *word);

int	main(int ac, char **av)
{
	float	dis;
	int		bench;
	int		mode;
	t_list	*stack_a;
	t_list	*stack_b;

	bench = 0;
	mode = 4;
	stack_a = NULL;
	if (ac <= 1)
		exit(EXIT_FAILURE);
	general_checker(av, &stack_a, &mode, &bench);
	dis = disorder(&stack_a);
	if (mode == 1 && dis > 0)
		bubble_sort(&stack_a);
	else if (mode == 2 && dis > 0)
		chunk_sort(&stack_a, &stack_b);
	else if (mode == 3 && dis > 0)
		radix_sort(&stack_a, &stack_b);
	else if (mode == 4 && dis > 0)
		adaptive(&stack_a, &stack_b);
	if (bench == 1)
		bench_(mode, dis);
	return (ft_lstclear(&stack_a), ft_lstclear(&stack_b), 0);
}

void	split_insert(char *arg, t_list **stack_a)
{
	char	**words;
	int		w;

	words = ft_split(arg, ' ');
	w = 0;
	while (words[w])
		insert(words[w++], stack_a);
}

int	insert(char *num, t_list **stack_a)
{
	t_list	*temp;
	long	*n;

	n = (long *)malloc(sizeof(long));
	if (!n)
		error(stack_a);
	*n = ft_atoi(num);
	if (*n < -2147483648 || *n > 2147483647)
		return (free(n), error(stack_a), 0);
	temp = *stack_a;
	while (temp != NULL)
	{
		if (temp->content == (int)(*n))
			return (free(n), error(stack_a), 0);
		temp = temp->next;
	}
	temp = ft_lstnew((int)(*n));
	if (!temp)
		error(stack_a);
	free(n);
	ft_lstadd_back(stack_a, temp);
	return (0);
}

int	word_checker(char *word)
{
	int	i;
	int	space;

	i = 0;
	space = 0;
	while (word[i])
	{
		if (!ft_isdigit(word[i]) && word[i] == ' ' )
			space = 1;
		else if (!ft_isdigit(word[i]) && ((word[i] == '-' || word[i] == '+')
				&& ft_isdigit(word[i + 1])))
			;
		else if (!ft_isdigit(word[i]) && word[i] != ' ')
			return (2);
		i++;
	}
	if (space)
		return (1);
	return (0);
}

void	error(t_list **stack_a)
{
	ft_lstclear(stack_a);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
