make && gcc -Wall -Wextra -Werror -fsanitize=address -g3 -o tester test.c libftprintf.a && ./tester
