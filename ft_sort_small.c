/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoval <kkoval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:44:00 by kkoval            #+#    #+#             */
/*   Updated: 2024/04/26 13:03:59 by kkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// sorts stack with 2 and 3 cases
int	ft_sort_three(t_list **stack_a)
{
	int	max_i;

	if (is_sorted(*stack_a))
		return (1);
	max_i = get_max_ind(*stack_a);
	if (max_i == 0)
		ft_do_rotate(stack_a, 'a');
	if (max_i == 1)
		ft_do_rev_rotate(stack_a, 'a');
	if ((*stack_a)->num > (*stack_a)->next->num)
		ft_do_swap(*stack_a, 'a');
	return (1);
}

// it finds the index of the highest number of the stack
int	get_max_ind(t_list *stack)
{
	int				i;
	int				max_i;
	long long int	max;

	i = 0;
	max_i = 0;
	max = stack->num;
	while (stack != NULL)
	{
		if (max < stack->num)
		{
			max = stack->num;
			max_i = i;
		}
		i++;
		stack = stack->next;
	}
	return (max_i);
}

// it finds the index of the lowest number of the stack
int	get_min_ind(t_list *stack)
{
	int	i;
	int	min_i;
	int	min;

	i = 1;
	min_i = 1;
	min = stack->num;
	while (stack != NULL)
	{
		if (min > stack->num)
		{
			min = stack->num;
			min_i = i;
		}
		i++;
		stack = stack->next;
	}
	return (min_i);
}

// in order to sort 4 cases in less movements, it pushes the lowest number
// to stack_b, in case of 5, it repeats the same action. Stack_a is then 
// sorted with ft_sort_three. The elements from stack_b then pushed back to a
int	ft_sort_five(t_list **stack_a, t_list **stack_b)
{
	int	min;
	int	len;

	len = ft_stack_len(*stack_a);
	min = get_min_ind(*stack_a);
	if (min == 1 || min == 2 || min == 3)
		while (min-- != 1)
			ft_do_rotate(stack_a, 'a');
	else
		while (min++ <= len)
			ft_do_rev_rotate(stack_a, 'a');
	ft_do_push(stack_a, stack_b, 'b');
	min = get_min_ind(*stack_a);
	len = ft_stack_len(*stack_a);
	if (min == 2)
		ft_do_rotate(stack_a, 'a');
	else
		while (min++ <= len)
			ft_do_rev_rotate(stack_a, 'a');
	ft_do_push(stack_a, stack_b, 'b');
	ft_sort_three(stack_a);
	ft_do_push(stack_b, stack_a, 'a');
	ft_do_push(stack_b, stack_a, 'a');
	return (1);
}
