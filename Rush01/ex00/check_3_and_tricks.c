/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_3_and_tricks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:50:29 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/02/13 23:08:05 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	clear_nums(int matrix[][5][5], int i, int j, int num);
void	check_4_tricks(int solved[][5], int nums[][6], int matrix[][5][5]);
void	check_3_tricks(int nums[][6], int matrix[][5][5]);
void	check_4_tricks(int solved[][5], int nums[][6], int matrix[][5][5]);
void	check_last_4(int solved[][5], int matrix[][5][5]);

void	check_4_tricks(int solved[][5], int nums[][6], int matrix[][5][5])
{
	if (nums[0][1] == 1 && nums[1][0] == 1)
	{
		if (nums[0][3] == 2 && nums[2][5] == 2 && matrix[2][3][4] == 4)
		{
			solved[2][3] = 4;
			clear_nums(matrix, 2, 3, 4);
		}
	}
	if (nums[2][0] == 2 && nums[0][2] == 2 && matrix[2][2][4] == 4)
	{
		solved[2][2] = 4;
		clear_nums(matrix, 2, 2, 4);
	}
	if (nums[3][5] == 2 && nums[5][3] == 2 && matrix[3][3][4] == 4)
	{
		solved[3][3] = 4;
		clear_nums(matrix, 3, 3, 4);
	}
	if (nums[3][0] == 2 && nums[5][2] == 2 && matrix[3][2][4] == 4)
	{
		solved[3][2] = 4;
		clear_nums(matrix, 3, 2, 4);
	}
	check_last_4(solved, matrix);
}

void	check_3(int solved[][5], int nums[][6], int matrix[][5][5])
{
	int	i;

	i = 0;
	while (++i <= 4)
	{
		if (nums[i][0] == 1 && nums[i][5] == 2)
		{
			solved[i][4] = 3;
			clear_nums(matrix, i, 4, 3);
		}
		if (nums[i][0] == 2 && nums[i][5] == 1)
		{
			solved[i][1] = 3;
			clear_nums(matrix, i, 1, 3);
		}
	}
	i = 0;
	while (++i <= 4)
	{
		if (nums[0][i] == 1 && nums[5][i] == 2)
		{
			solved[4][i] = 3;
			clear_nums(matrix, 4, i, 3);
		}
		if (nums[0][i] == 2 && nums[5][i] == 1)
		{
			solved[1][i] = 3;
			clear_nums(matrix, 1, i, 3);
		}
	}
}

void	check_3_tricks(int nums[][6], int matrix[][5][5])
{
	int	i;

	i = 0;
	while (++i <= 4)
	{
		if (nums[i][0] == 3)
		{
			matrix[i][1][3] = 0;
		}
		if (nums[i][5] == 3)
			matrix[i][4][3] = 0;
	}
	i = 0;
	while (++i <= 4)
	{
		if (nums[0][i] == 3)
			matrix[1][i][3] = 0;
		if (nums[5][i] == 3)
			matrix[4][i][3] = 0;
	}
}

void	check_last_4(int solved[][5], int matrix[][5][5])
{
	int	i;
	int	j;

	i = 0;
	while (++i <= 4)
	{
		j = 0;
		while (++j <= 4)
		{
			if (matrix[i][j][4] == 4)
			{
				solved[i][j] = 4;
				clear_nums(matrix, i, j, 4);
			}
		}
	}
}
