#include<iostream>
#include<vector>
using namespace std;

template <typename T> void input(T x[], int n){
	cout << "Enter the elements of array" << endl;
	for(int i = 0; i < n; i++)
		cin >> x[i];
}

template <typename T> void sort(T x[], int n){
	for (int i = 0; i < n-1; i++) {
		int min_idx = i;
        for (int j = i+1; j < n; j++){
            if (x[j] < x[min_idx]){
                min_idx = j;
            }
        }
        T temp = x[min_idx];
    	x[min_idx] = x[i];
        x[i] = temp;
    }
}

template <typename T> void output(T x[], int n){
	cout << "Array after sorting is: ";
	for(int i = 0; i < n; i++)
		cout << x[i] << " ";
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