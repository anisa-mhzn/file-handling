//stream class hiearchy 
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
	string text;
	cout<<"Enter a line of text "<<endl;
	getline(cin,text);
	ofstream fout("anisa.txt");  //output file stream
	
	if(!fout){
		cerr<<"Unable to open file for writing!"<<endl;
		return 1;
	}
	fout<<text<<endl;  //writing text in file
	fout.close();
	
	cout<<"Data written in text file successfully!"<<endl;
	ifstream fin("anisa.txt");  //input file stream
	if(!fin){
		cerr<<"Unable to open file for reading!";
		return 1;
	}
	
	cout<<"Reading data back from file!"<<endl;
	while(getline(fin,text)){
		cout<<text<<endl;
	}
	fin.close();
}