import sys, csv

def main():
    if len(sys.argv) < 3:
        sys.exit("Too few command-line arguments")
    elif len(sys.argv) > 3:
        sys.exit("Too many command-line arguments")
    elif sys.argv[1].endswith(".csv") == False:
        sys.exit("Not a CSV file")
    else:
        try:
            with open(sys.argv[2], 'w') as csvfile:
                fieldnames = ['first', 'last', 'house']
                writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
                writer.writeheader()
            with open(sys.argv[1], 'r') as csvfile:
                reader = csv.DictReader(csvfile)
                for row in reader:
                    last, first = row['name'].split(', ')
                    house = row['house']
                    with open(sys.argv[2], 'a', newline='') as csvfile:
                        writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
                        writer.writerow({'first':first, 'last':last, 'house':house})
        except:
            sys.exit("Could not read " + sys.argv[1])

if __name__ == "__main__":
    main()