/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 01:58:18 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/02/18 03:15:28 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str);

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len_src;
	unsigned int	len_dest;

	len_src = ft_strlen(src);
	len_dest = ft_strlen(dest);
	if (size < 1)
		return (size + len_src);
	i = 0;
	while (dest[i] != '\0')
		++i;
	j = 0;
	while ((src[j] != '\0') && (i < size - 1))
	{
		dest[i] = src[j];
		++i;
		++j;
	}
	dest[i] = '\0';
	if (size < len_dest)
		return (len_src + size);
	else
		return (len_src + len_dest);
}

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		++i;
	}
	return (i);
}
