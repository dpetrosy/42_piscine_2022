/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:16:36 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/02/08 20:46:00 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	char	c;
	int		i;

	i = 0;
	c = *(str + i++);
	while (c != '\0')
	{
		ft_putchar(c);
		c = *(str + i++);
	}
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}
