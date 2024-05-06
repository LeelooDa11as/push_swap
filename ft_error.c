/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoval <kkoval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:40:17 by kkoval            #+#    #+#             */
/*   Updated: 2024/05/06 18:04:00 by kkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// message to be displayed if there is any error with received arguments or 
// with handling of the arguments and subsequent program termination
int	ft_error(void)
{
	write(2, "Error\n", 6);
	return (0);
}

// it frees all the nodes of the list and then sets stack to NULL
void	ft_free(t_list **stack)
{
	t_list	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	stack = NULL; (should it be *stack?)
}

// it frees both stacks and terminates the program in case error occuring
// with stacks during sorting
int	ft_error_free(t_list **stack_a, t_list **stack_b)
{
	ft_free(stack_a);
	ft_free(stack_b);
	return (0);
}

// it frees the int *nums in the end of ft_check_input or if any error with 
//input occurs
int	ft_free_int(long long int *ptr, int flag)
{
	free(ptr);
	return (flag);
}
