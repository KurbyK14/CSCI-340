#!/bin/bash

PROG=./a.out

# ARG1 = N
# ARG2 = SEED
# ARG3 = MINX
# ARG4 = MAXX

# Run three simple test cases and generate output files
"$PROG" 10 1 1 50 > output-10-1-1-50
"$PROG" 10 2 1 50 > output-10-2-1-50
"$PROG" 20 3 1 50 > output-20-3-1-50
