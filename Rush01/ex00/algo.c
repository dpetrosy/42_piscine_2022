/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 19:29:04 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/02/13 22:59:37 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		check_solved(int solved[][5]);
void	check_1_4(int solved[][5], int nums[][6], int matrix[][5][5]);
void	clear_nums(int matrix[][5][5], int i, int j, int num);
int		check_only_in_nums(int solved[][5], int nums[][6], int matrix[][5][5]);
void	check_only_in_nums1(int solved[][5], int nums[][6], int matrix[][5][5]);
int		check_3_line(int solved[][5], int nums[][6], int matrix[][5][5]);
void	check_3_line1(int solved[][5], int nums[][6], int matrix[][5][5]);

int	check_solved(int solved[][5])
{
	int	i;
	int	j;

	i = 0;
	while (++i <= 4)
	{
		j = 0;
		while (++j <= 4)
		{
			if (solved[i][j] == 0)
			{
				return (1);
			}
		}
	}	
	return (0);
}

int	check_only(int solved[][5], int nums[][6], int matrix[][5][5])
{
	int	i;
	int	j;
	int	k;
	int	num;
	int	count;

	count = 0;
	i = 0;
	while (++i <= 4)
	{
		j = 0;
		while (++j <= 4)
		{
			k = 0;
			while (++k <= 4)
			{
				if (matrix[i][j][k] > 0)
				{
					++count;
					num = matrix[i][j][k];
				}
			}
			if (count == 1)
			{
				solved[i][j] = num;
				clear_nums(matrix, i, j, num);
				return (1);
			}
			count = 0;
		}
	}
	return (0);
}

int	check_only_in_nums(int solved[][5], int nums[][6], int matrix[][5][5])
{
	int	i;
	int	j;
	int	count;
	int	arr[3];

	i = 0;
	while (i <= 2)
	{
		arr[i] = 0;
		++i;
	}
	count = 0;
	i = 0;
	while (++i <= 4)
	{
		j = 0;
		while (++j <= 4)
		{
			if (matrix[i][j][3] == 3)
			{
				++count;
				arr[1] = i;
				arr[2] = j;
			}
		}
		if (count == 1)
		{
			solved[arr[1]][arr[2]] = 3;
			clear_nums(matrix, arr[1], arr[2], 3);
			return (1);
		}
		count = 0;
	}
	check_only_in_nums1(solved, nums, matrix);
	return (0);
}

void	check_only_in_nums1(int solved[][5], int nums[][6], int matrix[][5][5])
{
	int	i;
	int	j;
	int	count;
	int	arr[3];

	i = 0;
	while (i <= 2)
	{
		arr[i] = 0;
		++i;
	}
	count = 0;
	j = 0;
	while (++j <= 4)
	{
		i = 0;
		while (++i <= 4)
		{
			if (matrix[i][j][3] == 3)
			{
				++count;
				arr[1] = i;
				arr[2] = j;
			}
		}
		if (count == 1)
		{
			solved[arr[1]][arr[2]] = 3;
			clear_nums(matrix, arr[1], arr[2], 3);
			return ;
		}
		count = 0;
	}
	return ;
}

int	check_3_line(int solved[][5], int nums[][6], int matrix[][5][5])
{
	int	i;

	check_3_line1(solved, nums, matrix);
	i = 0;
	while (++i <= 4)
	{
		if (nums[i][0] == 3 && solved[i][4] == 4 && solved[i][3] == 3)
		{
			solved[i][1] = 2;
			clear_nums(matrix, i, 1, 2);
			solved[i][2] = 1;
			clear_nums(matrix, i, 2, 1);
			return (1);
		}
		if (nums[i][5] == 3 && solved[i][1] == 4 && solved[i][2] == 3)
		{
			solved[i][4] = 2;
			clear_nums(matrix, i, 4, 2);
			solved[i][3] = 1;
			clear_nums(matrix, i, 3, 1);
			return (1);
		}
	}
	return (0);
}

void	check_3_line1(int solved[][5], int nums[][6], int matrix[][5][5])
{
	int	i;

	i = 0;
	while (++i <= 4)
	{
		if (nums[0][i] == 3 && solved[4][i] == 4 && solved[3][i] == 3)
		{
			solved[1][i] = 2;
			clear_nums(matrix, 1, i, 2);
			solved[2][i] = 1;
			clear_nums(matrix, 2, i, 1);
			return ;
		}
		if (nums[5][i] == 3 && solved[1][i] == 4 && solved[2][i] == 3)
		{
			solved[4][i] = 2;
			clear_nums(matrix, 4, i, 2);
			solved[3][i] = 1;
			clear_nums(matrix, 3, i, 1);
			return ;
		}
	}
	return ;
}
