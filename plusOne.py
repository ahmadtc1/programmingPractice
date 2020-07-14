def plusOne(digits):
    length = len(digits)
    number = 0
    j = 0

    for x in range(length - 1, -1, -1):
        number += digits[x] * (10 ** j)
        j += 1

    return number + 1

num = plusOne([2, 3, 4])
print(num)
