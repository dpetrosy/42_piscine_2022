/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 00:38:17 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/02/12 18:02:47 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	char	*return_ptr;
	char	c;

	return_ptr = str;
	if (*str == '\0')
		return (return_ptr);
	c = *str;
	while (c != '\0')
	{
		if (c >= 97 && c <= 122)
		{
			*str = c - 32;
		}
		str = str + 1;
		c = *str;
	}
	return (return_ptr);
}
