class Solution:
    def toLowerCase(self, str: str) -> str:
        lowerCaseString = ""
        letterDictionary = {
            "A": "a",
            "B": "b",
            "C": "c",
            "D": "d",
            "E": "e",
            "F": "f",
            "G": "g",
            "H": "h",
            "I": "i",
            "J": "j",
            "K": "k",
            "L": "l",
            "M": "m",
            "N": "n",
            "O": "o",
            "P": "p",
            "Q": "q",
            "R": "r",
            "S": "s",
            "T": "t",
            "U": "u",
            "V": "v",
            "W": "w",
            "X": "x",
            "Y": "y",
            "Z": "z"
        }
        for letter in str:
            if letter in letterDictionary:
                lowerCaseString += letterDictionary[letter]
            else:
                lowerCaseString += letter
        return lowerCaseString
