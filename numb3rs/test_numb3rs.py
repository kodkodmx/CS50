from numb3rs import validate

def main():
    test_format()
    test_range()

def test_format():
    assert validate(r'127.0.0.1') == True
    assert validate(r'127.0.0.') == False
    assert validate(r'127.0.') == False
    assert validate(r'127.') == False
    assert validate(r'cat.') == False


def test_range():
    assert validate('300.255.255.255') == False
    assert validate('255.300.255.255') == False
    assert validate('255.255.300.255') == False
    assert validate('255.255.255.300') == False
    assert validate('255.255.255.255') == True


if __name__ == "__main__":
    main()