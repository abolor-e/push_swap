#include "push_swap.h"
#include <stdio.h>
/*
int	ft_min_check3(t_stack *a_stack)
{
	t_stack	*temp;

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

void	ft_little_sort(t_stack **a_stack)
{
	if (!*a_stack)
		return; //Check this return!!! Maybe error handling function call!
	if (ft_min_arg3(*a_stack) == 0)
	{
		rra(a_stack);
		sa(a_stack);
	}
	else if (ft_max_arg3(*a_stack) == (*a_stack)->number)
	{
		ra(a_stack);
		if (ft_sorted_check(*a_stack) == 0)
			sa(a_stack);
	}
	else if (ft_max_arg3(*a_stack) == (ft_lstlast(*a_stack)->number))
	{
		sa(a_stack);
	}
	else if (ft_min_arg3(*a_stack) == (ft_lstlast(*a_stack)->number &&
		ft_max_arg3(*a_stack) == ((*a_stack)->next)->number))
		rra(a_stack); 
}

void	ft_sort4(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*temp;
	int		gap;

	gap = ft_gap(a_stack);
	temp = *a_stack;
	printf("%ld %ld %ld %ld\n", (*a_stack)->number, ((*a_stack)->next)->number, (((*a_stack)->next)->next)->number, ((((*a_stack)->next)->next)->next)->number);
	if (gap == 1)
	{
		sa(a_stack);
		printf("%ld %ld %ld %ld\n", (*a_stack)->number, ((*a_stack)->next)->number, (((*a_stack)->next)->next)->number, ((((*a_stack)->next)->next)->next)->number);
	}
	else if (gap == 2)
	{
		ra(a_stack);
		printf("%ld %ld %ld %ld\n", (*a_stack)->number, ((*a_stack)->next)->number, (((*a_stack)->next)->next)->number, ((((*a_stack)->next)->next)->next)->number);
		ra(a_stack);
		printf("%ld %ld %ld %ld\n", (*a_stack)->number, ((*a_stack)->next)->number, (((*a_stack)->next)->next)->number, ((((*a_stack)->next)->next)->next)->number);
	}
	else if (gap == 3)
	{
		rra(a_stack);
		printf("%ld %ld %ld %ld\n", (*a_stack)->number, ((*a_stack)->next)->number, (((*a_stack)->next)->next)->number, ((((*a_stack)->next)->next)->next)->number);
	}
	if (ft_sorted_check(*a_stack) == 0)
	{
		pb(a_stack, b_stack);
		printf("%ld %ld %ld\n", (*a_stack)->number, ((*a_stack)->next)->number, (((*a_stack)->next)->next)->number);
		ft_little_sort(a_stack);
		pa(a_stack, b_stack);
	}
}

void	ft_sort5(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*temp;
	int		gap;

	gap = ft_gap(a_stack);
	temp = *a_stack;
	if (gap == 1)
		sa(a_stack);
	else if (gap == 2)
	{
		ra(a_stack);
		ra(a_stack);
	}
	else if (gap == 3)
	{
		rra(a_stack);
		rra(a_stack);
	}
	else if (gap == 4)
		rra(a_stack);
	if (ft_sorted_check(*a_stack) == 0)
	{
		pb(a_stack, b_stack);
		ft_sort4(a_stack, b_stack);
		pa(a_stack, b_stack);
	}
}

void	ft_sorting(t_stack **a_stack)// Maybe Static!
{
	t_stack	*b_stack;

	if (!*a_stack || !(*a_stack)->next)
		return ; // Check this return!!!
	b_stack = NULL; // Maybe need to be mallocked?!
	ft_sort_index(a_stack);
	if (ft_lstsize(*a_stack) == 2)
		sa(a_stack);
	else if (ft_lstsize(*a_stack) == 3)
		ft_little_sort(a_stack);
	else if (ft_lstsize(*a_stack) == 4)
		ft_sort4(a_stack, &b_stack);
	else if (ft_lstsize(*a_stack) == 5)
		ft_sort5(a_stack, &b_stack);
	else
		ft_radix_sort();
}
