/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 02:07:37 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/03/13 20:34:42 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb);
int	ft_sqrt(int nb);

int	ft_find_next_prime(int nb)
{
	int	is_found;
	int	i;
	int	int_range;

	int_range = 2147483647;
	if (nb <= 1)
		return (2);
	is_found = 0;
	i = nb;
	if (ft_is_prime(i))
		return (i);
	while (!(is_found) && i < int_range)
	{
		++i;
		is_found = ft_is_prime(i);
	}
	return (i);
}

int	ft_is_prime(int nb)
{
	int	i;
	int	num_sqrt;

	if (nb == 2 || nb == 3 || nb == 5)
		return (1);
	num_sqrt = ft_sqrt(nb);
	if (nb > 5 && (nb % 2 == 0 || nb % 3 == 0 || nb % 5 == 0))
		return (0);
	if (nb <= 1)
		return (0);
	i = 2;
	while (i <= num_sqrt)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_sqrt(int nb)
{
	int	i;

	if (nb <= 0)
		return (0);
	i = 1;
	while (i * i < nb)
	{
		if (i >= 46341)
			return (i + 1);
		++i;
	}
	if (i * i == nb)
		return (i);
	else
		return (i + 1);
}
