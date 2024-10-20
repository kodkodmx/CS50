due=50
while True:
    print("Amount Due:", due)
    res = int(input("Insert Coin: "))
    if res == 25 or res == 10 or res == 5:
        due = due - res
        if due <= 0:
            print("Change Owed:", abs(due))
            break
    else:
        continue
