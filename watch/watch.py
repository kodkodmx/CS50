import re
import sys


def main():
    print(parse(input("HTML: ")))


def parse(s):
    if link := re.search(r"src=\"http://youtube.com/embed/(.{11})", s):
        result = (f"https://youtu.be/" + link.group(1))
    elif link := re.search(r"src=\"http://www.youtube.com/embed/(.{11})", s):
        result = (f"https://youtu.be/" + link.group(1))
    elif link := re.search(r"src=\"https://youtube.com/embed/(.{11})", s):
        result = (f"https://youtu.be/" + link.group(1))
    elif link := re.search(r"src=\"https://www.youtube.com/embed/(.{11})", s):
        result = (f"https://youtu.be/" + link.group(1))
    else:
        result = ("None")
    return result






if __name__ == "__main__":
    main()

"""link = re.search(r"src=\"http://youtube.com/embed/(.{11})\"",s)
    result = (f"https://youtu.be/" + link.group(1))
    elif link := re.search(r"src=\"https://youtube.com/embed/(.{11})",s):
        result = (f"https://youtu.be/" + link.group(1))
    elif link := re.search(r"src=\"src=\"https://www.youtube.com/embed/(.{11})",s):
        result = (f"https://youtu.be/" + link.group(1))
    return result"""