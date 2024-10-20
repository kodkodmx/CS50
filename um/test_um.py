from um import count
import pytest

def main():
    test_um()



def test_um():
    assert count('Um') == 1
    assert count(' um ') == 1
    assert count('Puma') == 0
    assert count('Um...') == 1
    assert count('Um... yes, um... I know') == 2


if __name__ == "__main__":
    main()