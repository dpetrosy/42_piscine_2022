#ifndef SOLVER_H
#define SOLVER_H


/*
 * Brief: display readed words
 */
int		display_words(char *dict, char nums_3[], int size);

/*
 * Brief: control solving problen with while llop
 */
void	solver(char *dict, char number[], int size);

/*
 * Brief: get first numbers div number to 3
 */
void	get_nums3(char number[], char nums_3[]);

/*
 * Brief: shift string left by shift size
 */
void	shift_left(char number[], int shift);

/*
 * Brief: fill string with given symbol
 */
void	fill_0(char *str, char c);


#endif   /* SOLVER_H */