class Matrix:
    def __init__(self, rows, columns):
        self.matrix = []
        self.rows = rows
        self.columns = columns

    def inputMatrix(self):
        for i in range(self.rows):
            row = []
            for j in range(self.columns):
                print("Enter a element (", i + 1, ",", j + 1, ") : ", end = " ")
                num = int(input())
                row += [num]
            self.matrix += [row]

    @staticmethod
    def addMatrix(m1, m2):

        if m1.columns == m2.columns and m1.rows == m2.rows:
            res = Matrix(m1.rows,m1.columns)
            for i in range(m1.rows):
                row = []
                for  j in range(m1.columns):
                    row += [m1.matrix[i][j] + m2.matrix[i][j]]
                res.matrix += [row]

            res.showMatrix()

        else:
            print("Addition of given matrices is not possible!")

    def showMatrix(self):

        for i in range(self.rows):
            for j in range(self.columns):
                print(self.matrix[i][j], end = "  ")
            print()

    def transpose(self):
        tMatrix = Matrix(self.columns, self.rows)

        for i  in range(tMatrix.rows):
            row = []
            for j in range(tMatrix.columns):
                row += [self.matrix[j][i]]
            tMatrix.matrix += [row]

        tMatrix.showMatrix()

    @staticmethod
    def multipyMatrix(m1, m2):
        if m1.columns == m2.rows:
            res = Matrix(m1.rows, m2.columns)
            for i in range(res.rows):
                row = []
                for j in range(res.columns):
                    element = 0
                    for k in range(m1.columns):
                        element += m1.matrix[i][k] * m2.matrix[k][j]
                    row += [element]
                res.matrix += [row]
            res.showMatrix()
        else:
            print("Multiplication of given matrices is not possible!!!")

    @staticmethod
    def subtractMatrix(m1, m2):

        if m1.columns == m2.columns and m1.rows == m2.rows:
            res = Matrix(m1.rows, m1.columns)
            for i in range(m1.rows):
                row = []
                for j in range(m1.columns):
                    row += [m1.matrix[i][j] - m2.matrix[i][j]]
                res.matrix += [row]

            res.showMatrix()

        else:
            print("Subtraction of given matrices is not possible!")

print("Input Matrix 1")
m1_row = int(input("Enter the no. of rows :"))
m1_col = int(input("Enter the no. of columns :"))
m1 = Matrix(m1_row, m1_col)
m1.inputMatrix()
print()
print("Input Matrix 2")
m2_row = int(input("Enter the no. of rows :"))
m2_col = int(input("Enter the no. of columns :"))
m2 = Matrix(m2_row, m2_col)
m2.inputMatrix()
print()




print("Matrix I = ")
m1.showMatrix()
print()
print("Matrix II = ")
m2.showMatrix()
print()



print("Press 0 for exit\nPress 1 for addition of matrix\nPress 2 for multiplication of matrix")
print("Press 3 for subtraction of matrix\nPress 4 for transpose of matrix")

ch = int(input("Enter your choice : "))
while ch != 0:

    if ch == 1:
        Matrix.addMatrix(m1, m2)

    elif ch == 2:
        Matrix.multipyMatrix(m1, m2)

    elif ch == 3:
        Matrix.subtractMatrix(m1, m2)

    elif ch == 4:
        m1.transpose()
        print()
        m2.transpose()

    else:
        print("Invalid Choice !!!")

    ch = int(input("Enter your choice : "))

