def main():
        fraction = input("Fraction: ")
        print(gauge(convert(fraction)))


def convert(fraction):
    while True:
        try:
            num = fraction.split("/")
            result = int(num[0])/int(num[1])
            if result <= 1:
                return result*100
            else:
                fraction = input("Fraction: ")
                pass
        except (ValueError, ZeroDivisionError):
           fraction = input("Fraction: ")
           
def gauge(result):
    if result <= 1:
        return 'E'

    elif result >= 99:
        return 'F'
    else:
        return (f"{result:.0f}%")


if __name__ == "__main__":
    main()