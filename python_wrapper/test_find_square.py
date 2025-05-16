#!/usr/bin/env python3
import sys
import os

sys.path.insert(0, os.path.abspath("build"))

import find_square

def test_find_square():
    # Exact match for a perfect square
    assert find_square.find_square(64.0, 0, 10) == 8
    assert find_square.find_square(81.0, 0, 20) == 9

    # Not found square (should return -1)
    assert find_square.find_square(50.0, 0, 20) == -1
    assert find_square.find_square(64.1, 0, 10) == -1

    # Bounds tests
    assert find_square.find_square(0.0, 0, 0) == 0
    assert find_square.find_square(1.0, 1, 1) == 1
    assert find_square.find_square(1.0, 2, 2) == -1

    # Large range
    assert find_square.find_square(1000000.0, 0, 1000) == 1000

    print("All Python tests passed successfully.")

if __name__ == "__main__":
    test_find_square()
