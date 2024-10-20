import inflect

p = inflect.engine()
names = []

while True:
    try:
        names.append(input("Name: "))
        names2 = p.join(names)
    except EOFError:
        print()
        print ("Adieu, adieu, to", names2)
        break
    