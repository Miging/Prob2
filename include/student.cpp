#include <iostream>
#include <fstream>
#include <algorithm>
#include "student.h"

using namespace std;

Student::Student(string name,string id,string year,string department,string tel)
        :name(name),id(id),year(year),department(department),tel(tel)
{}
Student::Student(){}
bool Student::setName(string name) {
    if(name.length()>15 or name.length()==0) {
        cout<<"ERROR: name should not be blanks and has up 15 (English)"<<endl;
        return false; };
    for (char c :name){
        if(!isalpha(c) and c!=' ') {
            cout<<"ERROR: name is English"<<endl;
            return false; };
    }
    this->name=name;
    return true;
}
bool Student::setId(string id) {
    if (id.length() != 10){
        cout << "ERROR: id should not be blanks and exactly 10 digits" << endl;
        return false;
    }
    for (char c: id) {
        if(!isnumber(c)) {
            cout<<"ERROR: id is number"<<endl;
            return false; };
    }
    if(stoi(id.substr(0,4))<1916 or stoi(id.substr(0,4))>2023){
        cout<<"ERROR: first 4 digit is admission year. it should be 1916~2023"<<endl;
        return false;
    }
    this->id= (id);
    return true;
}
bool Student::setYear(string year) {
    if(year.length()!=4) {
        cout<<"ERROR: birth year should be exactly 4 digits"<<endl;
        return false;
    }
    if(stoi(year)<1900 or stoi(year)>2023){
        cout<<"ERROR: invalidated birth year. it should be 1900~2023 "<<endl;
        return false;
    }
    for (char c : year) {
        if(!isnumber(c)) {
            cout<<"ERROR: birth year is number"<<endl;
            return false; };
    }
    this->year=year;
    return true;
}
void Student::setDepartment(string department) {
    this->department=department;
}
bool Student::setTel(string tel) {
    if(tel.length()>12) {
        cout<<"ERROR: tame has up to 12 digits"<<endl;
        return false; }
    for (char c:tel){
        if(!isnumber(c)){
            cout<<"ERROR: tel is number"<<endl;
        }
    }
    this->tel=tel;
    return true;
}

StudentDB::StudentDB(){}

void StudentDB::printStudent(Student s) {
    cout<<right<<setw(13)<<s.getName()<<setw(11)<<s.getId()<<setw(21)<<s.getDepartment()<<setw(11)<<s.getYear()<<"  "<<s.getTel()<<endl;
}

void StudentDB::getAll(){

    sort(students.begin(),students.end(), [this](Student a, Student b) {
        switch (sortOption) {
            case 1:
                return a.getName()<b.getName();
            case 2:
                return a.getId()<b.getId();
            case 3:
                return a.getYear()<b.getYear();
            case 4:
                return a.getDepartment()<b.getDepartment();
        }
    });
    cout<<left<<setw(13)<<"Name"<<setw(11)<<" StudentID"<<setw(21)<<" Dept"<<setw(10)<<" Birth Year"<<" Tel"<<endl;
    for(Student &s:students){
        printStudent(s);
    }
    cout<<"End of the List"<<endl;
}

void StudentDB::addStudent(Student student){
    students.push_back(student);
    //파일에도 넣어야함
}
void StudentDB::addTxt(Student newStudent,fstream& file) {
    file<<newStudent.getName()<<","<<newStudent.getId()<<","<<newStudent.getDepartment()<<","<<newStudent.getYear()<<","<<newStudent.getTel()<<endl;
}
void StudentDB::searchByName(string name) {
    bool found=false;
    cout<<left<<setw(13)<<"Name"<<setw(11)<<" StudentID"<<setw(21)<<" Dept"<<setw(10)<<" Birth Year"<<" Tel"<<endl;
    for(Student student:students){
        if(student.getName()==name) printStudent(student);
        found=true;
    }
    if(!found) cout<<"ERROR: not found"<<endl;
}
void StudentDB::searchByID(string id) {
    bool found=false;
    cout<<left<<setw(13)<<"Name"<<setw(11)<<" StudentID"<<setw(21)<<" Dept"<<setw(10)<<" Birth Year"<<" Tel"<<endl;
    for(Student student:students){
        if(student.getId()==id) printStudent(student);
        found=true;
    }
    if(!found) cout<<"ERROR: not found"<<endl;
}
void StudentDB::searchByYear(string year) {
    bool found=false;
    cout<<left<<setw(13)<<"Name"<<setw(11)<<" StudentID"<<setw(21)<<" Dept"<<setw(10)<<" Birth Year"<<" Tel"<<endl;
    for(Student student:students){
        if(student.getYear()==year) printStudent(student);
        found=true;
    }
    if(!found) cout<<"ERROR: not found"<<endl;
}
void StudentDB::searchByDepartment(string department) {
    bool found=false;
    cout<<left<<setw(13)<<"Name"<<setw(11)<<" StudentID"<<setw(21)<<" Dept"<<setw(10)<<" Birth Year"<<" Tel"<<endl;
    for(Student student:students){
        if(student.getDepartment()==department) printStudent(student);
        found=true;
    }
    if(!found) cout<<"ERROR: not found"<<endl;
}
bool StudentDB::setSortOption(int answer) {
    if (answer>4 or answer<=0) {
        cout<<"ERROR: Select the (1~4) number"<<endl;
        return false;}
    sortOption=answer;
    return true;
}
bool StudentDB::isIDinDB(string id) {
    for(Student s:students){
        if(s.getId()==id) {
            cout<<"ERROR: Already Inserted"<<endl;
            return true; }
    }
    return false;
}


