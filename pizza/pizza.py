import sys, csv
from tabulate import tabulate

def main():
    if len(sys.argv) == 1:
        sys.exit("Too few command-line arguments")
    elif len(sys.argv) > 2:
        sys.exit("Too many command-line arguments")
    elif sys.argv[1].endswith(".csv") == False:
        sys.exit("Not a CSV file")
    else:
        try:
            with open(sys.argv[1]) as csvfile:
                reader = csv.reader(csvfile)
                table = []
                for row in reader:
                    table.append(row)
                headers = table[0]
                print(tabulate(table[1:], headers, tablefmt="grid"))
        except FileNotFoundError:
            sys.exit("File does not exist")

if __name__ == "__main__":
    main()