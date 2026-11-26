#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
    fstream file;
    string line;    
    file.open("xyz.txt",ios::out);
    if(!file.is_open()){
        cout<<"the file can't open for outfile";
        return 1;
    }
    file<<"line 1: the writing is done"<<endl;
    file.close();
     file.open("xyz.txt",ios::app|ios::out);
    if(!file.is_open()){
        cout<<"the file can't open";
        return 1;
    }
    file<<"line 2:the appending is done "<<endl;
    file.close();
    
    file.open("xyz.txt",ios::in);
    if(!file.is_open()){
        cout<<"the file is cant open for the reading ";
        return 1;

    }
    file<<"line 3: reading is done"<<endl;
    while(getline(file,line)){
        cout<<line<<endl;
    }
    file.close();
    return 0;
}
