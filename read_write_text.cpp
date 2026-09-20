//reading and writing text files
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct person{
	string name;
	int age;
};
int main(){
	struct person p[3];
	int i;
	
	//cout<<"Enter name and age "<<endl;
	for(i=0;i<3;i++){
		cout<<"Enter name and age "<<endl;
	cin>>p[i].name>>p[i].age;
  }
	ofstream fout("anisa.txt");  //output file stream
	
	if(!fout){
		cerr<<"Unable to open file for writing!"<<endl;
		return 1;
	}
	for(i=0;i<3;i++){
	fout<<p[i].name<<" "<<p[i].age<<endl;  
	}//writing text in file
	fout.close();
	cout<<"Data written in text file successfully!"<<endl;
	
	ifstream fin("anisa.txt");  //input file stream
	if(!fin){
		cerr<<"Unable to open file for reading!";
		return 1;
	}
	
	cout<<"Reading data back from file!"<<endl;
	string name;
	int age;
	while(fin>>name>>age){
		cout<<"Name= "<<name<<" Age= "<<age<<endl;
	}
	fin.close();
}
