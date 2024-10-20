def main():
    plate = input("Plate: ")
    if is_valid(plate):
        print("Valid")
    else:
        print("Invalid")


def is_valid(s):
    numbers = True
    if not(6 >= len(s) >= 2):
        return False
    if not(s[0].isalpha() and s[1].isalpha()):
        return False
    if not(s.isalnum()):
        return False
    for i in range(len(s)):
            if (s[i].isnumeric()):
                k = i
                if numbers and s[i] == "0":
                    return False
                else:
                    numbers = False
                    for j in range(k, (len(s))):
                        if s[j].isalpha():
                            return False
    else:
        return True


if __name__ == "__main__":
    main()