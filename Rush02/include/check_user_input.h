#ifndef CHECK_INPUT_H
#define CHECK_INPUT_H


/*
 * Brief: check and control user input
 */
void	check_user_input(int argc, char **argv);

/*
 * Brief: control ft_atoi function calling
 */
int		check_input(char *str, char num[]);

/*
 * Brief: control solving problen with while llop
 */
void	solver(char *dict, char number[], int size);

/*
 * Brief: work like atoi function, bring integer from string 
 */
void	ft_atoi(char num[], char *str, int i, int j);

/*
 * Brief: fill string with given symbol
 */
void	fill_0(char *str, char c);

/*
 * Brief: putstr function
 */
void	ft_putstr(char *str);

/*
 * Brief: strlen function
 */
int		ft_strlen(char *str);


#endif   /* CHECK_INPUT_H */
