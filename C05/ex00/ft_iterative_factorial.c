/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:10:19 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/02/16 00:34:03 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int					i;
	unsigned long long	num;

	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	i = 1;
	num = 1;
	while (i <= nb)
	{
		num = num * i;
		++i;
	}
	return (num);
}
