#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_list
{
	long int		num;
	struct s_list	*next;
} t_list;

//Algorithm

void    ft_send_digb(t_list **s_a, t_list **s_b, int div);
void    ft_send_diga(t_list **s_a, t_list **s_b, int div);
void    pos_stack(t_list *stack);
void    add_stack(t_list *stack, int n);

//Algorithm for 2 to 5 numbers
int 	get_min_ind(t_list *stack);
int 	get_max_ind(t_list *stack);
int		ft_sort_three(t_list **stack_a);
int		ft_sort_five(t_list **stack_a, t_list **stack_b);


//Check input for all necessary parameters
int			ft_check_input(int argc, char **argv);
int			ft_check_int(int argc, char **argv);
long int	ft_atoi(char *str);
int			ft_check_duplicate(int *arr, size_t len);
int			ft_check_limits(long int);

//Stack fill and debug
int			fill_stack(t_list **current, int argc, char **argv);
int			ft_radix(t_list **stack_a, t_list **stack_b);
//void		print_stack(t_list *stack); //temporary
int			is_sorted(t_list *stack);
int			ft_sort(t_list **stack_a, t_list **stack_b, int argc);

//Stack moves
void 		ft_swap(t_list *stack);
void		ft_push(t_list **stack_a, t_list **stack_b);
void		ft_rotate(t_list **stack);
void		ft_rev_rotate(t_list **stack);

//Do single moves
void		ft_do_swap(t_list *stack, char mode);
void    	ft_do_push(t_list **src, t_list **dst, char mode);
void    	ft_do_rotate(t_list **stack, char mode);
void    	ft_do_rev_rotate(t_list **stack, char mode);


//Do pair moves
void		ft_swap_ab(t_list *stack_a, t_list *stack_b);
void		ft_rotate_ab(t_list **stack_a, t_list **stack_b);
void    	ft_rev_rot_ab(t_list **stack_a, t_list **stack_b);

//Utils
int			ft_error(void);
int			ft_stack_len(t_list *stack);
int			ft_div(int num, int div);
int			ft_error_free(t_list **stack_a, t_list **stack_b);
void		ft_free(t_list **stack);



#endif
