/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 01:07:59 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/02/15 00:41:33 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strlowcase(char *str);

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

char	*ft_strcapitalize(char *str)
{
	int		i;

	ft_strlowcase(str);
	i = 0;
	if (str[i] >= 97 && str[i] <= 122)
		str[i] = str[i] - 32;
	while (str[i] != '\0')
	{
		if (!((str[i] >= 65 && str[i] <= 90) || (str[i] >= 48 && str[i] <= 57)))
		{
			if (!(str[i] >= 97 && str[i] <= 122))
			{
				if (str[i + 1] >= 97 && str[i + 1] <= 122)
					str[i + 1] -= 32;
			}	
		}
		++i;
	}
	return (str);
}
