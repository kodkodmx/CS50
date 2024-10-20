# TODO
import cs50


# Main Function make the math and print the result
def main():

    # Ask for the original Text
    text = cs50.get_string("Text: ")

    # Call the functions
    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)

    # Make the Math for the Coleman-Liau index with the formula index = 0.0588 * L - 0.296 * S - 15.8
    # print(letters, words, sentences)
    L = (letters / words) * 100
    S = (sentences / words) * 100
    # print(L, S)
    index = (0.0588 * L) - (0.296 * S) - 15.8

    # Prints the results
    if (index > 16):
        print("Grade 16+")

    if (index < 1):
        print("Before Grade 1")

    if ((index > 1) and (index < 16)):
        print("Grade", round(index))


# Function that count the letters
def count_letters(text):
    letters = 0
    for j in range(27):
        for i in range(len(text)):
            if (text[i] == chr(65 + j) or text[i] == chr(97 + j)):
                letters += 1
    return letters


# Function that count the words
def count_words(text):
    words = 1
    for i in range(len(text)):
        if (text[i] == chr(32)):
            words += 1
    return words


# Function that count the sentenses
def count_sentences(text):
    sentences = 0
    for i in range(len(text)):
        if ((text[i] == chr(33)) or (text[i] == chr(46)) or (text[i] == chr(63))):
            sentences += 1
    return sentences


if __name__ == "__main__":
    main()