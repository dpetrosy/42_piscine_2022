/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 02:50:34 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/02/24 18:17:18 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solver.h"

int		g_size;

void	solver(char *dict, char number[], int size)
{
	char	nums_3[3];
	int		is_breaked;

	g_size = size;
	is_breaked = 0;
	fill_0(nums_3, '#');
	while (g_size > 0 && is_breaked == 0)
	{
		get_nums3(number, nums_3);
		is_breaked = display_words(dict, nums_3, g_size);
	}
}

void	get_nums3(char number[], char nums_3[])
{
	if (g_size % 3 == 1)
	{
		nums_3[0] = number[0];
		shift_left(number, 1);
	}
	else if (g_size % 3 == 2)
	{
		nums_3[0] = number[0];
		nums_3[1] = number[1];
		shift_left(number, 2);
	}
	else
	{	
		nums_3[0] = number[0];
		nums_3[1] = number[1];
		nums_3[2] = number[2];
		shift_left(number, 3);
	}
}

void	shift_left(char number[], int shift)
{
	int		i;
	int		j;

	i = 0;
	while (i < shift)
	{
		j = 0;
		while (j < g_size)
		{
			number[j] = number[j + 1];
			++j;
		}
		++i;
		g_size = g_size - 1;
	}
}
