#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int				s;
	long long int	res;

	s = 1;
	res = 0;
	while (*str == '\n' || *str == '\t' || *str == ' '
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if ((*str == '-' || *str == '+') && *(str + 1) != '\0')
	{
		if (*str == '-')
			s = -1;
		str++;
	}
	while (*str)
	{
		if (*str >= 58 || *str <= 47)
			ft_handle_error("Error\n");
		res = (res * 10) + (*str - '0');
		str++;
	}
	if ((res * s) > INT_MAX || (res * s) < INT_MIN)
		ft_handle_error("Error\n");
	return (res * s);
}

void	ft_double_check(t_stack_list *a_stack)
{
	t_stack_list	*check;

	while (a_stack)
	{
		check = a_stack->next;
		while (check)
		{
			if (a_stack->number == check->number)
				ft_handle_error("Error\n"); //Check if the stack needs to be freed?
			check = check->next;
		}
		a_stack = a_stack->next;
	}
}

void	ft_sorted_check(t_stack_list *a_stack)
{
	t_stack_list	*check;

	while (a_stack && a_stack->next)
	{
		check = a_stack->next;
		if (check->number < a_stack->number)
			return ; // Check this return!
		a_stack = a_stack->next;
	}
	ft_handle_error("Error\n");
	// Check when 1 number and ascending 
	// numbers are present, error or nothing?
}
