class Solution(object):
    def boxes(self, index, board):
        i = int(index / 3) * 3
        j = (index % 3) * 3
        digits = []
        for a in range(i, i + 3):
            for b in range(j, j + 3):
                if board[a][b] != '.' and board[a][b] in digits:
                    return False
                elif board[a][b] != '.':
                    digits.append(board[a][b])
        return True

    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        row = []
        col = []
        for i in range(9):
            row = []
            col = []
            valid = self.boxes(i, board)
            if valid is False:
                return False
            for j in range(9):
                if board[i][j] != '.' and board[i][j] in row:
                    return False
                if board[j][i] != '.' and board[j][i] in col:
                    return False
                if board[i][j] != '.':
                    row.append(board[i][j])
                if board[j][i] != '.':
                    col.append(board[j][i])
        
        return True
        
