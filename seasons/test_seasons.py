from seasons import validate
import pytest

def main():
    test_validate()

def test_validate():
    assert validate('2022-10-29') == ("2022", "10", "29")



if __name__ == "__main__":
    main()
