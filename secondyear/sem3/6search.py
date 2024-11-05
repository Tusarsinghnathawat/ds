def sentinel(num):
    c=0
    nu = int(input("the number to be searched: "))
    num.append(nu)
    i = 0
    while(num[i] != nu):
        i += 1
    if(i!=len(num)-1):
        print("the number was present")
    else:
        print("the numbe was not present")
# Time Complexity: O(n)      
def binary(num):
    c=0
    nu = int(input("the number to be searched: "))
    num.sort()
    l = 0
    h = len(num) - 1
    while(l<=h):
        mid = int((l+h)/2)
        if(nu == num[mid]):
            c = 1
            print("the number was found")
            break
        elif(nu<num[mid]):
            h = mid - 1
        else:
            l = mid + 1
# Time Complexity: O(log n)
n =  int(input("enter the number of elements: "))
num = list()
for i in range(0, n):
    x = int(input())
    num.append(x)

print("enter 1 for sentinel search")
print("enter 2 for binary search")
choice = int(input("enter the choice: "))

if(choice == 1):
    sentinel(num)
elif(choice == 2):
    binary(num)