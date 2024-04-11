import numpy as np
import pandas as pd
# GOAL: Generate line of n words given an initial word + track runtime between two solutions

######## Retrieve input #########
# Get user input (number of words to generate after a newline)
x = input()
print(f"{x}")

# Get ordered list of words
words = []
line = input()
for word in line.split(','):
    words.append(word)
    # print(f"{word} ")
# Record transition matrix
n = len(words)
print(f"{n} x {n}")
matrix = [[] for i in range(n)]
# m2 = np.zeros((n, n))

for i in range(0, n):
    try:
        row = input()
        for val in row.split(','):
            matrix[i].append(val)
            # print(f"{val} ")
    except EOFError: # reached end of file
        break

# m2 = matrix

# for v in m2:
#     print(f"{v}")

tmatrix = np.transpose(matrix)

for v in tmatrix:
    print(f"{v}")

######## Functionality ######## 
# 1. Take in transformation matrix and an input state
# 2. Predict resultant state after n steps using - 

# TODO: Solution 1: for-loop OR recursive

# TODO: Solution 2: Diagonalize, then raise to power