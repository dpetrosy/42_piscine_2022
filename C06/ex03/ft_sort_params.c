/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 22:42:40 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/02/14 23:55:19 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strcmp(char *s1, char *s2);
void	swap(int j, char **argv);
void	display_str(int argc, char **argv);

void	display_str(int argc, char **argv)
{
	int		i;
	int		j;
	char	*str;
	char	new_line;

	new_line = '\n';
	i = 0;
	while (++i < argc)
	{
		j = 0;
		str = argv[i];
		while (str[j] != '\0')
		{
			write (1, &str[j], 1);
			++j;
		}
		write (1, &new_line, 1);
	}
}

void	swap(int j, char **argv)
{
	char	*tmp;

	tmp = argv[j];
	argv[j] = argv[j + 1];
	argv[j + 1] = tmp;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (1)
	{
		if (s1[i] != s2[i])
		{
			if (s1[i] < s2[i])
				return (-1);
			else
				return (1);
		}
		if (s1[i] == '\0')
		{
			return (1);
		}
		++i;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*str1;
	char	*str2;

	i = 1;
	while (i < argc)
	{
		j = 1;
		while (j < argc - i)
		{
			str1 = argv[j];
			str2 = argv[j + 1];
			if (ft_strcmp(str1, str2) == 1)
			{
				swap(j, argv);
			}
			++j;
		}
		++i;
	}
	display_str(argc, argv);
	return (0);
}
