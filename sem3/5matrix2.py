print("Enter order of matrix_1:")
m=int(input("Enter value of m:"))
n=int(input("Enter value of n:"))
matrix1=[]
matrix2=[]

print("Enter value of matrix_1:")
for i in range(m):
    temp=[]
    for i in range(n):
        num=int(input())
        temp.append(num)

    matrix1.append(temp)

print("Enter order of matrix_2:")
a=int(input("Enter value of a:"))
b=int(input("Enter value of b:"))

print("Enter value of matrix_2:")
for i in range(a):
    temp=[]
    for i in range(b):
        num=int(input())
        temp.append(num)

    matrix2.append(temp)

def transpose(matrix):
    trans=[]
    for i in range(m):
        temp1=[]
        for j in range(n):
            temp1.append(matrix[j][i])

        trans.append(temp1)

    return trans



def addition(m1,m2):
    add=[]
    for i in range(len(m1)):
        for j in range(len(m2)):
            add.append(m1[i][j]+m2[i][j])

    return add




def substraction(m1,m2):
    sub=[]
    for i in range(len(m1)):
        for j in range(len(m2)):
            sub.append(m1[i][j]-m2[i][j])

    return sub




def multiplication(m1,m2):
    result=[]
    for i in range(len(m1)):
        r=[]
        for j in range(len(m2[0])):
            r.append(int(0))

        result.append(r)


    for i in range(len(m1)):
        for j in range(len(m2[0])):
            for k in range(len(m2)):
                result[i][j]+= (m1[i][k]*m2[k][j])
    return result


def saddlePoint(a,m,n):
    for i in range(m):
        min=a[i][0]
        col=0
        for j in range(n):
            if a[i][j]<min:
                min=a[i][j]
                col=j
        max=a[0][col]
        for k in range(m):
            if a[k][col]>max:
                max=a[k][col]
        if min==max:
            print("Saddle point is:",min)
            return
    print("No saddle point")

print("Addition of two given matrix is",addition(matrix1,matrix2))
print("Substraction of two given matrix is:",substraction(matrix1,matrix2))
print("Multiplication of two given matrix is:",multiplication(matrix1,matrix2))
print("Transpose of given matrix is:",transpose(matrix1))
saddlePoint(matrix1)