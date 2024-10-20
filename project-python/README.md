# Number Guessing Game
#### Video Demo: https://youtu.be/cCEAVCwiT24

## Description:
The Number Guessing Game is a Python program that allows the user to guess a randomly generated number within a specified range. The user is given a limited number of attempts to guess the correct number.

## How to Play:
1. Run the program.
2. Enter the maximum number for the range when prompted.
3. Guess the number within the given range.
4. Receive feedback on whether your guess is correct, too high, or too low.
5. Repeat until you guess the correct number or run out of attempts.

## Files:
- **project.py:**
  - This is the main script containing the game logic.
  - It includes the following functions:

    - **`main()`**:
      - Orchestrates the flow of the game, taking user input, generating a random number, and managing the guessing process.

    - **`validate(value)`**:
      - Validates user input to ensure it is a valid integer between 1 and 100.
      - Returns `True` if the input is invalid, prompting the user to enter a valid number.

    - **`generate(max_value)`**:
      - Generates a random number between 1 and the specified maximum value.
      - Returns the randomly generated number.

    - **`guess(user_guess, num)`**:
      - Compares the user's guess with the correct number.
      - Returns feedback indicating whether the guess is correct, too high, or too low.

    - **`opportunities(max_value)`**:
      - Calculates the number of attempts based on the maximum range (13% of the range).
      - Returns the number of attempts, rounded up to the nearest whole number.

- **test_project.py:**
  - This file contains test cases for the functions in `project.py`.
  - It uses the `pytest` library to assert the correctness of the `guess`, `validate`, and `opportunities` functions.

- **requirements.txt:**
  - This file lists the pip-installable libraries required for the project.
  - To install the dependencies, run:
    ```
    pip install -r requirements.txt
    ```

- **README.md:**
  - This file provides detailed information about the project, including how to play the game, the purpose of each function, design choices, instructions on running the program and tests, and installation of required libraries.

## Design Choices:
- **Input Validation:**
  - The program validates user input to ensure it is a valid integer between 1 and 100.
  - If the input is invalid, the user is prompted to enter a valid number.

- **Guess Feedback:**
  - The user receives feedback on their guess, indicating whether the correct number is smaller or larger.
  - The program also notifies the user when they guess the correct number.

- **Limited Attempts:**
  - The game limits the number of attempts based on the maximum range to add challenge and excitement.

## How to Run:
1. Ensure you have Python installed on your system.
2. Install the required libraries by running:
```
pip install -r requirements.txt
```
3. Download the `project.py` and `test_project.py` files.
4. Open a terminal or command prompt and navigate to the directory containing the scripts.
5. Run the tests by entering `pytest test_project.py`.
6. If all tests pass, your functions are working correctly.
7. Run the game by entering `python project.py` and enjoy!

