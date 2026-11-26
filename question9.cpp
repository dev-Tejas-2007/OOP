#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class student{
    public:
    int roll;
    string name;
    float marks;
    void input(){
        cout<<"enter your roll no:"<<endl;
        cin>>roll;
        cout<<"enter your name:"<<endl;
        cin>>name;
        cout<<"enter your marks:"<<endl;
        cin>>marks;
        
    }
   void display() const {
    cout << roll << " | " << name << " | " << marks << endl;
}
};

void write(const string& filename, int count) {
    ofstream outfile(filename, ios::out);
    if (!outfile) {
        cout << "Error occurred:" << endl;
        return;
    }
    student s;
    for (int i = 0; i < count; i++) {
        cout << "\nenter the details for number: " << i + 1 << endl;
        s.input();
        outfile << s.roll << " " << s.name << " " << s.marks << "\n";  // inside loop
    }
    outfile.close();
    cout << "\nrecords added." << endl;
}
void read(const string& filename) {
    ifstream infile(filename, ios::in);
    if (!infile) {
        cout << "the file cant open" << endl;
        return;
    }
    student s;
    cout << "\nroll no | name | marks\n";
    while (infile >> s.roll >> s.name >> s.marks) {
        s.display();
    }
    infile.close();
}
int main(){
    string filename="studentdata.txt";
    int n;
    cout<<"enter the number of entries of students:";
    cin>>n;
    write(filename,n);
    read(filename);
    return 0;
}
