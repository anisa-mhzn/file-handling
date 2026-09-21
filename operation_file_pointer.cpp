// Comprehensive Practical: File Operations with File Pointers
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Employee{
	public:
		string name;
		int id;
		float salary;

		Employee(){}   // empty constructor, needed for reading blank objects
		Employee(string n, int i, float s){
			name = n;
			id = i;
			salary = s;
		}
		void display(){
			cout<<"ID= "<<id<<" NAME= "<<name<<" SALARY= "<<salary<<endl;
		}
};

int main(){
	Employee emp[2] = {
		Employee("Anisa", 1, 450000),
		Employee("Sita", 2, 60000)
	};

	// Step 1: Write multiple employee records into a binary file
	ofstream fout("employees.dat", ios::binary);
	if(!fout){
		cout<<"Unable to open file for writing!";
		return 1;
	}
	for(int i=0; i<2; i++){
		fout.write(reinterpret_cast<char*>(&emp[i]), sizeof(emp[i]));
	}
	fout.close();
	cout<<"2 employee records written successfully!"<<endl;

	// Step 2: Open the file again for reading + pointer operations
	ifstream fin("employees.dat", ios::binary);
	if(!fin){
		cout<<"Unable to open file for reading!";
		return 1;
	}

	// Move to the beginning of the file
	fin.seekg(0, ios::beg);
	cout<<"Pointer moved to beginning. Position: "<<fin.tellg()<<endl;

	// Move to the end of the file to check file size
	fin.seekg(0, ios::end);
	cout<<"Pointer moved to end. Position (file size in bytes): "<<fin.tellg()<<endl;

	// Jump to a SPECIFIC record — e.g., record number 2 (index 1, since indexing starts at 0)
	Employee temp;
	fin.seekg(1 * sizeof(Employee), ios::beg);   // skip 1 record, land at the 2nd
	fin.read(reinterpret_cast<char*>(&temp), sizeof(temp));
	cout<<"Jumped directly to record 1: ";
	temp.display();

	// Step 3: Go back to beginning, and read+display ALL records until EOF
	fin.seekg(0, ios::beg);
	cout<<"Reading all records from the start:"<<endl;

	Employee e;
	while(fin.read(reinterpret_cast<char*>(&e), sizeof(e))){
		e.display();
	}
	// loop stops automatically once read() fails at EOF — no eof() trap here

	fin.close();
	return 0;
}

