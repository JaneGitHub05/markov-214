# GOAL: Generate line of n words given an initial word + track runtime between two solutions

######## Retrieve input #########

# Get ordered list of words
words = []
line = input()
for word in line.split():
    words.append(word)
    print(f"{word} ")
# Record transition matrix
rows, cols = len(words), len(words)
print(f"{rows} x {cols}")
matrix = [[]]
for r in range(0, rows - 1):
    try:
        row = input()
        for val in row.split():
            matrix[r].append(val)
            print(f"{val} ")
    except EOFError: # reached end of file
        break

for v in matrix:
    print(f"{v}")

######## Functionality ######## 
# 1. Take in transformation matrix and an input state
# 2. Predict resultant state after n steps using - 

# TODO: Solution 1: for-loop OR recursive

# TODO: Solution 2: Diagonalize, then raise to power