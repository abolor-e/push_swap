/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolor-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:58:00 by abolor-e          #+#    #+#             */
/*   Updated: 2024/02/27 12:58:31 by abolor-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_atoi(const char *str)
{
	int				s;
	long long int	res;

	s = 1;
	res = 0;
	while (*str == '\n' || *str == '\t' || *str == ' '
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	ft_little_check(str);
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

void	ft_double_check(t_stack *a_stack)
{
	t_stack	*check;

	while (a_stack)
	{
		check = a_stack->next;
		while (check)
		{
			if (a_stack->number == check->number)
			{
				ft_free_stack(&a_stack);
				ft_handle_error("Error\n");
			}
			check = check->next;
		}
		a_stack = a_stack->next;
	}
}

int	ft_sorted_check(t_stack *a_stack)
{
	int	i;

	i = a_stack->number;
	while (a_stack)
	{
		if (i > a_stack->number)
			return (0);
		i = a_stack->number;
		a_stack = a_stack->next;
	}
	return (1);
}

int	ft_lstsize(t_stack *lst)
{
	size_t	i;

	if (!lst)
		return (0);
	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int	ft_min_arg3(t_stack *a_stack)
{
	int	i;

	i = a_stack->number;
	while (a_stack)
	{
		if (i > a_stack->number)
			return (1);
		a_stack = a_stack->next;
	}
	return (0);
}
