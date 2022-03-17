/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 17:57:45 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/02/15 17:26:23 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(const char c);
void	reverse(char *str, int length);
void	itao(char *str, long long int number);
void	check_number(char *str, long long int *num, int *is_neg, int *num_len);

void	ft_putnbr(int nb)
{
	char			str[50];
	char			c;
	int				i;
	long long int	num;

	num = nb;
	itao(str, num);
	i = 0;
	c = str[i++];
	while (c != '\0')
	{
		ft_putchar(c);
		c = str[i++];
	}
}

void	ft_putchar(const char c)
{
	write(1, &c, 1);
}

void	reverse(char *str, int length)
{
	int	start;
	int	end;
	int	tmp;

	start = 0;
	end = length - 1;
	while (start < end)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		++start;
		--end;
	}
}

void	itao(char *str, long long int number)
{
	int	num_length;
	int	reminder;
	int	is_negative;

	num_length = 0;
	is_negative = 0;
	check_number(str, &number, &is_negative, &num_length);
	while (number != 0)
	{
		reminder = number % 10;
		str[num_length++] = reminder + '0';
		number /= 10;
	}
	if (is_negative)
		str[num_length++] = '-';
	str[num_length] = '\0';
	reverse(str, num_length);
}

void	check_number(char *str, long long int *num, int *is_neg, int *num_len)
{
	if (*num == 0)
	{
		str[*num_len] = '0';
		*num_len = *num_len + 1;
		str[*num_len] = '\0';
	}
	if (*num < 0)
	{
		*is_neg = 1;
		*num = -(*num);
	}
}
