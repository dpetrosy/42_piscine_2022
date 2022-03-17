/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 01:30:18 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/02/22 02:00:25 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int		i;
	int		*arr;
	int		len;

	len = max - min;
	if (min >= max)
	{
		range = NULL;
		return (0);
	}
	arr = (int *)malloc(len * 4);
	if (arr == NULL)
		return (-1);
	i = 0;
	while (min < max)
	{
		arr[i] = min;
		++i;
		++min;
	}
	*range = arr;
	return (i);
}
