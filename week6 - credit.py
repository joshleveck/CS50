import re
from cs50 import get_string
from sys import exit


num = get_string("Number: ")

n = len(num)
y = 0
if n % 2 == 0:
    for i in range(int(n / 2)):
        x = int(num[i * 2]) * 2
        x = str(x)
        for j in range(len(x)):
            y += int(x[j])
    for i in range(int(n / 2)):
        y += int(num[(i * 2) + 1])

elif n % 2 == 1:
    for i in range(int(n / 2) - 1):
        x = int(num[(i * 2) + 1]) * 2
        x = str(x)
        for j in range(len(x)):
            y += int(x[j])
    for i in range(int((n / 2) - 1)):
        y += int(num[i * 2])
print(y)

if y % 10 == 0:
    if re.search("^34", num) or re.search("^37", num):
        print("AMEX")
        exit(0)
    elif re.search("^51", num) or re.search("^52", num) or re.search("^53", num) or re.search("^54", num) or re.search("^55", num):
        print("MASTERCARD")
        exit(0)
    elif re.search("^4", num):
        print("VISA")
        exit(0)

print("INVALID")