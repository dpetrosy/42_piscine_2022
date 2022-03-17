/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:22:44 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/02/13 23:16:31 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	check_argc(int argc);
int	check_argv_lenght(char **argv);
int	check_argv(char **argv);
void	ft_putstr(char *str);
void	matrix_and_numbers(char **argv);

void	check_user_input(int argc, char **argv)
{
	char	*str;

	str = "Error\n";
	if (check_argc(argc))
		if (check_argv_lenght(argv))
			if (check_argv(argv))
				matrix_and_numbers(argv);
			else
				ft_putstr(str);
		else
			ft_putstr(str);
	else
		ft_putstr(str);	
}

int check_argc(int argc)
{
	if (argc != 2)
	{
		return (0);
	}
	else
	{
		return (1);
	}
}

int	check_argv_lenght(char **argv)
{
	char	*str;
	int	i;

	str = argv[1];

	i = 0;
	while (str[i] != '\0')
	{
		++i;
	}
	if (i != 31)
	{
		return (0);
	}
	else
	{
		return (1);
	}
}

int check_argv(char **argv)
{
	char	*str;
	int	i;

	str = argv[1];
	i = 0;
	while (str[i] != '\0')
	{
		if (i % 2 == 0)
		{
			if (str[i] < 49 || str[i] > 52)
				return (0);
		}
		else if (str[i] != ' ')
		{
			return (0);
		}
		++i;
	}
	return (1);
}
