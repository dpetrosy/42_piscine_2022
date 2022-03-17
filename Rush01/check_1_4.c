/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_1_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 01:31:36 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/02/13 23:05:41 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	check_1(int solved[][5], int nums[][6], int matrix[][5][5]);
void	check_4_u_d(int solved[][5], int nums[][6], int matrix[][5][5]);
void	clear_nums(int matrix[][5][5], int i, int j, int num);
void	check_1_r_l(int solved[][5], int nums[][6], int matrix[][5][5]);
void	check_4_r_l(int solved[][5], int nums[][6], int matrix[][5][5]);
void	check_4_tricks(int solved[][5], int nums[][6], int matrix[][5][5]);
void	check_3(int solved[][5], int nums[][6], int matrix[][5][5]);
void	check_3_tricks(int nums[][6], int matrix[][5][5]);

void	check_1_4(int solved[][5], int nums[][6], int matrix[][5][5])
{
	int	i;
	int	j;

	i = 0;
	while (i <= 4)
	{
		j = 0;
		while (j <= 4)
		{
			solved[i][j] = 0;
			++j;
		}
		++i;
	}
	check_1(solved, nums, matrix);
	check_1_r_l(solved, nums, matrix);
	check_4_u_d(solved, nums, matrix);
	check_4_r_l(solved, nums, matrix);
	check_4_tricks(solved, nums, matrix);
	check_3(solved, nums, matrix);
	check_3_tricks(nums, matrix);
}

void	check_1(int solved[][5], int nums[][6], int matrix[][5][5])
{	
	int	j;

	j = 0;
	while (++j <= 4)
	{
		if (nums[0][j] == 1)
		{
			solved[1][j] = 4;
			clear_nums(matrix, 1, j, 4);
		}
	}
	j = 0;
	while (++j <= 4)
	{
		if (nums[5][j] == 1)
		{
			solved[4][j] = 4;
			clear_nums(matrix, 4, j, 4);
		}
	}
}	

void	check_1_r_l(int solved[][5], int nums[][6], int matrix[][5][5])
{
	int	i;

	i = 0;
	while (++i <= 4)
	{
		if (nums[i][0] == 1)
		{
			solved[i][1] = 4;
			clear_nums(matrix, i, 1, 4);
		}
	}
	i = 0;
	while (++i <= 4)
	{
		if (nums[i][5] == 1)
		{
			solved[i][4] = 4;
			clear_nums(matrix, i, 4, 4);
		}
	}
}

void	check_4_u_d(int solved[][5], int nums[][6], int matrix[][5][5])
{	
	int	i;
	int	j;
	int	k;	

	j = 0;
	while (++j <= 4)
	{
		i = 0;
		if (nums[0][j] == 4)
		{
			while (++i <= 4)
			{
				solved[i][j] = i;
				clear_nums(matrix, i, j, i);
			}
		}
	}
	j = 0;
	while (++j <= 4)
	{
		i = 0;
		k = 4;
		if (nums[5][j] == 4)
		{
			while (++i <= 4)
			{
				solved[k][j] = i;
				clear_nums(matrix, k--, j, i);
			}
		}
	}	
}

void	check_4_r_l(int solved[][5], int nums[][6], int matrix[][5][5])
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (++i <= 4)
	{
		j = 0;
		if (nums[i][0] == 4)
		{
			while (++j <= 4)
			{
				solved[i][j] = j;
				clear_nums(matrix, i, j, j);
			}
		}
	}
	i = 0;
	while (++i <= 4)
	{
		j = 0;
		k = 4;
		if (nums[i][5] == 4)
		{
			while (++j <= 4)
			{
				solved[i][k] = j;
				clear_nums(matrix, i, k--, j);
			}
		}
	}	
}
