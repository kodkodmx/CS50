from project import guess, validate, opportunities

def test_guess():
    # Test cases for the guess function
    assert guess(6, 5) == 'The number is Smaller'
    assert guess(4, 5) == 'The number is Bigger'
    assert guess(5, 5) == 'You guessed the number'

def test_validate():
    # Test cases for the validate function
    assert validate("1") == False  # Valid input
    assert validate("100") == False  # Valid input
    assert validate("101") == True  # Invalid input
    assert validate("0") == True  # Invalid input
    assert validate("cat") == True  # Invalid input

def test_opportunities():
    # Test cases for the opportunities function
    assert opportunities(1) == 1  # 13% of 1 is 0.13, rounded up to 1
    assert opportunities(10) == 2  # 13% of 10 is 1.3, rounded up to 2
    assert opportunities(20) == 3  # 13% of 20 is 2.6, rounded up to 3
    assert opportunities(65) == 9  # 13% of 65 is 8.45, rounded up to 9
    assert opportunities(100) == 13  # 13% of 100 is 13
