/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 16:28:49 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/02/13 23:11:54 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	display_solved(int solved[][5]);
void	ft_putstr(char *str);
void	ft_putchar(char c);
void	take_numbers(int arr[][6], char *arg);
void	fill_matrix(int arr[][5][5]);
void	solver(int nums[][6], int matrix[][5][5]);
void	check_1_4(int solved[][5], int nums[][6], int matrix[][5][5]);
int		check_solved(int solved[][5]);
int		check_only(int solved[][5], int nums[][6], int matrix[][5][5]);
int	check_only_in_nums(int solved[][5], int nums[][6], int matrix[][5][5]);
int	check_3_line(int solved[][5], int nums[][6], int matrix[][5][5]);

void	matrix_and_numbers(char **argv)
{	
	char	*argument;
	int	input_numbers[6][6];
	int	matrix[5][5][5];

	argument = argv[1];
	take_numbers(input_numbers, argument);
	fill_matrix(matrix);
	solver(input_numbers, matrix);
}

void	solver(int nums[][6], int matrix[][5][5])
{	
	int	i;
	int	solved[5][5];

	check_1_4(solved, nums, matrix);
	i = 0;
	while (i++ < 32)
	{
		if (check_solved(solved))
		{
			if (check_only(solved, nums, matrix) != 1)
			{
				if (check_only_in_nums(solved, nums, matrix) != 1)
				{
					if (check_3_line(solved, nums, matrix) != 1)
						ft_putstr("Error\n");
					else
						continue ;
				}
				else
				{
					continue ;
				}
			}
			else
			{
				continue ;
			}
		}
	}
	display_solved(solved);
}
