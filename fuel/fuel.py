while True:
    fraction = input("Fraction: ")
    try:
        num = fraction.split("/")
        if int(num[0]) > int(num[1]):
            continue
        else:
            result = int(num[0])/int(num[1])
            if result <= .01:
                print("E")

            elif result >= .99:
                print("F")
            else:
                print(f"{result*100:.0f}%")
    except (ValueError, ZeroDivisionError):
        continue
    else:
        break
