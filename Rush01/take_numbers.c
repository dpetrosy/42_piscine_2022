/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 00:02:16 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/02/13 21:53:48 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	correct_numbers(int arr[][6]);
void	fill_0(int arr[][6]);
void	fill_0_inside(int arr[][6]);

void	take_numbers(int arr[][6], char *arg)
{
	fill_0(arr);

	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (i <= 4)
	{
		j = 0;
		while (j <= 4)
		{
			if (j == 0 || i == 0)
			   arr[i][j] = 0;
			else
			{
				arr[i][j] = arg[k] - '0';
				k += 2;
			}
			++j;
		}
		++i;
	}
	correct_numbers(arr);
}

void	fill_0(int arr[][6])
{
	int i;
	int j;

	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 6)
		{
			arr[i][j] = 0;
			++j;
		}
		++i;
	}
}

void correct_numbers(int arr[][6])
{
	int i;
	int j;

	j = 0;
	while (++j <= 4)
		arr[0][j] = arr[1][j];
	j = 0;
	while (++j <= 4)
		arr[5][j] = arr[2][j];
	i = 0;
	j = 1;
	while (++i <= 4)
	{
		arr[i][0] = arr[3][j];
		++j;
	}	
	i = 0;
	j = 1;
	while (++i <= 4)
	{
		arr[i][5] = arr[4][j];
		++j;
	}
	fill_0_inside(arr);
}

void	fill_0_inside(int arr[][6])
{
	int i;
	int j;

	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 6)
		{
			if (i >= 1 && i <= 4 && j >= 1 && j <= 4)
				arr[i][j] = 0;
			++j;
		}
		++i;
	}	
}
