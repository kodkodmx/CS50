from plates import is_valid

def main():
    test_minmax()
    test_nonalpha()
    test_not_middle()
    test_nonzero()

def test_minmax():
    assert is_valid('AA') == True
    assert is_valid('ABCDEF') == True
    assert is_valid('A') == False
    assert is_valid('ABCDEFG') == False

def test_nonalpha():
    assert is_valid('A2') == False
    assert is_valid('2A') == False
    assert is_valid('AA') == True

def test_not_middle():
    assert is_valid('AAA2') == True
    assert is_valid('AA2A') == False

def test_nonzero():
    assert is_valid('AA01') == False
    assert is_valid('AA10') == True

def test_isalphanum():
    assert is_valid('CS50') == True
    assert is_valid('CS@50') == False





if __name__ == "__main__":
    main()