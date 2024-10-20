# Importing the necessary libraries
import random  # For generating random numbers
import math    # For mathematical functions
import re      # For regular expressions

def main():
    # Get the maximum number from the user
    max_value = input("Maximum number? ")

    # Validate the user input for the maximum number
    while validate(max_value):
        max_value = input("Maximum number? ")
    else:
        # Generate a random number within the specified range
        num = generate(int(max_value))

    # Calculate the number of attempts based on the maximum range
    attempts = opportunities(int(max_value))
    # Uncomment the line below to print the initial attempts and the correct number
    # print(attempts, num)

    # Main loop for the user to make guesses
    while attempts > 0:
        # Get the user's guess
        user_guess = input("Your guess? ")

        # Validate the user input for the guess
        while validate(user_guess):
            user_guess = input("Your guess? ")
        else:
            # Compare the user's guess with the correct number
            result = guess(int(user_guess), num)
            print(result)
            attempts -= 1
            # Check if the user guessed the correct number
            if result == "You guessed the number":
                break
            # Provide feedback
            print(f"Remaining attempts: {attempts}")
    else:
        print("Out of attempts. The correct number was", num)

def validate(value):
    # Validate if the input value is a valid integer between 1 and 100
    if re.match(r"^[1-9][0-9]?$|^100$", value):
        return False
    else:
        print("Invalid input. Please enter a number between 1 and 100.")
        return True

def generate(max_value):
    # Generate a random number between 1 and the specified maximum value
    num = random.randrange(1, max_value + 1)
    return num

def guess(user_guess, num):
    # Compare the user's guess with the correct number and provide feedback
    if user_guess == num:
        return "You guessed the number"
    elif user_guess > num:
        return "The number is Smaller"
    else:
        return "The number is Bigger"

def opportunities(max_value):
    # Calculate the number of attempts based on the maximum range (13% of the range)
    attempts = max_value * 0.13
    return math.ceil(attempts)

# Execute the main function if this script is run as the main program
if __name__ == "__main__":
    main()
