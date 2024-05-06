/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoval <kkoval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:52:28 by kkoval            #+#    #+#             */
/*   Updated: 2024/05/06 19:08:27 by kkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_list
{
	long long int	num;
	struct s_list	*next;
}	t_list;

// ============ Input checking (ft_check_input) ================================

int				ft_check_input(int argc, char **argv);
int				ft_check_int(int argc, char **argv);
long long int	ft_atoi(char *str);
int				ft_check_duplicate(long long int *arr, size_t len);
int				ft_check_limits(long long int n);

// ============ Filling stack and sorting (ft_push_swap) =======================

int				fill_stack(t_list **current, int argc, char **argv);
int				ft_radix(t_list **stack_a, t_list **stack_b);
int				is_sorted(t_list *stack);
int				ft_sort(t_list **stack_a, t_list **stack_b, int argc);

// ============ Sorting 2 - 5 cases (ft_sort_small) ============================ 

int				get_min_ind(t_list *stack);
int				get_max_ind(t_list *stack);
int				ft_sort_three(t_list **stack_a);
int				ft_sort_five(t_list **stack_a, t_list **stack_b);

// ============ Radix functions for > 5 elements (ft_sort) ===================== 

void			ft_send_digb(t_list **stack_a, t_list **stack_b, int div);
void			ft_send_diga(t_list **s_a, t_list **s_b, int div);
void			ft_index_stack(t_list *stack);
int				ft_count_bigger(t_list *stack, int num);

// ============ Stack movements (ft_moves) =====================================

void			ft_swap(t_list *stack);
void			ft_push(t_list **stack_a, t_list **stack_b);
void			ft_rotate(t_list **stack);
void			ft_rev_rotate(t_list **stack);

// ============ Stack movements call and print (ft_do_moves) ===================

void			ft_do_swap(t_list *stack, char mode);
void			ft_do_push(t_list **src, t_list **dst, char mode);
void			ft_do_rotate(t_list **stack, char mode);
void			ft_do_rev_rotate(t_list **stack, char mode);

// ============ Util functions (ft_utils) ======================================

long long int	ft_div(long long int num, int div);
int				ft_strlen(char *str);
int				ft_stack_len(t_list *stack);

// ============ Error handling and frees (ft_error) ============================

int				ft_error(void);
int				ft_error_free(t_list **stack_a, t_list **stack_b);
void			ft_free(t_list **stack);
int				ft_free_int(long long int *ptr, int flag);

#endif
