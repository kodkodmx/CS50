from working import convert
import pytest

def main():
    test_smallformat()
    test_bigformat()
    test_wrong_format()
    test_wrong_minute()
    test_wrong_hour()


def test_smallformat():
    assert convert('12 AM to 12 PM') == "00:00 to 12:00"
    assert convert('10 AM to 10 PM') == "10:00 to 22:00"

def test_bigformat():
    assert convert('12:00 AM to 12:00 PM') == "00:00 to 12:00"
    assert convert('10:50 AM to 10:01 PM') == "10:50 to 22:01"

def test_wrong_format():
    with pytest.raises(ValueError):
        convert("9 AM - 9 PM")


def test_wrong_minute():
    with pytest.raises(ValueError):
         convert("9:60 AM to 9:60 PM")


def test_wrong_hour():
    with pytest.raises(ValueError):
        convert("13 PM to 17 PM")



if __name__ == "__main__":
    main()