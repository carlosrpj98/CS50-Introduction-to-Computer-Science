from cs50 import get_float

# Getting the change value from the user
while True:
    change = get_float("Change owed: ")
    if change > 0:
        break

# Loop that pass through all the coin values
change = change * 100
count = 0
for x in [25, 10, 5, 1]:
    while change >= x:
        change -= x
        count += 1

print(f"{count}")