import sys, os
from PIL import Image, ImageOps

def main():
    if len(sys.argv) < 3:
        sys.exit("Too few command-line arguments")
    elif len(sys.argv) > 3:
        sys.exit("Too many command-line arguments")
    elif os.path.splitext(sys.argv[1].lower())[1] != ".jpg" and os.path.splitext(sys.argv[1].lower())[1] != ".jpeg" and os.path.splitext(sys.argv[1].lower())[1] != ".png" or os.path.splitext(sys.argv[2].lower())[1] != ".jpg" and os.path.splitext(sys.argv[2].lower())[1] != ".jpeg" and os.path.splitext(sys.argv[2].lower())[1] != ".png":
        sys.exit("Invalid input")
    elif os.path.splitext(sys.argv[1].lower())[1] != os.path.splitext(sys.argv[2].lower())[1]:
        sys.exit("Input and output have different extensions")
    else:
        try:
            before = Image.open(sys.argv[1])
        except FileNotFoundError:
            sys.exit("Input does not exist")
        else:
            shirt = Image.open('shirt.png')
            shirt_size = shirt.size

            before1 = ImageOps.fit(before,shirt_size)
            before1.paste(shirt, shirt)

            before1.save(sys.argv[2])

if __name__ == "__main__":
    main()