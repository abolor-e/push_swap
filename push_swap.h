/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolor-e <abolor-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:22:02 by abolor-e          #+#    #+#             */
/*   Updated: 2024/02/23 11:06:17 by abolor-e         ###   ########.fr       */
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

typedef struct s_stack
{
	long			number;
	int				index;
	struct s_stack	*prev;
	struct s_stack	*next;
}				t_stack;

// utils.c!
int				ft_atoi(const char *str);
void			ft_double_check(t_stack *a_stack);
int				ft_sorted_check(t_stack *a_stack);
int				ft_lstsize(t_stack *lst);
int				ft_min_arg3(t_stack *a_stack);

// utils2.c
int		ft_max_arg3(t_stack *a_stack);

// index.c
void	ft_sort_index(t_stack **a_stack);
int		ft_gap(t_stack **a_stack);

// free_error.c! error message and free function!
void		ft_free_(char **str);
void		ft_handle_error(char *str);

// pull.c! extraction of data!
t_stack		*ft_extract(int ac, char **av);
t_stack		*ft_extract_ac2(char **av);
t_stack		*ft_lstlast(t_stack *lst);
t_stack		*ft_lstnew(int content);
void		ft_lstadd_back(t_stack **lst, t_stack *new);

// operations.c!
void		sa(t_stack **a_stack);
void		rra(t_stack **a_stack);
void		ra(t_stack **a_stack);
void		ft_push(t_stack **a_stack, t_stack **b_stack);
void		pb(t_stack **a_stack, t_stack **b_stack);
void		pa(t_stack **a_stack, t_stack **b_stack);

//int	rotate(t_stack **a_stack);

//int	swap(t_stack **a_stack);

// sorting.c!
void		ft_little_sort(t_stack **a_stack);
void		ft_sorting(t_stack **a_stack);
void		ft_sort4(t_stack **a_stack, t_stack **b_stack);
void	ft_sort5(t_stack **a_stack, t_stack **b_stack);

#endif