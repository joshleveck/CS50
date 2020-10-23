from cs50 import get_int
from sys import exit

def main():
    while True:
        n = get_int("Height: ")
        if n > 1 and n < 8:
            break
    x = n
    height(n, x)

def height(n, x):
    if n == 0:
        return
    height(n - 1, x)
    print(" " * (x - n), end="")
    print("#" * n, end="")
    print("  ", end="")
    print("#" * n)

main()

