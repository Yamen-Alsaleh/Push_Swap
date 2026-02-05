/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahel <hayat.ahel@learner.42.tech>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 19:32:41 by hahel             #+#    #+#             */
/*   Updated: 2026/02/04 15:25:40 by yalsaleh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
/************************** B Operations **************************/
void	swap_b(t_list **stack_b);
void	revers_rotate_b(t_list **stack_b);
void	rotate_b(t_list **stack_b);
void	push_b(t_list **stack_b, t_list **stack_a);
/************************** A Operations **************************/
void	swap_a(t_list **stack_a);
void	revers_rotate_a(t_list **stack_a);
void	rotate_a(t_list **stack_a);
void	push_a(t_list **stack_b, t_list **stack_a);
/************************** Push_Swap.c **************************/
void	split_insert(char *arg, t_list **stack_a);
int		insert(char *num, t_list **stack_a);
int		word_checker(char *word);
void	error(t_list **stack_a);
/************************** Push_Swap_Utils_1.c **************************/
int		flag_check(char *flag);
float	disorder(t_list **stack_a);
void	general_checker(char **av, t_list **stack_a, int *mode, int *bench);
void	fill_index(t_list **stack_a);
int		pos(t_list **stack, int index);
/************************** Push_Swap_Utils_2.c **************************/
void	sort_and_push(t_list **stack_b, t_list **stack_a);
/************************** Bench.c **************************/
void	bench_(int mode, float dis);
void	print_disorder(float dis);
void	print_strategy(float dis, int mode);
void	print_total_ops(void);
void	print_ops(void);
/************************** Bench_Utils.c **************************/
int		bench_count_a(int i);
int		bench_count_b(int i);
/************************** Simple.c **************************/
void	bubble_sort(t_list **stack_a);
/************************** Medium.c **************************/
void	chunk_sort(t_list **stack_a, t_list **stack_b);
int		ft_sqrt(t_list **stack_a);
void	find_and_ra(t_list **stack, int index);
int		in_range(int max, int min, t_list **stack_a);
void	find_and_rb(t_list **stack, int index);
/************************** Complex.c **************************/
void	radix_sort(t_list **stack_a, t_list **stack_b);
int		get_max(t_list **stack_a);
/************************** Adaptiv.c **************************/
void	adaptive(t_list **stack_a, t_list **stack_b);

#endif
