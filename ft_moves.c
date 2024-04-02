#include "ft_push_swap.h"

//es el algoritmo
//int do_moves(t_list	*stack, int len)

void	ft_swap(t_list *stack)
{
	int	aux_n;
	
	if (stack == NULL || stack->next == NULL)
		return;
	aux_n = stack->num;
	stack->num = (stack->next)->num;
	stack->next->num = aux_n;
}

void	ft_push(t_list **src, t_list **dst)
{
	t_list	*push_elm;
	
	if (*src == NULL)
		return;
	push_elm = *src;
	if ((*src)->next == NULL)
		*src = NULL;
	else //hace conexiones
		*src = (*src)->next;
	if (*dst == NULL)
	{
		push_elm->next = NULL;
		*dst = push_elm;
 	}
	else //hay que conectar los elementos
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
	if (*stack == NULL || (*stack)->next == NULL) //he añadido otra condicion por si solo hay un elemento
		return;
	first = (*stack)->next; // porque se va a convertir en el primero una vez acabamos el loop
	while ((*stack)->next != NULL)
	{
		*stack = (*stack)->next;
	}
	(*stack)->next = aux;
	aux->next = NULL;
	*stack = first; // hacemos que el ptr apunte a prev segundo elem que ahora sera 1
}

void	ft_rev_rotate(t_list **stack)
{
	t_list	*aux;
	t_list	*first;

	if (*stack == NULL || (*stack)->next == NULL) //añadido otra condicion
		return;
	first = *stack;
	while((*stack)->next != NULL)
	{
		// aqui pillo una posicion antes de la ultima que apunta al null
		//porque se convertira en la nueva ultima
		aux = (*stack);
		*stack = (*stack)->next; //aqui voy avanzando, y la ultima que salga de aqui
		//apuntara a la ultimo que sera la nueva primera
	}
	//aqui la ultima le pongo null
	aux->next = NULL;
	//engancho la nueva primera posicion con la antigua primera que sera ahorra next.
	(*stack)->next = first;
}