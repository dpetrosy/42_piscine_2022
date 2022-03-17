/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_words.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 04:33:19 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/02/24 19:09:28 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include "../include/display_words.h"

char	*g_dict;

int	display_words(char *dict, char nums_3[], int size)
{
	char	*line;
	char	str[100];

	nums_3[3] = '\0';
	g_dict = ft_strcpy(str, "/Users/dpetrosy/Rush02/ex00/data/");
	g_dict = ft_strcat(g_dict, dict);
	line = (char *)malloc(280);
	if (line == NULL)
	{
		ft_putstr("Memory allocation error\n");
		return (1);
	}
	line[255] = '\0';
	fill_0(line, '#');
	if (open_and_read(nums_3, size, line) == 0)
	{
		free(line);
		return (1);
	}
	else
	{
		free(line);
		return (0);
	}
}

int		g_fd;

int	open_and_read(char nums_3[], int size, char *line)
{
	int		sz;
	int		i;
	char	buf[1];
	int		found;

	found = 0;
	g_fd = open(g_dict, O_RDONLY | O_EXCL);
	if (g_fd == -1)
	{
		ft_putstr("Dict Error\n");
		return (0);
	}	
	i = 0;
	while ((sz = read(g_fd, buf, 1) > 0) && found == 0)
	{
		if (buf[0] != '\n')
		{
			line[i] = buf[0];
			++i;
		}
		else
		{
			line[i] = '\0';
			i = 0;
			found = check_line(line, nums_3, size);
		}
	}
	if (sz < 0)
	{	
		close(g_fd);
		return (0);
	}	
	close(g_fd);
	return (1);
}

int	check_line(char *line, char nums_3[], int size)
{
	char	c;

	if (nums_3[1] == '#')
	{
		if (find_number_only(line, nums_3))
		{
			if (find_ten_power(line, nums_3, size))
				return (1);
			else
				return (0);
		}
		else
			return (0);
	}
	else if (nums_3[2] == '#')
	{
		if (find_2_numbers(line, nums_3, size))
		{
			if (find_ten_power(line, nums_3, size))
				return (1);
			else
				return (0);
		}
		else
			return (0);
	}
	else if (nums_3[2] != '#')
	{
		if (find_number_only(line, nums_3))
		{
			ft_putstr("hundred ");
			nums_3[0] = nums_3[1];
			nums_3[1] = nums_3[2];
			nums_3[2] = '#';
			nums_3[3] = '\0';
			if (find_2_numbers(line, nums_3, size))
			{
				if (find_ten_power(line, nums_3, size))
					return (1);
				else
					return (0);
			}
			else
				return (0);
		}
		else
			return (0);
	}
	return (0);
}

int	find_number_only(char *line, char nums_3[])
{
	int		i;
	int		j;
	char	str[100];

	fill_0(str, '#');
	i = 0;
	j = 0;
	while (line[i] == ' ')
		++i;
	while (line[i] >= '0' && line[i] <= '9')
	{
		str[j] = line[i];
		++i;
		++j;
	}
	str[j] = '\0';
	if (str[0] == nums_3[0] && str[1] == '\0')
	{
		while (line[i] == ' ')
			++i;
		if (line[i] != ':')
			return (0);
		else
		{
			++i;
			while (line[i] == ' ')
				++i;
			while (line[i] >= 33 && line[i] <= 126)
			{
				ft_putchar(line[i]);
				++i;
			}
			ft_putchar(' ');
			return (1);
		}
	}
	else
		return (0);
}

int	find_ten_power(char *line, char nums_3[], int size)
{
	int		sz;
	int		i;
	char	buf[1];
	int		found;

	found = 0;
	i = 0;
	while ((sz = read(g_fd, buf, 1) > 0) && found == 0)
	{
		if (buf[0] != '\n')
		{
			line[i] = buf[0];
			++i;
		}
		else
		{
			line[i] = '\0';
			i = 0;
			found = check_ten_power(line, nums_3, size);
		}
	}
	if (sz < 0 || found == 0)
	{
		return (0);
	}	
	return (1);
}

int	check_ten_power(char *line, char nums_3[], int size)
{
	int		i;
	int		j;
	char	str[100];
	char	ten_power[50];

	ft_power(ten_power, size);
	fill_0(str, '#');
	i = 0;
	j = 0;
	while (line[i] == ' ')
		++i;
	while (line[i] >= '0' && line[i] <= '9')
	{
		str[j] = line[i];
		++i;
		++j;
	}
	str[j] = '\0';
	if (ft_strcmp(str, ten_power) == 0)
	{
		while (line[i] == ' ')
			++i;
		if (line[i] != ':')
			return (0);
		else
		{
			++i;
			while (line[i] == ' ')
				++i;
			while (line[i] >= 33 && line[i] <= 126)
			{
				ft_putchar(line[i]);
				++i;
			}
			ft_putchar(',');
			ft_putchar(' ');
			return (1);
		}
	}
	else
		return (0);
}

void	ft_power(char *ten_power, int size)
{
	int	i;

	i = 0;
	ten_power[0] = '1';
	++i;
	while (i <= size)
	{
		ten_power[i] = '0';
		++i;
	}
	ten_power[i] = '\0';
}

int	find_2_numbers(char *line, char nums_3[], int size)
{
	int		i;
	int		j;
	char	str[100];
	char	c;

	fill_0(str, '#');
	i = 0;
	j = 0;
	while (line[i] == ' ')
		++i;
	while (line[i] >= '0' && line[i] <= '9')
	{
		str[j] = line[i];
		++i;
		++j;
	}
	str[j] = '\0';
	if (str[0] == nums_3[0] && str[1] == nums_3[1] && str[2] == '\0')
	{
		while (line[i] == ' ')
			++i;
		if (line[i] != ':')
			return (0);
		else
		{
			++i;
			while (line[i] == ' ')
				++i;
			while (line[i] >= 33 && line[i] <= 126)
			{
				ft_putchar(line[i]);
				++i;
			}
			ft_putchar('-');
			return (1);
		}
	}
	if (nums_3[0] > '1' && nums_3[1] >= '1' && str[2] == '\0')
	{	
		c = nums_3[1];
		nums_3[1] = '0';
		if (read_file(nums_3, size, line))
		{
			nums_3[1] = '#';
			nums_3[2] = '#';
			nums_3[3] = '\0';
			nums_3[0] = c;
			if (read_file(nums_3, size, line))
			{
				return (1);
			}
			else
				return (0);
		}
		else
			return (0);
	}
	return (0);
}

int	read_file(char nums_3[], int size, char *line)
{
	int		sz;
	int		i;
	char	buf[1];
	int		found;

	found = 0;
	i = 0;
	sz = 0;
	buf[0] = '#';
	g_fd = open(g_dict, O_RDONLY | O_EXCL);
	if (g_fd == -1)
	{
		ft_putstr("Dict Error\n");
		return (0);
	}	
	while ((sz = read(g_fd, buf, 1) > 0) && found == 0)
	{
		if (buf[0] != '\n')
		{
			line[i] = buf[0];
			++i;
		}
		else
		{
			line[i] = '\0';
			i = 0;
			found = check_line_2(line, nums_3, size);
		}
	}
	if (sz < 0 || found == 0)
	{
		return (0);
	}	
	return (1);
}

int	check_line_2(char *line, char nums_3[], int size)
{
	if (nums_3[1] == '#')
	{
		if (find_number_only(line, nums_3))
		{
			if (find_ten_power(line, nums_3, size))
				return (1);
			else
				return (0);
		}
		else
			return (0);
	}
	else if (nums_3[2] == '#')
	{
		if (find_2_numbers(line, nums_3, size))
		{
			return (1);
		}
		else
			return (0);
	}
	return (0);
}
