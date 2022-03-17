/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 02:31:04 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/02/24 18:16:10 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_atoi.h"

void	ft_atoi(char num[], char *str, int i, int j)
{
	if (str[0] == '\0')
		return ;
	while (ft_isspace(str[i]))
		++i;
	if (str[i] == '-' || str[i] == '+')
		return ;
	if (str[i] < '0' || str[i] > '9')
		return ;
	if (check_0(str, i))
	{
		num[0] = '0';
		num[1] = '\0';
		return ;
	}
	while (str[i] == '0')
		++i;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num[j] = str[i];
		++i;
		++j;
	}
	num[j] = '\0';
}

int	check_0(char *str, int i)
{
	while (str[i] == '0')
		++i;
	if (str[i] == '\0')
		return (1);
	else
		return (0);
}

int	ft_isspace(char c)
{
	char	*str;
	int		i;

	str = " \f\n\r\t\v";
	i = 0;
	while (str[i] != '\0')
	{
		if (c == str[i])
			return (1);
		++i;
	}
	return (0);
}
