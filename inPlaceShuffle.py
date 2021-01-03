import unittest
import random

def shuffle(list):
    # If theres 0 or 1 items in the list return it as is
    if (len(list) < 1):
        return list

    for x in range(len(list)):
        swapIndex = random.randint(x, len(list) - 1)
        
        if (swapIndex != x):
            temp = list[swapIndex]
            list[swapIndex] = list[x]
            list[x] = temp

if (__name__ == "__main__"):
    list = [1,2,3,4,5,6,7,8,9,10]
    shuffle(list)
    print(list)
