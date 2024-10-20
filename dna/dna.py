import csv
import sys


def main():

    # TODO: Check for command-line usage

    if len(sys.argv) != 3:
        exit("Usage: python dna.py data.csv sequence.txt")

    # TODO: Read database file into a variable

    # print(sys.argv[1])
    dataBase = []
    dFile = sys.argv[1]
    f = open(dFile, 'r')  # or 'with open(dFile, 'r') as f:
    reader = csv.DictReader(f)
    for person in reader:
        dataBase.append(person)
    # print(dataBase)

    # TODO: Read DNA sequence file into a variable

    # print(sys.argv[2])
    sFile = sys.argv[2]
    f = open(sFile, 'r')
    sequence = f.read()
    # print(sequence)

    # TODO: Find longest match of each STR in DNA sequence

    STR_list = list(dataBase[0].keys())[1:]
    # or 'del STR_list[0]' insted of [1:] ↑
    # print(STR_list)
    STR_matches = {}
    for STR in STR_list:
        STR_matches[STR] = longest_match(sequence, STR)
    # print(STR_matches)

    # TODO: Check database for matching profiles

    for person in dataBase:
        match = 0
        for STR in STR_list:
            if int(person[STR]) == STR_matches[STR]:
                match += 1
            # print(int(person[STR]), STR_matches[STR], match)
        if match == len(STR_list):
            print(person['name'])
            return

    print("No Match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
