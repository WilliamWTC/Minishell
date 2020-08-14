#!/bin/sh
# Check form memory leaks
valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes --show-reachable=yes --verbose --gen-suppressions=all --log-file=valgrind-out.txt ./minishell