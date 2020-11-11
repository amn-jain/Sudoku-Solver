Board = [[0, 8, 0, 7, 0, 1, 0, 3, 0],
         [4, 0, 9, 0, 0, 0, 0, 0, 0],
         [0, 5, 0, 0, 6, 0, 4, 1, 8],
         [7, 0, 0, 0, 0, 9, 0, 0, 0],
         [8, 0, 0, 6, 1, 0, 5, 0, 0],
         [0, 3, 5, 0, 0, 0, 0, 2, 9],
         [0, 6, 0, 4, 0, 7, 0, 9, 0],
         [1, 0, 0, 0, 0, 8, 0, 0, 4],
         [0, 2, 0, 0, 5, 0, 0, 7, 0]]

def display_board(Board):

    for i in range(len(Board)):
        if(i%3 == 0 and i != 0):
            print("-----------------------")
        for j in range(len(Board[0])):
            if(j%3 == 0 and j != 0):
                print("|", end = " ")
            if(j != 8):
                print(str(Board[i][j]) + " ", end = "")
            else:
                print(str(Board[i][j]))

def find_empty(Board):

    for i in range(len(Board)):
        for j in range(len(Board[0])):
            if(Board[i][j] == 0):
                return (i, j) # (row, column)
    
    return None

def valid(Board, num, pos):

    # Check Row
    for i in range(len(Board[0])):
        if(Board[pos[0]][i] == num and pos[1] != i):
            return False
    
    # Check Column
    for i in range(len(Board)):
        if(Board[i][pos[1]] == num and pos[0] != i):
            return False

    # Check Box
    Box_X = pos[0] // 3
    Box_Y = pos[1] // 3
    for i in range(Box_X * 3, Box_X * 3 + 3, 1):
        for j in range(Box_Y * 3, Box_Y * 3 + 3, 1):
            if(Board[i][j] == num and pos != (i, j)):
                return False
    
    return True

def solve(Board):

    find = find_empty(Board)

    if(find == None):
        return True
    else:
        x = find[0]
        y = find[1]
    
    for i in range(1, 10, 1):
        if(valid(Board, i, (x, y))):
            Board[x][y] = i

            if solve(Board):
                return True

            Board[x][y] = 0

    return False

display_board(Board)
print()
print()
solve(Board)
display_board(Board)        