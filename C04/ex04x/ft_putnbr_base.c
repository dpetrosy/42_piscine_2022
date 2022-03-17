/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 22:50:07 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/02/22 00:21:19 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_base(long int num, char *base);
int		check_base(char *base);
void	ft_putnbr_base(int nbr, char *base);

void	ft_putnbr_base(int nbr, char *base)
{
	long int	num;

	if (base[0] == '\0' || base[1] == '\0')
		return ;
	if (check_base(base) == 1)
	{
		num = nbr;
		if (num < 0)
		{
			write (1, "-", 1);
			num = -num;
		}
		print_base(num, base);
	}
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= 32 || base[i] == 127)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (!(base[i] >= 33 && base[i] <= 126))
				return (0);
			if (base[i] == base[j])
				return (0);
			++j;
		}
		++i;
	}
	return (1);
}

void	print_base(long int num, char *base)
{
	char	hex[500];
	int		rem;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (base[len])
		++len;
	if (num == 0)
	{
		write (1, &base[0], 1);
		return ;
	}
	while (num != 0)
	{
		rem = num % len;
		hex[i] = base[rem];
		++i;
		num = num / len;
	}
	while (i-- >= 0)
		write(1, &hex[i], 1);
}
