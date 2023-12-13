#include<iostream> //This line includes the Input/Output Stream Library, which provides functionality for reading from and writing to the standard input and output.
#include<fstream> //This line includes the File Stream Library, which provides functionality for reading from and writing to files.
using namespace std; //This line declares that elements from the standard C++ library (e.g., cout, cin) are part of the std namespace

class fileHandle{
	fstream doc; //fstream is used for file input and output operations.
	
	public:
	void createFile(){ //This function creates a file named fileHandle.txt
		doc.open("fileHandle.txt", ios::out); //ios::out opens the file in output mode
		if(!doc) 
			cout << "Error !!!" << endl; //If the file is not created, then it will show an error message
		else
			cout << "File Created Successfully" << endl; 
			doc.close(); //Closing the file
	}

	void writeFile(){
		doc.open("fileHandle.txt", ios::out);
		string data;
		cout << "Enter data: ";
		getline(cin, data); //getline() is used to read a string or a line from the input stream.
		doc << data; //Writing data to the file
		cout << "Data Entered Successfully" << endl;
		doc.close();
	}

	void readFile(){
		cout << "\nReading the file: ";
		doc.open("fileHandle.txt", ios::in); //ios::in opens the file in input mode
		string x; 
		while(doc >> x) //Reads data from the file into the x variable until the end of the file is reached.
			cout << x << " ";
	}
};

int main(){
	fileHandle doc;
	doc.createFile();
	doc.writeFile();
	doc.readFile();
}