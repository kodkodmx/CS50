def main():
    res = input("Input: ")
    print(shorten(res))




def shorten(word):
    for char in word:
        if char.lower() in ('a', 'e', 'i', 'o', 'u'):
            x = word.replace(char, "")
            word = x
    return word


if __name__ == "__main__":
    main()