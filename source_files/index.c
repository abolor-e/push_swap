#include "../push_swap.h"

static t_stack	*ft_min_content(t_stack **a_stack)
{
	t_stack	*temp;
	t_stack	*point_min;
	int				starter;

	temp = *a_stack;
	point_min = NULL;
	starter = 0;
	while (temp)
	{
		if ((!starter || temp->number < point_min->number) && temp->index == -1)
		{
			point_min = temp;
			starter = 1;
		}
		temp = temp->next;
	}
	return (point_min);
}

void	ft_sort_index(t_stack **a_stack)
{
	t_stack	*temp;
	int				i;

	temp = ft_min_content(a_stack);
	i = 0;
	while (temp)
	{
		temp->index = i++;
		temp = ft_min_content(a_stack);	
	}
}

static int	ft_minindex(t_stack **a_stack)
{
	t_stack	*temp;
	int		min;

	temp = *a_stack;
	min = temp->index;
	while (temp) //try also with just while (temp)!
	{
		if (temp->index < min)
			min = temp->index;
		temp = temp->next;
	}
	return (min);
}

int	ft_gap(t_stack **a_stack)
{
	t_stack	*temp;
	int		gap;

	temp = *a_stack;
	gap = 0;
	while (temp)
	{
		if (temp->index == ft_minindex(a_stack))
			break;
		gap++;
		temp = temp->next;
	}
	return (gap);
}