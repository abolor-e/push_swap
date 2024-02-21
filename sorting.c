#include "push_swap.h"
/*
int	ft_min_check3(t_stack_list *a_stack)
{
	t_stack_list	*temp;

	if (!a_stack)
		return (-1);
	temp = a_stack;
	while (a_stack)
	{
		if (temp->number > a_stack->number)
		{
			return (1);
		}
		a_stack = a_stack->next;
	}
	return (0);
}
*/

int	ft_max_arg3(t_stack_list *a_stack)
{
	int	i;

	i = a_stack->number;
	while (a_stack)
	{
		if (i < a_stack->number)
			i = a_stack->number;
		a_stack = a_stack->next;
	}
	return (i);
}

void	ft_little_sort(t_stack_list **a_stack)
{
	if (ft_min_arg3(*a_stack) == 0)
	{
		rra(a_stack);
		sa(a_stack);
	}
	else if (ft_max_arg3(*a_stack) == (*a_stack)->number)
	{
		ra(a_stack);
		if (ft_sorted_check(*a_stack) == 1)
			sa(a_stack);
	}
	else
	{
		rra(a_stack);
	}
}