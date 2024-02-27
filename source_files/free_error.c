/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolor-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:51:40 by abolor-e          #+#    #+#             */
/*   Updated: 2024/02/27 12:52:09 by abolor-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free_(char **str)
{
	char	*c;

	if (!str)
		return ;
	while (*str)
	{
		c = *str;
		free(c);
		str++;
	}
	*str = NULL;
}

void	ft_free_stack(t_stack **a_stack)
{
	t_stack	*tmp;

	if (!(*a_stack))
		return ;
	while (*a_stack)
	{
		tmp = (*a_stack)->next;
		free(*a_stack);
		*a_stack = tmp;
	}
	*a_stack = NULL;
}

void	ft_handle_error(char *str)
{
	write(2, str, 6);
	exit(FAILURE);
}
