# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")
import time
import datetime


# Helper function to handle the task of determining whether a given timestamp is interesting
def isInteresting(s):
    # Count how many numbers exist in the timestamp
    numCount = set()
    for letter in s:
        if (letter.isalnum()):
            numCount.add(letter)

    # If theres only 1 or 2 numbers in the timestamp it's interesting
    return (len(numCount) <= 2)


def solution(S, T):
    # write your code in Python 3.6
    # Convert the hh mm ss string to seconds
    SECONDS_IN_HOUR = 60 * 60
    SECONDS_IN_MINUTE = 60
    interestingTimestamps = 0

    hours, minutes, seconds = S.split(":")
    endHours, endMinutes, endSeconds = T.split(":")

    startSeconds = int(hours) * SECONDS_IN_HOUR + int(minutes) * SECONDS_IN_MINUTE + int(seconds)

    print(startSeconds)

    endSeconds = int(endHours) * SECONDS_IN_HOUR + int(endMinutes) * SECONDS_IN_MINUTE + int(endSeconds)

    print(endSeconds)

    currentSeconds = startSeconds

    while (currentSeconds <= endSeconds):
        currentTimestamp = str(datetime.timedelta(seconds=currentSeconds))
        

        print(currentTimestamp)

        if (isInteresting(currentTimestamp)):
            interestingTimestamps += 1

        currentSeconds += 1
    
    return interestingTimestamps




if (__name__ == "__main__"):
    s = '15:15:12'
    print(solution('22:22:21', '22:22:23'))