/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:30:12 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/02/21 20:58:37 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isspace(char c);

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

int	ft_atoi(char *str)
{
	int		minus;
	int		num;
	int		i;

	minus = 1;
	i = 0;
	while (ft_isspace(str[i]))
		++i;
	while (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			minus = -minus;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	num = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10;
		num = num + (str[i] - '0');
		++i;
	}
	num = num * minus;
	return (num);
}
