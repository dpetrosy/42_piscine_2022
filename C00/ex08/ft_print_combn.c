/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:02:33 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/02/08 17:24:25 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	display_result(int n, int t, int b, char *s);
void	ft_putchar(char c);
void	display_str(char *s, int n);
int		strlength(char *s);

void	ft_print_combn(int n)
{
	int		i;
	char	s[10];

	s[0] = '0';
	i = 0;
	while (i <= 9)
	{
		display_result(n, 0, i++, s);
	}
}

void	display_result(int n, int t, int b, char *s)
{
	int		i;

	s[t] = b + '0';
	if (t == n - 1)
	{
		display_str(s, n);
	}
	else
	{
		i = b + 1;
		while (i <= 9)
		{
			display_result(n, t + 1, i++, s);
		}
	}
}

void	display_str(char *s, int n)
{
	char	c;
	int		last;
	int		i;

	i = 0;
	c = *(s + i++);
	last = 0;
	if (c == ((10 - n) + '0'))
		last = 1;
	while (c != '\0')
	{
		ft_putchar(c);
		c = *(s + i++);
	}
	if ((i - 1) % n == 0 && last != 1)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}
