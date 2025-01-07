substitution: substitution.c 
	gcc -Wall -Wextra -std=c11 -o substitution substitution.c -lcs50

clean: 
	rm -f substitution
