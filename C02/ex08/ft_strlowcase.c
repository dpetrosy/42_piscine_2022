/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 01:05:24 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/02/08 01:07:33 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	char	*return_ptr;
	char	c;

	return_ptr = str;
	if (*str == '\0')
		return (return_ptr);
	c = *str;
	while (c != '\0')
	{
		if (c >= 65 && c <= 90)
		{
			*str = c + 32;
		}
		str = str + 1;
		c = *str;
	}
	return (return_ptr);
}
