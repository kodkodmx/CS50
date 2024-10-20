from twttr import shorten

def test_vowels():
    assert shorten("aaa") == ""

def test_numbers():
    assert shorten("000") == "000"

def test_blank():
    assert shorten("") == ""

def test_capitalized():
    assert shorten("Alberto") == "lbrt"

def test_puntuation():
    assert shorten("aaa.AAA") == "."

def test_upper():
    assert shorten("ALBERTO") == "LBRT"
