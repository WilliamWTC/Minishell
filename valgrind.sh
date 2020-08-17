#!/bin/sh
# Check form memory leaks
make re
clear
valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes --show-reachable=yes --verbose --gen-suppressions=all --log-file=valgrind-out.txt ./minishell