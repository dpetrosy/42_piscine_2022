#ifndef DISPLAY_WORDS_H
#define DISPLAY_WORDS_H


/*
 * Brief: display readed words
 */
int		display_words(char *dict, char nums_3[], int size);

/*
 * Brief: open and read dict
 */
int		open_and_read(char nums_3[], int size, char *line);

/*
 * Brief: check nums_3 and start finding
 */
int		check_line(char *line, char nums_3[], int size);

/*
 * Brief: find and print only one number in nums_3
 */
int		find_number_only(char *line, char nums_3[]);

/*
 * Brief: strcat function
 */
char	*ft_strcat(char *dest, char *src);

/*
 * Brief: strcpy function
 */
char	*ft_strcpy(char *dest, char *src);

/*
 * Brief: putstr function
 */
void	ft_putstr(char *str);

/*
 * Brief: fill string with given symbol
 */
void	fill_0(char *str, char c);

/*
 * Brief: putchar function
 */
void	ft_putchar(char c);

/*
 * Brief: find and print ten power
 */
int		find_ten_power(char *line, char nums_3[], int size);

/*
 * Brief: check and start finding ten power
 */
int		check_ten_power(char *line, char nums_3[], int size);

/*
 * Brief: ten power function
 */
void	ft_power(char *ten_power, int size);

/*
 * Brief: strcmp function
 */
int		ft_strcmp(char *s1, char *s2);

/*
 * Brief: start finding 2 numbers in nums_3
 */
int		find_2_numbers(char *line, char nums_3[], int size);

/*
 * Brief: reads file from the beginning
 */
int		read_file(char nums_3[], int size, char *line);

/*
 * Brief: check 2 numbers from nums_3 and control finding
 */
int		check_line_2(char *line, char nums_3[], int size);


#endif   /* DISPLAY_WORDS_H */
