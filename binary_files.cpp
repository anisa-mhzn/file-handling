//reading and writing binary files
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class Student{
	private:
		string name;
		int roll;
		float marks;
	public:
		Student(string n, int r, float m){
			name=n;
			roll=r;
			marks=m;
		}
		void display(){
			cout<<"NAME= "<<name<<endl;
			cout<<"ROLL= "<<roll<<endl;
			cout<<"MARKS= "<<marks<<endl;
		}
};
int main(){
	Student s("anisa",25,90.5f);
	//Student s1("anikesh",11,80.5f);
	ofstream fout("students.dat",ios::binary);
	if(!fout){
		cout<<"Unable to open binary file!";
		return 1;
	}
		fout.write(reinterpret_cast<char*>(&s),sizeof(s));
		//fout.write(reinterpret_cast<char*>(&s1),sizeof(s1));
	fout.close();
	
	ifstream fin("students.dat",ios::binary);
	if(!fin){
		cerr<<"Unable to open binary for reading"<<endl;
		return 1;
	}
	Student s2("",0,0);
	//Student s3("",0,0);
	fin.read(reinterpret_cast<char*>(&s2),sizeof(s2));
	//fin.read(reinterpret_cast<char*>(&s3),sizeof(s3));
	cout<<"Values read from binary file:"<<endl;
    s2.display();
    //s3.display();
	fin.close();
}

