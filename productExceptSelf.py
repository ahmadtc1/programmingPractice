import unittest

def productExceptSelf(list):
    left = [1] * len(list)
    right = [1] * len(list)
    left[0] = list[0]
    right[-1] = list[-1]
    prodExceptSelf = [0] * len(list)
    for x in range(1, len(list)):
        left[x] = list[x] * left[x-1]

        y = -1 * x - 1
        right[y] = right[y+1] * list[y]

    prodExceptSelf[0] = right[1]
    prodExceptSelf[-1] = left[len(list) - 2]

    print(right)
    print(left) 
    
    for x in range(1, len(list) - 1):
        prodExceptSelf[x] = left[x-1] * right[x+1]

    return prodExceptSelf

def get_products_of_all_ints_except_at_index(list):

    if (len(list) < 3):
        raise IndexError('At least 3 elements necessary')

    left = [1] * len(list)
    # [1, 7, 3, 4]
    prodSoFar = 1
    for x in range(len(list)):
        left[x] = prodSoFar
        prodSoFar *= list[x]

    
    prodSoFar = 1
    # [1, 1, 7, 21]
    for x in range(len(list) - 1, -1, -1):
        left[x] = left[x] * prodSoFar
        prodSoFar *= list[x]

    return left


# Tests

class Test(unittest.TestCase):

    def test_small_list(self):
        actual = get_products_of_all_ints_except_at_index([1, 2, 3])
        expected = [6, 3, 2]
        self.assertEqual(actual, expected)

    def test_longer_list(self):
        actual = get_products_of_all_ints_except_at_index([8, 2, 4, 3, 1, 5])
        expected = [120, 480, 240, 320, 960, 192]
        self.assertEqual(actual, expected)

    def test_list_has_one_zero(self):
        actual = get_products_of_all_ints_except_at_index([6, 2, 0, 3])
        expected = [0, 0, 36, 0]
        self.assertEqual(actual, expected)

    def test_list_has_two_zeros(self):
        actual = get_products_of_all_ints_except_at_index([4, 0, 9, 1, 0])
        expected = [0, 0, 0, 0, 0]
        self.assertEqual(actual, expected)

    def test_one_negative_number(self):
        actual = get_products_of_all_ints_except_at_index([-3, 8, 4])
        expected = [32, -12, -24]
        self.assertEqual(actual, expected)

    def test_all_negative_numbers(self):
        actual = get_products_of_all_ints_except_at_index([-7, -1, -4, -2])
        expected = [-8, -56, -14, -28]
        self.assertEqual(actual, expected)

    def test_error_with_empty_list(self):
        with self.assertRaises(Exception):
            get_products_of_all_ints_except_at_index([])

    def test_error_with_one_number(self):
        with self.assertRaises(Exception):
            get_products_of_all_ints_except_at_index([1])


unittest.main(verbosity=2)