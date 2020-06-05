
def checkAdjacent(y, x, maxY, maxX, grid, visited):
    if ((y, x) not in visited):
        if (grid[y][x] == "1"):
            print("Adding ({}, {}) to visited".format(y,x))
            visited.add((y, x)) 
            if (x > 0):
                checkAdjacent(y, x - 1,  maxY, maxX, grid, visited)
            if (x < maxX - 1):
                checkAdjacent(y, x + 1,  maxY, maxX, grid, visited)
            if (y > 0):
                checkAdjacent(y - 1, x, maxY, maxX, grid, visited)
            if (y < maxY - 1):
                checkAdjacent(y + 1, x,  maxY, maxX, grid, visited)

        elif (grid[y][x] == "0"):
            return 0
        
def numIslands(grid):
    visited = set()
    islands = 0
    maxX = len(grid[0])
    maxY = len(grid)
    
    for y in range(len(grid)):
        for x in range(len(grid[0])):
            if (grid[y][x] == "1" and (y,x) not in visited):
                print("Printing visited")
                for entry in visited:
                    print(entry)
                print("Adding island@ ({}, {})".format(y,x))
                islands += 1
                checkAdjacent(y, x, maxY, maxX, grid, visited)

    return islands
