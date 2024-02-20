#include "push_swap.h"
/*
int	ft_min_check(t_stack_list *a_stack)
{
	int	i;

	i = 0;

}
*/

void	ft_little_sort(t_stack_list **a_stack)
{
	if (ft_min_check(*a_stack) == (*a_stack)->number)
	{
		rra(a_stack);
		sa(a_stack);
	}
	else if ()
}