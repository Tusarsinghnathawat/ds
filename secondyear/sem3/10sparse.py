m1=int(input())
n1=int(input())
a=[]

for i in range(m1):
    x=[]
    for j in range(n1):
        x.append(int(input()))
    a.append(x)
  
m2=int(input())
n2=int(input())
b=[]
  
for i in range(m2):
    x=[]
    for j in range(n2):
        x.append(int(input()))
    b.append(x)

def sparse(a,m,n):
    s=[]
    temp=[]
    temp.append(m)
    temp.append(n)
    temp.append(0)
    s.append(temp)
    cnt=0
    for i in range(m):
        for j in range(n):
            temp=[]
            if a[i][j]!=0:
                temp.append(i)
                temp.append(j)
                temp.append(a[i][j])
                cnt+=1
                s.append(temp)
    s[0][2]=cnt
    return s

sparse1=[]
sparse2=[]
sparse1=sparse(a,m1,n1)
sparse2=sparse(b,m2,n2)

def display(sparse):
    print("Row","Col","Value")
    for i in range(len(sparse)):
        for j in range(3):
            print(sparse[i][j],end="    ")
        print()

print("1st Sparse Matrix:")
display(sparse1)
print("2nd Sparse Matrix:")
display(sparse2)

def transpose(sp):
    temp=[]
    tp=[]
    temp.append(sp[0][1])
    temp.append(sp[0][0])
    temp.append(sp[0][2])
    tp.append(temp)
    for i in range(sp[0][1]):
        for j in range(sp[0][2]):
            temp=[]
            if(i==sp[j+1][1]):
                temp.append(sp[j+1][1])
                temp.append(sp[j+1][0])
                temp.append(sp[j+1][2])
                tp.append(temp)

    return tp

print("Transpose of Sparse Matrix:")
display(transpose(sparse1))

def FastTranspose(s):
    t=[]
    rowTerms=[]
    rank=[]
    for i in range(s[0][1]):
        rowTerms.append(0)
    for i in range(1,len(s)):
        rowTerms[s[i][1]]+=1
    rank.append(1)
    for i in range(1,s[0][1]):
        rank.append(rank[i-1]+rowTerms[i-1])
    t.append(s[0])
    for i in range(1,len(s)):
        temp=[]
        temp.append(s[i][1])
        temp.append(s[i][0])
        temp.append(s[i][2])
        t.insert(rank[s[i][1]],temp)
        rank[s[i][1]]+=1
    return t
# T.C. = O(no. of col + no. of non-zero elements)
print("Fast transpose of sparse matrix:")
print("row       ", "column       ", "value")
print(display(FastTranspose(sparse(a,m1,n1))))