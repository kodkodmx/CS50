# TODO
import cs50


def main():
    while (True):
        # ask for int as a height
        height = cs50.get_int("Height:")

        # checks if height is in range
        if height in range(1, 9):
            buildPyramid(height)
            break


# the build pyramid function
def buildPyramid(height):
    # loops for rows
    for i in range(height):
        # print spaces
        for j in range(height - i - 1):
            print(" ", end="")
        # print bricks
        for k in range(i + 1):
            print("#", end="")
        # print a new line
        print("")


if __name__ == "__main__":
    main()