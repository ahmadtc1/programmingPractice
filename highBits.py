
def highBits(num : int) -> int:
    digits = 0
    highBits = 0
    copy = num
    while (copy > 0):
        copy /= 10
        digits += 1

    for x in range(digits):
        highCheck = num & (1 << x)
        if (highCheck > 0):
            highBits += 1

    return highBits