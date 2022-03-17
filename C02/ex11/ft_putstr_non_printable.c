/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 21:43:05 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/02/15 17:08:41 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	print_hex(int num);

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	print_hex(int num)
{
	char	hex[100];
	int		rem;
	char	c;
	int		i;

	if (num < 16)
	{
		c = '0';
		write (1, &c, 1);
	}
	i = 0;
	while (num != 0)
	{
		rem = num % 16;
		if (rem < 10)
			hex[i] = rem + '0';
		else
			hex[i] = (rem + '0') + 39;
		++i;
		num = num / 16;
	}
	while (i-- >= 0)
		write(1, &hex[i], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 0 && str[i] <= 31) || str[i] == 127)
		{
			ft_putchar('\\');
			print_hex(str[i]);
		}
		else
			ft_putchar(str[i]);
		++i;
	}
}
