/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolor-e <abolor-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:22:02 by abolor-e          #+#    #+#             */
/*   Updated: 2024/02/21 16:40:28 by abolor-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# include "libft/libft.h"

# define FAILURE -1
# define SUCCESS 1

typedef struct s_stack_list
{
	long				number;
	struct s_stack_list	*prev;
	struct s_stack_list	*next;
}				t_stack_list;

// utils.c!
int				ft_atoi(const char *str);
void			ft_double_check(t_stack_list *a_stack);
int				ft_sorted_check(t_stack_list *a_stack);
int				ft_lstsize(t_stack_list *lst);
int				ft_min_arg3(t_stack_list *a_stack);

// free_error.c! error message and free function!
void			ft_free_(char **str);
void			ft_handle_error(char *str);

// pull.c! extraction of data!
t_stack_list	*ft_extract(int ac, char **av);
t_stack_list	*ft_extract_ac2(char **av);
void			ft_lstadd_back(t_stack_list **lst, t_stack_list *new);
t_stack_list	*ft_lstlast(t_stack_list *lst);
t_stack_list	*ft_lstnew(int content);

// operations.c!
void			sa(t_stack_list **a_stack);
void			rra(t_stack_list **a_stack);
void			ra(t_stack_list **a_stack);

// sorting.c!
void			ft_little_sort(t_stack_list **a_stack);

#endif