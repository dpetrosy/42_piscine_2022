/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 02:25:48 by dpetrosy          #+#    #+#             */
/*   Updated: 2022/02/24 03:25:59 by dpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>

void	ft_putstr(char *str);

typedef int	t_bool;

t_bool	ft_is_even(int nbr);

# define TRUE 1

# define SUCCESS 0

# define FALSE 0

# define EVEN(nbr) (nbr % 2 == 0) 

# define EVEN_MSG "I have an even number of arguments.\n"

# define ODD_MSG "I have an odd number of arguments.\n"

#endif /* FT_BOOLEAN_H */
