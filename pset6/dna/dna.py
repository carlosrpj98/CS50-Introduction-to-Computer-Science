from sys import argv, exit
import csv


def main():
    # Checking if the imput is correct
    if len(argv) != 3:
        print("usage: python.py 'database.csv' 'sequence.txt'")
        exit(1)

    # Opening the the database file
    with open(argv[1], "r") as data:
        database = csv.DictReader(data)
        # creating a list containing the columns names
        STRs = database.fieldnames[1:]

        # Opening the sequence
        with open(argv[2], "r") as sequences:
            sequence = sequences.read()
            list = []
            for title in STRs:
                length = len(title)
                total = substring(sequence, title, length)
                list.append(total)

            # The loop will look for numbers iquals to the numbers of the list
            # at every row in each column, and count when found, if the count is equals
            # to the number of nucleotides, it's a match!
            for row in database:
                count = 0
                for column in range(len(STRs)):
                    if int(row[STRs[column]]) == int(list[column]):
                        count += 1
                    if count == len(STRs):
                        print(row["name"])
                        exit(0)
            print("No match")
            exit(1)

# Function that returns the greater sequence of each nucleotides


def substring(sequence, STR, length):
    total = 0
    for x in range(len(sequence)):
        count = 0
        if sequence[x:x+length] == STR:
            start = x
            while sequence[start:start+length] == STR:
                count += 1
                start += length
            if count > total:
                total = count
    return total


main()