#include "ft_push_swap.h"

int ft_sort_three(t_list **stack_a)
{
    int     max_i;

    max_i = get_max_ind(*stack_a);
    if (max_i == 0)
        ft_do_rotate(stack_a, 'a');
    if (max_i == 1)
        ft_do_rev_rotate(stack_a, 'a');
    if ((*stack_a)->num > (*stack_a)->next->num)
        ft_do_swap(*stack_a, 'a');
    return (1);
}
/*
int ft_sort_five(t_list **stack_a, t_list **stack_b)
{
    int     min_n;
    int     min_i;
    ft_do_push(stack_a, stack_b, 'b');
    ft_do_push(stack_a, stack_b, 'b');
    ft_sort_three(stack_a);
    ft_sort_three(stack_b);
    min_n = (*stack_a)->num;
    while (*stack_b != NULL)
    {
        while ((*stack_a)->num < (*stack_b)->num && (*stack_a)->next->num != min_n)
            ft_do_rotate(stack_a, 'a');
        if ((*stack_a)->next->num == min_n)
            ft_do_rotate(stack_a, 'a');
        else if ((*stack_b)->num < min_n)
            min_n = (*stack_b)->num;
        ft_do_push(stack_b, stack_a, 'a');
    }
    if ((*stack_a)->next->num == min_n)
        ft_do_rotate(stack_a, 'a');
    while ()
    return (1);
}*/

int get_max_ind(t_list *stack)
{
    int i;
    int max_i;
    int max;

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


int get_min_ind(t_list *stack)
{
    int i;
    int min_i;
    int min;

    i = 0;
    min = stack->num;
    while (stack != NULL)
    {
        if (stack->num < min)
        {
            min = stack->num;
            min_i = i;
        }
        i++;
        stack = stack->next;
    }
    return (min_i);
}

int ft_sort_five(t_list **stack_a, t_list **stack_b)
{
    int min;
    int len;

    len = ft_stack_len(*stack_a);
    min = get_min_ind(*stack_a);
    if (min <= len/2)
        while (min-- > 0)
            ft_do_rotate(stack_a, 'a');
    else
        while (min++ < len)
            ft_do_rev_rotate(stack_a, 'a');
    ft_do_push(stack_a, stack_b, 'b');
    min = get_min_ind(*stack_a);
    if (min < 2)
        ft_do_rotate(stack_a, 'a');
    else
        while (min++ < len - 1)
            ft_do_rev_rotate(stack_a, 'a');
    ft_do_push(stack_a, stack_b, 'b');

    ft_sort_three(stack_a);
    ft_do_push(stack_b, stack_a, 'a');
    ft_do_push(stack_b, stack_a, 'a');
    return (1);
}