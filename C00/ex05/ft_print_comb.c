/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 23:57:04 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/02/08 17:22:02 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	display_numbers(int i, int j, int k, int is_comma);
void	control_j(char *i, char *j, char *k);

void	ft_print_comb(void)
{
	char	i;
	char	j;
	char	k;

	i = '0';
	j = '1';
	k = '2';
	display_numbers(i, j, k, 1);
	while (i != '7')
	{
		if (k != '9')
			++k;
		else
		{
			++j;
			k = j + 1;
		}
		display_numbers(i, j, k, 1);
		control_j(&i, &j, &k);
	}
	display_numbers(i, j, ++k, 0);
}

void	display_numbers(int i, int j, int k, int is_comma)
{
	ft_putchar(i);
	ft_putchar(j);
	ft_putchar(k);
	if (is_comma == 1)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	control_j(char *i, char *j, char *k)
{	
	if (*j == '8')
	{
		*i = *i + 1;
		*j = *i + 1;
		*k = *j;
	}
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}
