# Iterative O(n) runtime O(1) memory solution
def orderChecker(dineOrders, takeoutOrders, servedOrders):
    dcIndex = 0
    toIndex = 0

    for order in servedOrders:
        if (dcIndex < len(dineOrders) and dineOrders[dcIndex] == order):
            dcIndex += 1
        
        elif (toIndex < len(takeoutOrders) and takeoutOrders[toIndex] == order):
            toIndex += 1

        else:
            return False
    
    if (dcIndex == len(dineOrders) and toIndex == len(takeoutOrders)):
        return True

    else:
        return False


# Recursive O(n^2) runtime O(n^2) memory solution
def serverOrdersRecursive(dineOrders, takeOutOrders, serverOrders):
    if (len(serverOrders) == 0 ):
        return True

    elif (serverOrders[0] in dineOrders and len(dineOrders) > 0 and dineOrders[0] == serverOrders[0]):
        return serverOrdersRecursive(dineOrders[1:], takeOutOrders, serverOrders[1:])

    elif (serverOrders[0] in takeOutOrders and len(takeOutOrders) > 0 and takeOutOrders[0] == serverOrders[0]):
        return serverOrdersRecursive(dineOrders, takeOutOrders[1:], serverOrders[1:])
    
    else:
        return False


if (__name__ == "__main__"):
    take = [1, 3, 5]
    dine = [2, 4, 6]
    served = [1, 2, 4, 6, 5, 3]

    print(orderChecker(dine, take, served))