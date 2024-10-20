from datetime import date
import sys, re, inflect

def main():
    p = inflect.engine()
    year, month, day = validate(input("Date of Birth: "))
    born = date(int(year), int(month), int(day))
    now = date.today()
    minutes = ((now - born).days)*1440
    print(p.number_to_words(minutes, andword="").capitalize() + " minutes")

def validate(date):
    if valid := re.search(r"^((\d\d\d\d)-(\d\d)-(\d\d))$", date):
        year, month, day = valid.group(1).split("-")
        return year, month, day
    else:
        sys.exit("Invalid date")



if __name__ == "__main__":
    main()
