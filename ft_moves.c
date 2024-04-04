/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoval <kkoval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:45:02 by kkoval            #+#    #+#             */
/*   Updated: 2024/04/04 17:48:49 by kkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_swap(t_list *stack)
{
	int	aux_n;

	if (stack == NULL || stack->next == NULL)
		return ;
	aux_n = stack->num;
	stack->num = (stack->next)->num;
	stack->next->num = aux_n;
}

void	ft_push(t_list **src, t_list **dst)
{
	t_list	*push_elm;

	if (*src == NULL)
		return ;
	push_elm = *src;
	if ((*src)->next == NULL)
		*src = NULL;
	else
		*src = (*src)->next;
	if (*dst == NULL)
	{
		push_elm->next = NULL;
		*dst = push_elm;
	}
	else
	{
		push_elm->next = *dst;
		*dst = push_elm;
	}
}

void	ft_rotate(t_list **stack)
{
	t_list	*aux;
	t_list	*first;

	aux = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = (*stack)->next;
	while ((*stack)->next != NULL)
	{
		*stack = (*stack)->next;
	}
	(*stack)->next = aux;
	aux->next = NULL;
	*stack = first;
}

void	ft_rev_rotate(t_list **stack)
{
	t_list	*aux;
	t_list	*first;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	while ((*stack)->next != NULL)
	{
		aux = (*stack);
		*stack = (*stack)->next;
	}
	aux->next = NULL;
	(*stack)->next = first;
}
