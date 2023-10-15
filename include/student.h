#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <vector>
using namespace std;


class Student
{
private:
    /* data */
    //"Name" has up to 15 (English) characters , "Student ID" should be
    //exactly 10 digits where first 4 digits represent admission year. “Birth
    //
    //Year” should be exactly 4 digits. "Tel" has up to 12 digits.
    string name;//not null
    string id;//not null/first 4 digits is year//if the same id->error
    string year;//4digits
    string department;
    string tel;//12digits
public:
    Student();
    Student(string name, string id, string year, string department, string tel);
    // //setter
    bool setName(string name);
    bool setId(string id);
    bool setYear(string year);
    void setDepartment(string department);
    bool setTel(string tel);

    //get
    string getName(){return this->name;};
    string getId(){return this->id;};
    string getYear(){return this->year;};
    string getDepartment(){return this->department;};
    string getTel(){return this->tel;};
};


class StudentDB
{
private:
    /* data */
    vector<Student> students;
    int sortOption=1;
public:
    StudentDB(/* args */);

    //print
    void printStudent(Student student);
    //insert
    void addStudent(Student student);
    //insert in txt file
    void addTxt(Student newStudent,fstream& file);

    //list all
    void getAll();

    //search
    void searchByName(string name);
    void searchByID(string id);
    void searchByYear(string year);
    void searchByDepartment(string department);

    bool isIDinDB(string id);

    //compare for sort
    bool compare(Student& a,Student& b) const;

    //sort
    bool setSortOption(int answer);
};

#endif


