/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 22:45:11 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/02/14 22:23:45 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	main(int argc, char **argv)
{
	int		j;
	char	*str;

	(void) argc;
	(void) argv;
	while (--argc >= 1)
	{
		j = 0;
		str = argv[argc];
		while (str[j] != '\0')
		{
			ft_putchar(str[j]);
			++j;
		}
		ft_putchar('\n');
	}
	return (0);
}
