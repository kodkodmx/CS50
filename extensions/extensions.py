res = input("File name: ")
res = res.lower().strip()
if res.endswith('.gif'):
    print("image/gif")
elif res.endswith('.jpg') or res.endswith('.jpeg'):
    print("image/jpeg")
elif res.endswith('.png'):
    print("image/png")
elif res.endswith('.pdf'):
    print("application/pdf")
elif res.endswith('.txt'):
    print("text/plain")
elif res.endswith('.zip'):
    print("application/zip")
else:
    print("application/octet-stream")