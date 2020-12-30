def permPalindrome(string):
    unpaired = set()

    for letter in string:
        if (letter in unpaired):
            unpaired.remove(letter)
        
        else:
            unpaired.add(letter)
    
    if (len(unpaired) <= 1):
        return True
    
    else:
        return False


if (__name__ == "__main__"):
    print(permPalindrome("civil"))