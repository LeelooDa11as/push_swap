/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoval <kkoval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:43:18 by kkoval            #+#    #+#             */
/*   Updated: 2024/04/06 20:35:03 by kkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	fill_stack(t_list **current, int argc, char **argv)
{
	t_list	*follow;
	t_list	*first;
	int		i;

	i = 2;
	*current = malloc(sizeof(t_list));
	if (!current)
		return (0);
	(*current)->num = (long long int)ft_atoi(argv[1]);
	(*current)->next = NULL;
	first = *current;
	while (i < argc)
	{
		follow = malloc(sizeof(t_list));
		if (!follow)
			return (0);
		follow->num = (int)ft_atoi(argv[i]);
		follow->next = NULL;
		(*current)->next = follow;
		*current = follow;
		i++;
	}
	*current = first;
	return (1);
}

int	is_sorted(t_list *stack)
{
	while (stack != NULL && stack->next != NULL)
	{
		if (stack->num > stack->next->num)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	ft_sort(t_list **stack_a, t_list **stack_b, int len)
{
	if (*stack_a == NULL || *stack_b != NULL)
	{
		ft_error_free(stack_a, stack_b);
		return (0);
	}
	if (is_sorted(*stack_a) == 1)
		return (1);
	if (len == 2 || len == 3)
		return (ft_sort_three(stack_a));
	else if (len == 4 || len == 5)
		return (ft_sort_five(stack_a, stack_b));
	else
		return (ft_radix(stack_a, stack_b));
}

int	ft_radix(t_list **stack_a, t_list **stack_b)
{
	int	div;

	div = 1;
	while (!is_sorted(*stack_a))
	{
		ft_send_digb(stack_a, stack_b, div);
		while (*stack_b)
			ft_do_push(stack_b, stack_a, 'a');
		div *= 2;
	}
	while (*stack_b)
		ft_do_push(stack_b, stack_a, 'a');
	return (1);
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	if (!ft_check_input(argc, argv))
		return (ft_error());
	if (!fill_stack(&stack_a, argc, argv))
		ft_error_free(&stack_a, &stack_b);
	pos_stack(stack_a);
	if (!ft_sort(&stack_a, &stack_b, argc - 1))
		return (ft_error_free(&stack_a, &stack_b));
	ft_free(&stack_a);
	ft_free(&stack_b);
	return (1);
}
