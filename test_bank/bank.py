def main():
    greeting = input("Greeting: ")
    print(f"${value(greeting)}")



def value(greeting):
    greeting = greeting.lower().strip()
    if greeting == "":
        return 100
    else:
        if greeting[0]=="h" and greeting[1]=="e" and greeting[2]=="l" and greeting[3]=="l" and greeting[4]=="o":
            return 0
        elif greeting[0]=="h":
            return 20
        else:
            return 100



if __name__ == "__main__":
    main()