/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolor-e <abolor-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:22:02 by abolor-e          #+#    #+#             */
/*   Updated: 2024/02/16 14:50:43 by abolor-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# include "libft/libft.h"

# define FAILURE -1

typedef struct s_stack_list
{
	long			number;
	struct s_stack_list	*prev;
	struct s_stack_list	*next;
}				t_stack_list;

// utils.c!
int	ft_atoi(const char *str);
void	ft_double_check(t_stack_list *a_stack);
void	ft_sorted_check(t_stack_list *a_stack);

// free_error.c! error message and free function!
void	ft_free_(char **str);
void	ft_handle_error(char *str);

// pull.c! extraction of data!
t_stack_list	*ft_extract(int ac, char **av);
t_stack_list	*ft_extract_ac2(char **av);
void	ft_lstadd_back(t_stack_list **lst, t_stack_list *new);
t_stack_list	*ft_lstlast(t_stack_list *lst);
t_stack_list	*ft_lstnew(int content);

#endif