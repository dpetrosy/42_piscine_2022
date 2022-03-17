/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 22:36:02 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/02/07 22:45:19 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int		k;
	char	c;

	if (*str == '\0')
		return (1);
	c = *str;
	while (c != '\0')
	{
		if (c >= 65 && c <= 90)
			k = 1;
		else
			return (0);
		str = str + 1;
		c = *str;
	}
	return (1);
}
