def isShifted(a, b):
    if (len(a) != len(b)):
        return False

    # Loop through all rotation possibilities
    for x in range(len(b)):
        if (a == b):
            return True
        else:
            # Use string slicing to reconstruct the string shifted right by 1 
            a = a[-1] + a[: -1]

    return False
