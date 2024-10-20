import sys
def main():
    if len(sys.argv) == 1:
        sys.exit("Too few command-line arguments")
    elif len(sys.argv) > 2:
        sys.exit("Too many command-line arguments")
    elif sys.argv[1].endswith(".py") == False:
        sys.exit("Not a Python file")
    else:
        try:
            with open(sys.argv[1]) as file:
                count = 0
                for line in file:
                    if line.lstrip(" ") == ("\n") or line.lstrip(" ").startswith("#"):
                        pass
                    else:
                        count +=1
                print(count)
        except FileNotFoundError:
            sys.exit("File does not exist")
if __name__ == "__main__":
    main()