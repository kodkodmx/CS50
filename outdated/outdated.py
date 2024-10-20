months = [
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
]
while True:
    date = input("Date: ")
    try:
        values = date.split(" ")
        if values[0] in months and int(values[1][:-1])<=31:
            for num in range(len(months)):
                if values[0] == months[num]:
                    print(f"{values[2]}-{num+1:02}-{int(values[1][:-1]):02}")
            break
        else:
            values = date.split("/")
            if int(values[0])<=12 and int(values[1])<=31:
                print(f"{int(values[2])}-{int(values[0]):02}-{int(values[1]):02}")
                break
    except:
        continue


