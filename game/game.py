import random

while True:
        max = input("Level: ")
        try:
            int(max) > 1
            number = random.randint(1,int(max))
        except ValueError:
            continue
        else:
            while True:
                guess = input("Guess: ")
                try:
                    int(guess) > 1
                except ValueError:
                    continue
                else:
                    if int(guess) < number:
                        print("Too small!")
                        continue
                    elif int(guess) > number:
                        print("Too large!")
                        continue
                    else:
                        print("Just right!")
                        break
        break






