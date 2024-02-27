/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolor-e <abolor-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:27:38 by abolor-e          #+#    #+#             */
/*   Updated: 2024/02/27 12:54:24 by abolor-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a_stack;
	t_stack	*b_stack;

	if (ac == 1)
		return (-1);
	a_stack = ft_extract(ac, av);
	b_stack = NULL;
	if (!a_stack)
	{
		ft_free_stack(&a_stack);
		ft_handle_error("Error\n");
	}
	ft_double_check(a_stack);
	if (ft_sorted_check(a_stack) == 1)
	{
		ft_free_stack(&a_stack);
		exit(FAILURE);
	}
	ft_sorting(&a_stack, &b_stack);
	return (0);
}
