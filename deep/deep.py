res = input("What is the answer to the Great Question of Life, the Universe and Everything?")
res = res.lower().strip()
match res:
    case "42" | "forty two" | "forty-two":
        print("Yes")
    case _:
        print("No")