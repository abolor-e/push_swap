/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolor-e <abolor-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:22:02 by abolor-e          #+#    #+#             */
/*   Updated: 2024/02/27 12:34:06 by abolor-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# define FAILURE -1
# define SUCCESS 1

typedef struct s_stack
{
	long			number;
	int				index;
	struct s_stack	*next;
}				t_stack;

// utils.c!
int		ft_atoi(const char *str);
void	ft_double_check(t_stack *a_stack);
int		ft_sorted_check(t_stack *a_stack);
int		ft_lstsize(t_stack *lst);
int		ft_min_arg3(t_stack *a_stack);

// utils2.c
int		ft_max_arg3(t_stack *a_stack);
char	**ft_free(char **split_array);
char	**ft_split(const char *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);

// utils3.c
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
void	ft_check_av(char **av);
void	ft_little_check(const char *str);

// index.c
void	ft_sort_index(t_stack **a_stack);
int		ft_gap(t_stack **a_stack);

// free_error.c! error message and free function!
void	ft_free_(char **str);
void	ft_handle_error(char *str);
void	ft_free_stack(t_stack **a_stack);

// pull.c! extraction of data!
t_stack	*ft_extract(int ac, char **av);
t_stack	*ft_extract_ac2(char **av);
t_stack	*ft_lstlast(t_stack *lst);
t_stack	*ft_lstnew(int content);
void	ft_lstadd_back(t_stack **lst, t_stack *new);

// operations.c!
void	sa(t_stack **a_stack);
void	rra(t_stack **a_stack);
void	ra(t_stack **a_stack);
int		ft_push(t_stack **a_stack, t_stack **b_stack);
void	pb(t_stack **a_stack, t_stack **b_stack);
void	pa(t_stack **a_stack, t_stack **b_stack);
void	rb(t_stack **b_stack);

// sorting.c!
void	ft_little_sort(t_stack **a_stack);
void	ft_sorting(t_stack **a_stack, t_stack **b_stack);
void	ft_sort4(t_stack **a_stack, t_stack **b_stack);
void	ft_sort5(t_stack **a_stack, t_stack **b_stack);
void	ft_radix_sort(t_stack **a_stack, t_stack **b_stack);

#endif