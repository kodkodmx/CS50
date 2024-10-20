import random

def main():
    level = get_level()
    game = 1
    question = 1
    score = 0
    result = -1
    while game <= 10:
        x = generate_integer(level)
        y = generate_integer(level)
        while question <= 3:
            try:
                result = int(input(str(x) + " + " + str(y) + " = "))
            except ValueError:
                print("EEE")
                question += 1
            else:
                if result == (x + y):
                    score += 1
                    game += 1
                    break
                else:
                    print("EEE")
                    question += 1
        question = 1
        if result == -1 or (x + y) != result:
            print(str(x) + " + " + str(y) + " = " + str(x + y))
            game += 1
    print(score)
    return True


def get_level():
    while True:
        try:
            level=int(input("Level: "))
            if 4 > level > 0:
                break
        except:
            pass
    return level


def generate_integer(level):
    if level == 1:
        n = random.randint(0, 9)
    elif level == 2:
        n = random.randint(10, 99)
    else:
        n = random.randint(100, 999)

    return n


if __name__ == "__main__":
    main()