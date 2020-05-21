class Solution(object):
    def canConstruct(self, ransomNote, magazine):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        ransomNoteLetters = {}
        magazineLetters = {}
        for letter in ransomNote:
            if (letter in ransomNoteLetters):
                ransomNoteLetters[letter] += 1
            else:
                ransomNoteLetters[letter] = 1
        
        for letter in magazine:
            if (letter in magazineLetters):
                magazineLetters[letter] += 1
            else:
                magazineLetters[letter] = 1
                
        for letter in ransomNoteLetters:
            if letter not in magazineLetters:
                return False
            
            elif (ransomNoteLetters[letter] > magazineLetters[letter]):
                return False
            
        return True;
