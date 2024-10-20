from bank import value

def test_blank():
    assert value("") == 100

def test_hello():
    assert value("hello") == 0

def test_HELLO():
    assert value("HELLO") == 0

def test_starth():
    assert value("hola") == 20

def test_nobeginh():
    assert value("welcome") == 100



