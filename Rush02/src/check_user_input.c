/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_user_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 02:14:07 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/02/24 18:15:52 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/check_user_input.h"

void	check_user_input(int argc, char **argv)
{
	char	number[42];


	fill_0(number, '#');
	if (argc == 2)
	{
		if (check_input(argv[1], number) == 1)
			solver("numbers.dict", number, ft_strlen(number));
		else
			ft_putstr("Error");
	}
	else if (argc == 3)
	{
		if (check_input(argv[2], number) == 1)
		{
			solver(argv[1], number, ft_strlen(number));
		}
		else
			ft_putstr("Error");
	}
	else
		ft_putstr("Parameters count error\n");
}

int	check_input(char *str, char num[])
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	num[39] = '\0';
	num[0] = '\0';
	ft_atoi(num, str, i, j);
	if (num[0] == '\0' || num [39] != '\0')
		return (-1);
	else
		return (1);
}

void	fill_0(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		str[i] = c;
		++i;
	}
}
