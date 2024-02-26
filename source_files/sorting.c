#include "../push_swap.h"

void	ft_little_sort(t_stack **a_stack)
{
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
	if (gap == 1)
		sa(a_stack);
	else if (gap == 2)
	{
		ra(a_stack);
		ra(a_stack);
	}
	else if (gap == 3)
		rra(a_stack);
	if (ft_sorted_check(*a_stack) == 0)
	{
		pb(a_stack, b_stack);
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

static int	ft_maxindex_bits(t_stack **a_stack)
{
	t_stack	*temp;
	int		max;
	int		bits;
	//int		list_size;

	temp = *a_stack;
	max = temp->index;
	bits = 0;
	// list_size = ft_lstsize(temp);
	// while (list_size > 0 && ++bits)
	// 	list_size /= 2;
	while (temp)
	{
		if (temp->index > max)
			max = temp->index;
		temp = temp->next;
	}
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	ft_radix_sort(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*temp;
	int		i;
	int		a;
	int		list_size;
	int		iterbits;

	i = 0;
	temp = *a_stack;
	list_size = ft_lstsize(temp);
	iterbits = ft_maxindex_bits(a_stack);
	while (i < iterbits)
	{
		a = 0;
		while (a++ < list_size)
		{
			temp = *a_stack;
			if (((temp->index >> i) & 1) == 0)
				pb(a_stack, b_stack);
			else
				ra(a_stack);
		}
		while (ft_lstsize(*b_stack) != 0)
			pa(a_stack, b_stack);
		i++;
	}
}

// static void	radix_b(t_stack *b_stack, int b_size, int nb_bits, int j, t_stack *a_stack)
// {
// 	while (b_size && j <= nb_bits && ft_sorted_check(b_stack) == 0)
// 	{
// 		if (((b_stack->index >> j) & 1) == 0)
// 			rb(&b_stack);
// 		else
// 			pa(&a_stack, &b_stack);
// 		b_size--;
// 	}
// 	b_size = ft_lstsize(b_stack);
// 	if (ft_sorted_check(b_stack) == 1)
// 	{
// 		while (b_size >= 0)
// 		{
// 			pa(&a_stack, &b_stack);
// 			b_size--;
// 		}
// 	}
// }

// void	ft_radix_sort(t_stack **a_stack, t_stack **b_stack)
// {
// 	int	j;
// 	int	nb_bits;
// 	int	size;
// 	int	size_b;

// 	nb_bits = 0;
// 	size = ft_lstsize(*a_stack);
// 	while (size > 1 && ++nb_bits)
// 		size /= 2;
// 	j = 0;
// 	while (j <= nb_bits)
// 	{
// 		size = ft_lstsize(*a_stack);
// 		while (size)
// 		{
// 			if ((((*a_stack)->index >> j) & 1) == 1)
// 				pb(a_stack, b_stack);
// 			else
// 				ra(a_stack);
// 			size--;
// 		}
// 		radix_b(*b_stack, ft_lstsize(*b_stack), nb_bits, j + 1, *a_stack);
// 		j++;
// 	}
// 	size_b = ft_lstsize(*b_stack);
// 	while (size_b >= 0)
// 	{
// 		pa(a_stack, b_stack);
// 		size_b--;
// 	}
// }

void	ft_sorting(t_stack **a_stack, t_stack **b_stack)
{
	//ft_sort_index(a_stack);
	if (ft_lstsize(*a_stack) == 2)
		sa(a_stack);
	else if (ft_lstsize(*a_stack) == 3)
		ft_little_sort(a_stack);
	else if (ft_lstsize(*a_stack) == 4)
		ft_sort4(a_stack, b_stack);
	else if (ft_lstsize(*a_stack) == 5)
		ft_sort5(a_stack, b_stack);
	else
		ft_radix_sort(a_stack, b_stack);
}
