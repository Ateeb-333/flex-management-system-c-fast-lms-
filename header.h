#pragma once

#define HEADER_H
#include <iostream>
#include<iomanip>
#include<fstream>
#include<string.h>
#include <ctime>
#include <string>
#include <Windows.h>
#include <cstdlib>
#include <stdlib.h>
using std::cout;
using std::cin;
using std::getline;
using std::ifstream;
using std::ofstream;
using std::basic_ostream;
using std::basic_iostream;
using std::basic_ofstream;
using std::string;
using std::char_traits;

void display_menu();

class Administraton {
public:
    string name = "ADMIN";
    string email = "offical_admin@cfd.nu.edu.pk";
    string phone = "xxxx-xxxxxx";

    void display_info();
    void view_students();

    void view_teachers();

    void add_student();
    void add_teacher();
    void course();
    void edit_teacher_details();
    void edit_student_details();

    bool feestatus(string fee);


};
class HOD {
private:

    string hod_username;
    string hod_password;

public:

    string hod_usr;
    string hod_pas;
    HOD();
    bool hod_signinn();

    void hod_menu_display();

};

class Teacher
{
public:

    Teacher();
    void time_table();
    void marks();
    bool attendance();
    char grades();

    friend class Student;
};
class Student
{

public:
    Student(string name, int roll_number);

    void marks(Teacher& s, int marks);



    bool feestatus(Administraton, bool fee);

    bool attendance(Teacher& s, bool attendance);

    void grades(Teacher& student, char grade);

    string course(Administraton& student, string course_name);

    void student_display_menu();
    bool feestatus(bool fee);

    void admin();

    //private:
    std::string name_;
    int roll_number_;
    int marks_;
    bool attendance_;
    char grade_;
};


