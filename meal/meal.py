def main():
    res = input("What time is it? ")
    flotime = convert(res)
    #print (flotime)
    if 7 <= flotime <= 8:
        print("breakfast time")
    elif 12 <= flotime <= 13:
        print("lunch time")
    elif 18 <= flotime <= 19:
        print("dinner time")

def convert(time):
    x, y = time.split(":")
    x=float(x)
    y=float(y)
    return x+(y/60)


if __name__ == "__main__":
    main()