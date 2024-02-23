#include "push_swap.h"

int	ft_max_arg3(t_stack *a_stack)
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
