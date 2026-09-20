//detecting End Of File (EOF)
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
    ifstream fin("anisa.txt");

    if(!fin){
        cerr << "Unable to open file!" << endl;
        return 1;
    }

    string line;
    cout << "Reading file until EOF:" << endl;

    while(!fin.eof()){
    	getline(fin,line);
    	cout << line << endl;
	
    }

    fin.close();
    return 0;
}
