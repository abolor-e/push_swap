#include "push_swap.h"

void	sa(t_stack_list **a_stack)
{
	t_stack_list	*temp;

	if (!*a_stack || !(*a_stack)->next)
		return ;
	temp = *a_stack;
	*a_stack = (*a_stack)->next;
	(*a_stack)->next = temp;
	write(1, "sa\n", 3);
}

void	rra(t_stack_list **a_stack)
{
	t_stack_list	*temp;
	int				i;

	i = 0;
	temp = *a_stack;
	while ((*a_stack)->next)
	{
		i++;
		*a_stack = (*a_stack)->next;
	}
	(*a_stack)->next = temp;
	while (i > 1)
	{
		temp = temp->next;
		i--;
	}
	temp->next = NULL;
	write(1, "rra\n", 4);
}

void	ra(t_stack_list **a_stack)
{
	t_stack_list	*temp;

	temp = *a_stack;
	*a_stack = ft_lstlast(*a_stack);
	(*a_stack)->next = temp;
	*a_stack = temp->next;
	temp->next = NULL;
	write(1, "ra\n", 3);
}