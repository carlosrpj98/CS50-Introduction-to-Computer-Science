from cs50 import get_int, get_string

def main():
    while True:
        credit_number = get_int("Number: ")
        if len(str(credit_number)) > 0:
            break

    # Length of the credit number prompted
    length = len(str(credit_number))

    # If validaton is true, check the card flag
    if(validation(credit_number, length)):
        card(credit_number)
    else:
        print('INVALID')

def card(card):
    string = str(card)
    length = len(string)
    if length == 15 and string[:2] in ['34', '37']:
        print('AMEX')
    elif length == 16 and string[:2] in ['51', '52', '53', '54', '55']:
        print('MASTERCARD')
    elif length == 13 or 16 and string[:1] == '4':
        print('VISA')
    else:
        print('INVALID')

def validation(credit_number, length):
    # Setting the variables to the 'for' loop
    module, sum, total, excluded = 0, 0, 0, 0

    # Variable to store the card number in order to do not change the original variable
    number = credit_number

    for x in range(length):
        # Getting the last two digits
        module = (number % 100)

        # The last digit will be stored to the final step of the algorithm
        excluded += module % 10

        # The last but one number times two
        sum = int((module / 10)) * 2

        # If the result contain two digits, sum them
        if len(str(sum)) > 1:
            sum = int(sum / 10) + (sum % 10)
            total += sum
        else:
            total += sum

        # Updating the card number to the next step of the loop
        number = int(number / 100)

    if ((total + excluded) % 10 == 0):
        return True
    else:
        return False
main()

