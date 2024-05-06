/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoval <kkoval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:49:22 by kkoval            #+#    #+#             */
/*   Updated: 2024/04/26 12:46:16 by kkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_do_swap(t_list *stack, char mode)
{
	ft_swap(stack);
	if (mode == 'a')
		write(1, "sa\n", 3);
	else if (mode == 'b')
		write(1, "sb\n", 3);
}

void	ft_do_push(t_list **src, t_list **dst, char mode)
{
	ft_push(src, dst);
	if (mode == 'a')
		write(1, "pa\n", 3);
	else if (mode == 'b')
		write(1, "pb\n", 3);
}

void	ft_do_rotate(t_list **stack, char mode)
{
	ft_rotate(stack);
	if (mode == 'a')
		write(1, "ra\n", 3);
	else if (mode == 'b')
		write(1, "rb\n", 3);
}

void	ft_do_rev_rotate(t_list **stack, char mode)
{
	ft_rev_rotate(stack);
	if (mode == 'a')
		write(1, "rra\n", 4);
	else if (mode == 'b')
		write(1, "rrb\n", 4);
}
