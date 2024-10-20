res = input("Expression: ")
x, y, z = res.split(" ")
x = int(x)
z = int(z)
if y == ('+'):
    total = x + z
    print(f"{total:.1f}")
elif y == ('-'):
    total = x - z
    print(f"{total:.1f}")
elif y == ('*'):
    total = x * z
    print(f"{total:.1f}")
elif y == ('/'):
    total = x / z
    print(f"{total:.1f}")