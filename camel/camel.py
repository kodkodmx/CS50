res = input("camelCase: ")
for letter in res:
    if letter.isupper():
        x = res.replace(letter, "_" + letter.lower())
        res = x
print(res)