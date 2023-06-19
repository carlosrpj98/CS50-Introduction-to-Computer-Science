from cs50 import get_int

# Prompting from the user the height
while True:
    answer = get_int("Type a number between 1 and 8 ")
    if answer in range(1, 9):
        break

# Printing the blocks of the pyramid
for printing in range(answer):
    print((answer - (printing + 1)) * " ", end="")
    print((printing + 1) * "#", end="  ")
    print((printing + 1) * "#")
    print("")
    if printing < answer - 1:
        print()