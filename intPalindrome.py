def isPalindrome(num):
    power = 0
    reversedNum = 0
    copy = num

    while (copy > 0):
        power += 1
        copy //= 10

    copy = num
    power -= 1

    while (copy > 0):
        lastDigit = copy % 10
        reversedNum += lastDigit * (10 ** power)
        power -= 1
        copy //= 10

    if (num == reversedNum):
        print("Palindrome")
        return True

    else:
        print("Not Palindrome")
        return False


if (__name__ == "__main__"):
    isPalindrome(1234321)