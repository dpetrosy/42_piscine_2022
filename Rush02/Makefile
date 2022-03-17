
sources=main.c prints.c ft_atoi.c check_user_input.c solver.c display_words.c str_functions.c
src=$(sources:%.c=src/%.c)
objects=$(src:.c=.o)
compiler=gcc
executble=rush-02
lcovtest=rush-02.info

all : $(src) $(executble)

$(executble) : $(objects)
	$(compiler) $(objects) -g -o $@

.cpp.o :
	$(compiler) -c $< -g -o $@

clean :
	rm -f src/*.o

fclean :
	rm -f src/*.o $(executble) $(executble).*

debug :
	gdb $(executble)

gcov :
	$(compiler) $(src) --coverage -o $(executble)
	./$(executble)

lcov :
	lcov -t "program" -o $(lcovtest) -c -d .
	genhtml -o report $(lcovtest)
	rm -f *.gcda
	rm -f *.gcno
	rm -f $(lcovtest)
	rm -f $(executble) 
	open -a "Safari" report/index.html

clean_glcov :
	rm -f *.gcda
	rm -f *.gcno
	rm -f $(lcovtest)
	rm -rf report
	rm -f $(executble)

clean_gcda :
	rm -f *.gcda

clean_gcno :
	rm -f *.gcno
