#include "../push_swap.h"

void	sa(t_stack **a_stack)
{
	t_stack	*temp;

	if (!*a_stack || !(*a_stack)->next)
		return ;
	temp = *a_stack;
	*a_stack = (*a_stack)->next;
	temp->next = (*a_stack)->next;
	(*a_stack)->next = temp;
	write(1, "sa\n", 3);
}

/*
int	swap(t_stack **a_stack)
{
	t_stack	*head;
	t_stack	*next;
	int		tmp_val;
	int		tmp_index;

	if (ft_lstsize(*a_stack) < 2)
		return (-1);
	head = *a_stack;
	next = head->next;
	if (!head && !next)
		ft_handle_error("Error\n");
	tmp_val = head->number;
	tmp_index = head->index;
	head->number = next->number;
	head->index = next->index;
	next->number = tmp_val;
	next->index = tmp_index;
	return (0);
}

void	sa(t_stack **a_stack)
{
	if (swap(a_stack) == -1)
		return ;
	write(1, "sa\n", 3);
}
*/

void	rra(t_stack **a_stack)
{
	t_stack	*temp;
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
/*
int	rotate(t_stack **a_stack)
{
	t_stack	*head;
	t_stack	*tail;

	if (ft_lstsize(*a_stack) < 2)
		return (-1);
	head = *a_stack;
	tail = ft_lstlast(head);
	*a_stack = head->next;
	head->next = NULL;
	tail->next = head;
	return (0);
}

void	ra(t_stack **a_stack)
{
	if (rotate(a_stack) == -1)
		return ;
	write(1, "ra\n", 3);
}
*/

void	ra(t_stack **a_stack)
{
	t_stack	*temp;

	temp = *a_stack;
	*a_stack = ft_lstlast(*a_stack);
	(*a_stack)->next = temp;
	*a_stack = temp->next;
	temp->next = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_stack **b_stack)
{
	t_stack	*temp;

	temp = *b_stack;
	*b_stack = ft_lstlast(*b_stack);
	(*b_stack)->next = temp;
	*b_stack = temp->next;
	temp->next = NULL;
	write(1, "rb\n", 3);
}

int	ft_push(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*temp;
	t_stack	*from;
	t_stack	*to;

	if (ft_lstsize(*b_stack) == 0)
		return (-1);
	from = *b_stack;
	to = *a_stack;
	temp = *b_stack;
	from = from->next;
	*b_stack = from;
	if (!to)
	{
		to = temp;
		to->next = NULL;
		*a_stack = to;
	}
	else
	{
		temp->next = to;
		*a_stack = temp;
	}
	return (0);
}

void	pb(t_stack **a_stack, t_stack **b_stack)
{
	if (ft_push(b_stack, a_stack) == -1)
		ft_handle_error("Error\n");
	write(1, "pb\n", 3);
}

void	pa(t_stack **a_stack, t_stack **b_stack)
{
	if (ft_push(a_stack, b_stack) == -1)
		ft_handle_error("Error\n");
	write(1, "pa\n", 3);
}