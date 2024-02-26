#include "../push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*res;
	char	*temp;

	res = NULL;
	res = malloc(count * size);
	if (res == NULL)
		return (res);
	temp = res;
	i = 0;
	while (i < count * size)
		temp[i++] = 0;
	return (res);
}

void	ft_check_av(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (!av[i][0])
			ft_handle_error("Error\n");
		i++;
	}
}

void	ft_little_check(const char *str)
{
	while (*str == '\n' || *str == '\t' || *str == ' '
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '\0')
		ft_handle_error("Error\n");
}