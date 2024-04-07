/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoval <kkoval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:40:17 by kkoval            #+#    #+#             */
/*   Updated: 2024/04/05 13:40:23 by kkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_error(void)
{
	write(2, "Error\n", 6);
	return (0);
}

void	ft_free(t_list **stack)
{
	t_list	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	stack = NULL;
}

int	ft_error_free(t_list **stack_a, t_list **stack_b)
{
	ft_free(stack_a);
	ft_free(stack_b);
	return (1);
}

int	ft_free_int(long long int *ptr, int flag)
{
	free(ptr);
	return (flag);
}