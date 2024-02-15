#include "push_swap.h"

void	ft_free(char **str)
{
	char	*c;

	if (!str)
		return ;
	while (*str)
	{
		c = *str;
		free(c);
		*str++;
	}
	*str = NULL;
}

void	ft_handle_error(char *str)
{
	write(2, str, 6);
	exit(FAILURE);
}