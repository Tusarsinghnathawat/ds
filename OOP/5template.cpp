#include<iostream>
#include<vector>
using namespace std;

template <typename T> void input(T x[], int n){
	cout << "Enter the elements of array" << endl;
	for(int i = 0; i < n; i++)
		cin >> x[i];
}
// Selection Sort
template <typename T> void sort(T arr[], int size){
	for (int i = 0; i < size-1; i++) {
		int minInd = i;
        for (int j = i+1; j < size; j++){
            if (arr[j] < arr[minInd]){
                minInd = j;
            }
        }
        T temp = x[minInd];
    	x[minInd] = x[i];
        x[i] = temp;
    }
}

template <typename T> void output(T arr[], int size){
	cout << "Array after sorting is: ";
	for(int i = 0; i < size; i++)
		cout<<arr[i]<<" ";
}

int main(){
	int n;
	cout << "Enter the number of elements in Array: ";
	cin >> n;
	int x[n];
	input <int>(x, n);
	sort <int>(x, n);
	output <int>(x, n);

	float y[n];
	input <float>(y, n);
	sort <float>(y, n);
	output <float>(y, n);

	char z[n];
	input <char>(z, n);
	sort <char>(z, n);
	output <char>(z, n);
}