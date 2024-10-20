res = input("Input: ")
for char in res:
    if char.lower() in ('a', 'e', 'i', 'o', 'u'):
        x = res.replace(char, "")
        res = x
print(res)

