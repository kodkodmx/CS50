import re
import sys


def main():
    print(count(input("Text: ")))


def count(s):
    x = re.findall(r'^Um\b|\bum\b', s)
    return len(x)


if __name__ == "__main__":
    main()