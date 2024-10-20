# TODO
import cs50


def main():

    # Ask how many cents the customer is owed
    cents = get_cents()

    # Calculate the number of quarters to give the customer
    quarters = calculate_quarters(cents)
    cents -= quarters * 25

    # Calculate the number of dimes to give the customer
    dimes = calculate_dimes(cents)
    cents -= dimes * 10

    # Calculate the number of nickels to give the customer
    nickels = calculate_nickels(cents)
    cents -= nickels * 5

    # Calculate the number of pennies to give the customer
    pennies = calculate_pennies(cents)
    cents -= pennies * 1

    # Sum coins
    coins = quarters + dimes + nickels + pennies

    # Print total number of coins to give the customer
    print(int(coins))


def get_cents():
    cents = 0.00
    # ask for cents owed is not valid answer ask again
    while (True):
        cents = cs50.get_float("Change owed:")

        if (cents >= 0.00):
            break
    return round(cents*100)


def calculate_quarters(cents):

    # calculate the number of quarters to give back
    quarters = cents // 25
    return quarters


def calculate_dimes(cents):

    # calculate the number of dimes to give back
    dimes = cents // 10
    return dimes


def calculate_nickels(cents):

    # calculate the number of nickels to give back
    nickels = cents // 5
    return nickels


def calculate_pennies(cents):

    # calculate the number of pennies to give back
    pennies = cents // 1
    return pennies


if __name__ == "__main__":
    main()