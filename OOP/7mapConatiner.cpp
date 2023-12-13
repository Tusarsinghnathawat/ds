#include <iostream>
#include <map>
#include<iomanip> 
using namespace std;
int main()
{
	typedef map<string, long> mapType;
	mapType Covid_19;
	string states[]={"Uttar Pradesh","Maharashtra","Bihar","West Bengal","Andhra Pradesh","Madhya Pradesh","Tamil Nadu","Rajasthan","Karnataka",
									 "Gujarat","Orissa","Kerala","Jharkhand","Assam","Punjab","Chhattisgarh","Haryana","Uttarakhand","Himachal Pradesh","Tripura",
									 "Meghalaya","Manipur","Nagaland","Goa","Arunachal Pradesh","Mizoram","Delhi","Jammu and Kashmir + Ladakh"},state;
	long co_pt_cnt[]={199812341,112374333,104099452,91276115,84580777,72626809,72147030,68548437,61095297,60439692,41974218,33406061,32988134,31205576,
										 27743338,25545198,25351462,10086292,6864602,3673917,2966889,2855794,1978502,1458545,1383727,1097206,16787941,12541302},C19_cnt;
	for(int i=0;i<28;i++)
	 	Covid_19.insert(pair<string, long>(states[i],co_pt_cnt[i]));
	int cho;
	char ch;
	mapType::iterator iter = Covid_19.begin();
	do
	{
		cout<<"\n\t\t Map Menus"<<endl;
		cout<<"\t-----------------------------------------------------"<<"\n\t 1. Display all States C19_cnt"<<"\n\t 2. Find Particular State C19_cnt"
				<<"\n\t 3. Update C19_cnt"<<"\n\t 4. Size of C19_cnt Map"<<"\n\t 5. Add another State C19_cnt"<<"\n\t 6. Exit"
				<<"\n\t-----------------------------------------------------"<<"\n\t Enter your choice:";
		cin>>cho;
		switch(cho)
		{
			case 1: cout<<"\n\t"<<left<<setw(30)<<"State "<<setw(20)<<"Covid_19 Patient Count"<<endl;
							cout<<"\t-----------------------------------------------------"<<endl;
							for (iter = Covid_19.begin(); iter != Covid_19.end(); ++iter)
								cout <<"\t"<<left<<setw(30)<<iter->first <<setw(20)<< iter->second <<endl;
							cout<<"\t-----------------------------------------------------"<<endl;
							break;
			case 2:	cout<<"\n\t Enter the State Name:";
							fflush(stdin);
							getline(cin,state);
							iter = Covid_19.find(state);
							if( iter != Covid_19.end()) 
								cout <<"\n\t "<<state <<"'s Covid Patient Count is "<< iter->second <<endl;
							else
								cout << "\n\t Key is not in Covid_19 Database." <<endl;
							break;
			case 3: cout<<"\n\t Enter the State Name:";
							fflush(stdin);
							getline(cin,state);
							cout<<"\n\t Enter Updated Covid 19 Patient Count:";
							cin>>C19_cnt;
							Covid_19[state]=C19_cnt;
							break;
			case 4:	cout <<"\t Size of Covid_19 Database: " << Covid_19.size() <<endl;
							break;
			case 5:	cout<<"\n\t Enter the State Name:";
							fflush(stdin);
							getline(cin,state);
							cout<<"\n\t Enter Covid Patient Count:";
							cin>>C19_cnt;
							Covid_19.insert(pair<string, long>(state,C19_cnt));
							break;
			case 6: exit(0);
			default:cout<<"\n\t Enter choice inbetween 1 to 6 only.";
							break;
		}
		cout<<"\n\t Do you want to continue(y/n):";
		fflush(stdin);
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	return 0;
}
