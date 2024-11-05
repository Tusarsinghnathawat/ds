#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Personal{
	string name, dob, tel_no;

	public:
	Personal(string name1, string dob1, string tel):name(name1),dob(dob1), tel_no(tel){}
	string getName(){return name;}
	string getDob(){return dob;}
	string getTelNo(){return tel_no;}
};

// Comparator for sorting & Binary Search Algorithms

bool Comparator(Personal lhs, Personal rhs){
	return(lhs.getName() < rhs.getName());
}

void print(Personal& p){
	cout << "\n\t"<<p.getName()<<"\t"<<p.getDob()<<"\t"<<p.getTelNo()<<endl;
}

int main(){
	vector<Personal> pvec;
	int cho;
	char ch;
	string name, dob, telno;

	do{
		cout << "\n\t Personal Record Menus" << endl;
		cout << "\n\t 1. Create New Record";
		cout << "\n\t 2. Display All Recods";
		cout << "\n\t 3. Search Perticular Record";
		cout << "\n\t 4. Sort All Records & Display";
		cout << "\n\t 5. Exit";
		cout << "\n\t Enter your Choice: ";
		cin >> cho;

		switch(cho){
			case 1:
				cout << "\n\t Enter Personal Details";
				cout << "\n\t Name: ";
				cin >> name;
				cout << "\n\t Date of Birth: ";
				cin >> dob;
				cout << "\n\t Telephone Number(10 Digits Only)";
				cin >> telno;
				pvec.push_back(Personal(name, dob, telno));
				break;
			case 2:
				cout << "\n\t Personal Recors" << endl;
				cout << "\n\tName\tDateofBirth\tTelephoneNo";
				for_each(pvec.begin(),pvec.end(),print);
				break;
			case 3:
				cout << "\n\t Enter Person name for Searching: ";
				cin >> name;
				if(binary_search(pvec.begin(),pvec.end(),Personal(name," "," "),Comparator))
					cout << "\n\t Person with name "<<name<<" exists in vector.\n";
				else
					cout << "\n\t Person with name "<<name<<" does not exis in vector.\n";
				break;
			case 4:
				sort(pvec.begin(),pvec.end(),Comparator);
				cout << "\n\t Pesonal Record "<< endl;
				cout << "\n\tName\tDateofBirth\tTelephoneNo";
				for_each(pvec.begin(), pvec.end(),print);
				break;
			case 5:
				exit(0);
			default:
				cout << "\n\t Enter choice in between 1 to 5 only.";
		}
		cout << "\n\t Do you want to Continue(Y/N): ";
		fflush(stdin);
		cin >> ch;
	} while(ch == 'y'|| ch == 'y');
}
