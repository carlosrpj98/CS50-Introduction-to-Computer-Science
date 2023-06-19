from cs50 import get_int

# Prompting the height from the user
while True:
    height = get_int("A number between 1 and 8: ")
    if height in range(1, 9):
        break

# Printing the pyramid
for printing in range(height):
    print((height - printing - 1) * " ", end="")
    print((printing + 1) * "#")
