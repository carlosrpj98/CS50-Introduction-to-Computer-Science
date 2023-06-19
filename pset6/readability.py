from cs50 import get_string
# Prompting a text from the user
while True:
    text = get_string('text: ')
    if len(text) > 0:
        break
# Counting the number of words, letters, and sentences
words = len(text.split())
sentences = text.count('.') + text.count('!') + text.count('?')
letters = sum(i.isalpha() for i in text)

l = letters / words * 100
s = sentences / words * 100

index = round(0.0588 * l - 0.296 * s - 15.8)

# Printing the grade
if index < 1:
    print('Before Grade 1')
elif index >= 16:
    print('Grade 16+')
else:
    print(f'Grade: {index}')
{
}


