import validators

email = input("What's your email address? ")
result = validators.email(email)
if result == True:
    print('Valid')
else:
    print('Invalid')