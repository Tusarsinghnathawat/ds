#include <iostream>
using namespace std;

class Complex{

	float real, img;

	public:
	Complex(){
		real = 0;
		img = 0;
	}
	friend ostream &operator<<(ostream &, Complex &); // ostream is a class which is used to write the data into the stream (file).
	friend istream &operator>>(istream &, Complex &); // istream is a class which is used to read the data from the stream (file).
	friend Complex operator+(Complex &c1, Complex &a1); // operator overloading using friend function.
	friend Complex operator-(Complex &c2, Complex &a2);
	friend Complex operator*(Complex &c3, Complex &a3); 
	friend Complex operator/(Complex &c4, Complex &a4);
};

istream &operator>>(istream &in, Complex &obj){ //&operator is used to return the object by reference.
	cout << "Enter the real part: ";
	in >> obj.real; // cin is an object of istream class.
	cout << "Enter the imaginary part: ";
	in >> obj.img;
	return in;
}

ostream &operator<<(ostream &out, Complex &obj){ //<< is an operator overloading.
	cout << "Complex No is :";
	out << obj.real << "+(" <<  obj.img << "i)" <<"\n";
	return out;
}

Complex operator+(Complex &c1, Complex &a1){ //ampersand is used to pass the object by reference.
	Complex r1;
	r1.real = c1.real + a1.real;
	r1.img = c1.img + a1.img;
	return r1;
}

Complex operator-(Complex &c2, Complex &a2){ //- is an operator overloading.
	Complex r2;
	r2.real = c2.real - a2.real;
	r2.img = c2.img - a2.img;
	return r2;
}

Complex operator*(Complex &c3, Complex &a3){
	Complex r3;
	r3.real = c3.real * a3.real - c3.img * a3.img;
	r3.img = c3.real * a3.img + c3.img * a3.real;
	return r3;
}

Complex operator/(Complex &c4, Complex &a4){
	Complex r4;
	r4.real = (c4.real * a4.real + c4.img * a4.img) / (a4.real * a4.real + c4.img * c4.img);
	r4.img = (-c4.real * a4.img + c4.img * a4.real) / (a4.real * a4.real + c4.img * c4.img);
	return r4;
}

int main(){
	Complex s, a, b, add, sub, mul, div;
	cout << "Enter First Complex No\n";
	cin >> a;
	cout << "Enter Second Complex No\n";
	cin >> b;
	add = a + b;
	cout << "Addition of ";
	cout << add << "\n";
	sub = a - b;
	cout << "Substraction of ";
	cout << sub << "\n";
	mul = a * b;
	cout << "Multiplication of ";
	cout << mul << "\n";
	div = a / b;
	cout << "Division of ";
	cout << div << "\n";
}