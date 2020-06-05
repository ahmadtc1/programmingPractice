def matchString(baseString, findString):
    startIndex = -1
    findStringIndex = 0
    curString = ""
    x = 0

    while (x < len(baseString)):
        if (curString == findString):
            print("Found \"{}\" from index {} - {}".format(findString, startIndex, startIndex + len(findString) - 1))
            return True
            
        if (baseString[x] == findString[0] and curString == ""):
            startIndex = x

        if (baseString[x] == findString[findStringIndex]):
            curString += baseString[x]
            findStringIndex += 1

        elif (baseString[x] != findString[findStringIndex] and curString != ""):
            curString = ""
            findStringIndex = 0
            if (startIndex != -1):
                x = startIndex + 1

        x += 1
    print("Could not find string \"{}\" in \"{}\"".format(findString, basestring))
    return False