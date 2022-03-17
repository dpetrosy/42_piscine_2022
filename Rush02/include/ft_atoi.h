#ifndef FT_ATOI_H
#define FT_ATOI_H


/*
 * Brief: work like atoi function, bring integer from string 
 */
void	ft_atoi(char num[], char *str, int i, int j);

/*
 * Brief: check 0 in integer 
 */
int		check_0(char *str, int i);

/*
 * Brief: skip whitespaces
 */
int		ft_isspace(char c);


#endif   /* FT_ATOI_H */
