#include <iostream>
#include <fstream>
using namespace std;
#include <vector>
#include <sstream>
#include <filesystem>
#include "include//student.h"



int main(int argc, char const *argv[]){
    cout<<"start"<<endl;
    string path=argv[1];
    fstream file;
    if(!filesystem::exists(path))  file.open(path,ios::app);
    else file.open(path,ios::in|ios::out);
    if (!file.is_open()) {
        cout << "파일을 열 수 없습니다." << endl;
        return 1;
    }
    string s;
    StudentDB students;


    //reading file
    while(getline(file,s))
    {
        istringstream iss(s);
        Student student;
        string word;
        getline(iss,word,',');
        student.setName(word);
        getline(iss,word,',');
        student.setId(word);
        getline(iss,word,',');
        student.setDepartment(word);
        getline(iss,word,',');
        student.setYear(word);
        getline(iss, word);
        student.setTel(word);
        students.addStudent(student);
    }
    file.close();
    while (true) {
        cout << "1. Insertion" << endl;
        cout << "2. Search" << endl;
        cout << "3. Sorting Option" << endl;
        cout << "4. Exit" << endl;
        cout<<">"<<endl;
        int answer;
        cin >> answer;
        switch (answer) {
            case 1: {
                /* code */
                cout << "insert" << endl;
                fstream file(path, ios::app);
                //insert
                Student newStudent;
                cin.ignore();
                do {
                    cout << "name ?" << endl;
                    getline(cin, s, '\n');
                } while (!newStudent.setName(s));
                do {
                    cout << "Student ID (10 digits) ?" << endl;
                    getline(cin, s, '\n');
                } while (students.isIDinDB(s) or!newStudent.setId(s));
                do {
                    cout << "Birth year (4 digits) ?" << endl;
                    getline(cin, s, '\n');
                } while (!newStudent.setYear(s));
                cout << "Department ?" << endl;
                getline(cin, s, '\n');
                newStudent.setDepartment(s);
                do {
                    cout << "Tel ?" << endl;
                    getline(cin, s, '\n');
                } while (!newStudent.setTel(s));
                students.addStudent(newStudent);
                students.addTxt(newStudent, file);
                file.close();
                break;
            }
            case 2:
                //Search
                cout << "Search - " << endl;
                cout << "1. Search by name" << endl;
                cout << "2. Search by student ID (10 numbers)" << endl;
                cout << "3. Search by admission year (4numbers)" << endl;
                cout << "4. Search by department name" << endl;
                cout << "5. List All" << endl;
                cout<<">"<<endl;
                cin >> answer;
                cin.ignore();
                switch (answer) {
                    case 1:
                        cout << "Name?";
                        getline(cin,s,'\n');
//                    /* code */
                        students.searchByName(s);
                        break;
                    case 2:
                        cout << "Student ID?";
                        getline(cin,s,'\n');
                        students.searchByID(s);
                        break;
                    case 3:
                        cout << "Admission year?";
                        getline(cin,s,'\n');
                        students.searchByYear(s);
                        break;
                    case 4:
                        cout << "Department name keyword?";
                        getline(cin,s,'\n');
                        students.searchByDepartment(s);
                        break;
                    case 5:
                        students.getAll();
                        break;
                    default:
                        cout << "Error! select (1~5) Number" << endl;
                        break;
                }
                break;
            case 3://sorting Option
                do {
                    cout<<"- Sorting Option"<<endl;
                    cout<<"1. Sort by name"<<endl;
                    cout<<"2. Sort by Student ID"<<endl;
                    cout<<"3. Sort by Admission Year"<<endl;
                    cout<<"4. Sort by Department name"<<endl;
                    cout<<">";
                    cin >> answer;
                    cin.ignore();
                } while (!students.setSortOption(answer));
                break;
            case 4:
                //exit
                return 0;
            default:
                cout << "Error! select (1~4) Number" << endl;
                //error
                break;
        }
    }
    return 0;
}
