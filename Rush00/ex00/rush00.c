/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 20:17:27 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/02/05 20:27:47 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(const char c);
void	fill_rectangle(int i, int j, int I, int J);
void	up_down_line(int i, int j, int I, int J);
void	display_up_line(int j, int J);

void	rush(const int J, const int I)
{
	int	i;
	int	j;

	i = 0;
	while (++i <= I)
	{
		j = 0;
		while (++j <= J)
		{
			fill_rectangle(i, j, I, J);
			up_down_line(i, j, I, J);
		}
		ft_putchar('\n');
	}
}

void	fill_rectangle(int i, int j, int I, int J)
{
	char	symbol;
	char	space;

	symbol = '|';
	space = ' ';
	if (i != 1 && i != I)
	{
		if (j == 1 || j == J)
			ft_putchar(symbol);
		else
			ft_putchar(space);
	}
}

void	up_down_line(int i, int j, int I, int J)
{
	char	letter_o;
	char	symbol_line;

	letter_o = 'o';
	symbol_line = '-';
	if (i == 1)
	{
		display_up_line(j, J);
	}
	else if (i == I)
	{
		if (j == 1)
			ft_putchar(letter_o);
		else if (j == J)
			ft_putchar(letter_o);
		else
			ft_putchar(symbol_line);
	}
}

void	display_up_line(int j, int J)
{
	char	letter_o;
	char	symbol_line;

	letter_o = 'o';
	symbol_line = '-';
	if (j == 1)
		ft_putchar(letter_o);
	else if (j == J)
		ft_putchar(letter_o);
	else
		ft_putchar(symbol_line);
}
