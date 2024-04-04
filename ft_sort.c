/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoval <kkoval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:07:53 by kkoval            #+#    #+#             */
/*   Updated: 2024/04/04 18:12:09 by kkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_send_digb(t_list **s_a, t_list **s_b, int div)
{
	int	len;

	len = ft_stack_len(*s_a);
	while (len > 0 && !is_sorted(*s_a))
	{
		if (ft_div((*s_a)->num, div) == 0)
			ft_do_push(s_a, s_b, 'b');
		else
			ft_do_rotate(s_a, 'a');
		len--;
	}
}

void	ft_send_diga(t_list **s_a, t_list **s_b, int div)
{
	int	len;

	len = ft_stack_len(*s_b);
	while (len > 0 && !is_sorted(*s_a))
	{
		if (ft_div((*s_b)->num, div) == 1)
			ft_do_push(s_b, s_a, 'b');
		else
			ft_do_rotate(s_b, 'b');
		len--;
	}
}

void	pos_stack(t_list *stack)
{
	int		min;
	t_list	*first;

	min = 0;
	first = stack;
	while (stack != NULL)
	{
		if (stack->num < min)
			min = stack->num;
		stack = stack->next;
	}
	add_stack(first, -min);
}

void	add_stack(t_list *stack, int n)
{
	while (stack != NULL)
	{
		stack->num += n;
		stack = stack->next;
	}
}
