/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoval <kkoval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:12:34 by kkoval            #+#    #+#             */
/*   Updated: 2024/04/04 18:18:39 by kkoval           ###   ########.fr       */
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

int	ft_free_int(int *ptr, int flag)
{
	free(ptr);
	return (flag);
}

int	ft_div(int num, int div)
{
	return (num / div % 2);
}

int	ft_stack_len(t_list *stack)
{
	int	len;

	len = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}
