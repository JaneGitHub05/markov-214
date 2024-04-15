import numpy as np
import pandas as pd
import sys

# GOAL: Generate line of x words given an initial word + track runtime between two solutions
#* THIS IS A FIRST-ORDER MODEL: only considers T(n-1) for T(n) - "memoryless" property of a stochastic process

######## Take in input #########
# Get user input (initial word, and number of words to generate after it)
initial = input()
if initial == "newline":
    initial = "\n"
print(f"{initial}")
x = int(input())
print(f"{x}")
# TODO: Get user input (generate (iterate) or predict (diagonalize))
print(f"{sys.argv[1]}")

# Get ordered list of words
words = ["\n"]
line = input()
for word in line.split(','):
    words.append(word)
    # print(f"{word} ")
# record transition matrix
n = len(words)
print(f"{n} x {n}")
matrix = [[] for i in range(n)]
# npmatrix = np.zeros((n, n))

for i in range(0, n):
    try:
        row = input()
        for val in row.split(','):
            matrix[i].append(float(val))
            # print(f"{val} ")
    except EOFError: # reached end of file
        break

######## Functionality ######## 
#* 1. Get transformation matrix and an initial state
# transpose matrix
tmatrix = np.transpose(matrix)

# print(f"{tmatrix}")

# generate initial state vector
initialState = np.array([0 for i in range(n)])
initialState[words.index(initial)] = 1
# transform input from row to column vector
initialState.shape = (n, 1)
# print(f"{input}")

#* 2. Predict resultant state after n steps using - 
# TODO: Solution 1: for-loop OR recursive
nextState = initialState
for i in range(x):
    # print(f"{nextState}")
    nextState = np.matmul(tmatrix, nextState)
    # transform nextState from nD into 1D array
    nextState1D = np.ndarray.flatten(nextState)
    # print(f"{pd.Series(nextState1D).idxmax()}: {words[pd.Series(nextState1D).idxmax()]}")
    print(f"{words[pd.Series(nextState1D).idxmax()]} ", end="")
    # generate next state vector based on what word had the highest probability of appearing
    nextWord = pd.Series(nextState1D).idxmax()
    nextState = [0 for i in range(n)]
    nextState[nextWord] = 1

# TODO: Solution 2: Diagonalize, then raise to power
eigenvalues, eigenvectors = np.linalg.eig(tmatrix)
eigenvalues_powered = np.power(eigenvalues, x)
reconstructed_matrix = eigenvectors @ np.diag(eigenvalues_powered) @ np.linalg.inv(eigenvectors)
final_matrix = reconstructed_matrix @ initialState

index_of_largest = np.argmax(final_matrix)
predicted_word = words[index_of_largest]
print(f"{predicted_word}")
    