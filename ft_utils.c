/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoval <kkoval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:39:03 by kkoval            #+#    #+#             */
/*   Updated: 2024/05/06 18:51:11 by kkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// it gets every position of an integer (8 bits) and converts it to 0 or 1
// the div will in the range of 1 to 128, it could be done with bitwise operation
// instead 
long long int	ft_div(long long int num, int div)
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
