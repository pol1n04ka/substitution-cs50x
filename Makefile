substitution: substitution.c 
	gcc -Wall -Wextra -std=c11 -o substitution substitution.c 

clean: 
	rm -f substitution
