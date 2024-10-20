import re
import sys


def main():
    print(convert(input("Hours: ")))


def convert(s):
    if hour := re.search(r"(?:(^[0-9][0-9]*)(:\d\d)?)\s(AM|PM)\sto\s(?:([0-9][0-9]*)(:\d\d)?)\s(AM|PM)$",s):
        #print(hour.groups())
        if hour.group(1)[0] == "0":
            raise ValueError()
        if int(hour.group(1)) > 12:
            raise ValueError()
        if hour.group(3) == "AM":
            if hour.group(1) == "12":
                firsthour = "00"
            else:
                firsthour = hour.group(1)
        else:
            if hour.group(1) == "12":
                firsthour = "12"
            else:
                firsthour = str(int(hour.group(1))+12)
        if hour.group(4)[0] == "0":
            raise ValueError()
        if int(hour.group(4)) > 12:
            raise ValueError()
        if hour.group(6) == "AM":
            if hour.group(4) == "12":
                secondhour = "00"
            else:
                secondhour = hour.group(4)
        else:
            if hour.group(4) == "12":
                secondhour = "12"
            else:
                secondhour = str(int(hour.group(4))+12)

        if hour.group(2):
            if int(hour.group(2)[1:]) < 60:
                firstminutes = hour.group(2)
            else:
                raise ValueError()
        else:
            firstminutes = ":00"
        if hour.group(5):
            if int(hour.group(5)[1:]) < 60:
                secondminutes = hour.group(5)
            else:
                raise ValueError()
        else:
            secondminutes = ":00"
        result = (f"{firsthour:0>2}{firstminutes} to {secondhour:0>2}{secondminutes}")

        return result
    else:
        raise ValueError()


if __name__ == "__main__":
    main()