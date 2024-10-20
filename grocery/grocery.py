result = {}
while True:
    try:
        item = input().upper()
        if item in result:
            result[item] += 1
        else:
            result[item] = 1

    except EOFError:
        for item in sorted(result):
            print (result[item], item)
        break
