/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 16:23:11 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/02/13 21:59:53 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(const char c);
void	ft_putstr(char *str);

void	ft_putchar(const char c)
{
	write (1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		++i;
	}
}

void	display_solved(int solved[][5])
{
	int i;
	int j;

	i = 0;
	while (++i <= 4)
	{
		j = 0;
		while (++j <= 4)
		{
			ft_putchar(solved[i][j] + '0');
			if (j != 4)
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}
