def selectionSort(arr,n):
	for i in range(n):
		pos=i
		for j in range(i+1,n):
			if(arr[j]<arr[pos]): 
				pos=j
				
		(arr[i], arr[pos]) = (arr[pos], arr[i])
#   Time Complexity: O(n^2)
def insertionSort(arr,n):
	if n <= 1:
		return 

	for i in range(1, n): 
		temp = arr[i] 
		j = i-1
		while j >= 0 and temp < arr[j]: 
			arr[j+1] = arr[j] 
			j -= 1
		arr[j+1] = temp 
	# Time Complexity: O(n^2)	
def arrayInput(arr):
    n=int(input("Enter no. of elements: "))
    print("Enter the elements")
    for i in range(n):
        x=int(input())
        arr.append(x)

print("1 for selection sort")
print("2 for insertion sort")
ch=int(input())
arr=[]
if(ch==1):
	arrayInput(arr)
	selectionSort(arr,len(arr))
elif(ch==2):
	arrayInput(arr)
	insertionSort(arr,len(arr))		
print("Sorted array is:",arr)