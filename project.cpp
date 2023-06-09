
#include "header.h"
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

using namespace std;

void display_menu() {
    std::cout << "Flex Management System Menu" << endl;
    std::cout << "1. View administrator information" << endl;
    std::cout << "2. view staff" << endl;
    std::cout << "3. view students" << endl;
    std::cout << "4. view teachers" << endl;
    std::cout << "5. Add new teacher" << endl;
    std::cout << "6. add a new student" << endl;
    std::cout << "7. Edit student details" << endl;
    std::cout << "8. edit teacher details" << endl;
    std::cout << "8. Exit" << endl;
}
class Administraton {
public:
    string name = "ADMIN";
    string email = "offical_admin@cfd.nu.edu.pk";
    string phone = "xxxx-xxxxxx";

    void display_info() const {
        std::cout << "Name: " << name << endl;
        std::cout << "Email: " << email << endl;
        std::cout << "Phone: " << phone << endl;
    }
    void view_students()
    {
        ifstream infile("student.txt");

        string line;
        while (std::getline(infile, line))
        {
            std::cout << line << endl;
        }
    }
    void view_teachers()
    {
        ifstream infile("Teacher.txt");

        string line;
        while (std::getline(infile, line))
        {
            std::cout << line << endl;
        }
    }
    void add_student();
    void add_teacher();
    void course();
    void edit_teacher_details();
    void edit_student_details();

    bool feestatus(string fee)
    {
        std::cout << "enter fee status :(true/false)" << endl;
        std::cin >> fee;
        if (fee == "paid")
        {
            return true;
        }
        else
        {
            return false;
        }
    }

};
void edit_student_details() {
    string rollNo;
    std::cout << "Enter the Roll no of the student you want to edit: ";
    std::cin >> rollNo;

    ifstream infile{}; ("Student.txt");
    ofstream outfile{}; ("temp.txt", ios::app);
    bool found = false;

    if (infile.is_open() && outfile.is_open()) {
        string line;
        while (std::getline(infile, line)) {
            //stringstream ss(line);
            string sRollNo, firstName, lastName, feeStatus, address, contactNo;

            std::getline(std::cin, sRollNo, ',');
            std::getline(std::cin, firstName, ',');
            std::getline(std::cin, lastName, ',');
            std::getline(std::cin, feeStatus, ',');
            std::getline(std::cin, address, ',');
            std::getline(std::cin, contactNo, ',');

            if (sRollNo == rollNo) {
                found = true;
                std::cout << "Enter new details for the student:" << endl;
                std::cout << "First Name: ";
                std::cin >> firstName;
                std::cout << "Last Name: ";
                std::cin >> lastName;
                std::cout << "Fee Status: ";
                std::cin >> feeStatus;
                std::cout << "Address: ";
                std::cin.ignore();
                std::getline(std::cin, address);
                std::cout << "Contact No: ";
                std::cin >> contactNo;
            }

            outfile << sRollNo << "," << firstName << "," << lastName << "," << feeStatus << "," << address << "," << contactNo << endl;
        }

        infile.close();
        outfile.close();

        if (found) {
            remove("Student.txt");
            rename("temp.txt", "Student.txt");
            std::cout << "Student details updated successfully." << endl;
        }
        else {
            remove("temp.txt");
            std::cout << "Student not found." << endl;
        }

    }
    else {
        std::cout << "Unable to open file." << endl;
    }
}
void add_student()
{

    string firstName, courses, address, lastName, s_id, department, username, password, gender, contactNo, qualification;
    int reg_date, contact_no;
    bool feestatus;
    char bloodgroup;

    std::cout << "Enter the following details to add a new teacher:" << endl;
    std::cout << "First Name: ";
    std::cin >> firstName;
    std::cout << "Last Name: ";
    std::cin >> lastName;
    std::cout << "Department Name (1. Computer Science, 2. Electric Engineering, 3. Software Engineering, 4. Business, 5. Social Sciences): ";
    int choice;
    std::cin >> choice;
    switch (choice) {
    case 1:
        department = "Computer Science";
        break;
    case 2:
        department = "Electric Engineering";
        break;
    case 3:
        department = "Software Engineering";
        break;
    case 4:
        department = "Business";
        break;
    case 5:
        department = "Social Sciences";
        break;
    default:
        std::cout << "Invalid choice." << endl;
        return;
    }
    std::cout << "enter student id :" << endl;
    std::getline(std::cin, s_id);
    std::cout << "enter contact no:" << endl;
    std::cin >> contact_no;
    std::cout << "enter registration date (dd/mm/yyyy)" << endl;
    std::cin >> reg_date;
    std::cout << "enter qualification :" << endl;
    std::getline(std::cin, qualification);
    //  bool feestatus(bool fee);
    std::cout << "enter blood group:" << endl;
    std::cin >> bloodgroup;
    std::cout << "enter address :" << endl;
    std::getline(std::cin, address);
    //void courses();
   // int username;
    //string password;
    std::cout << " user : ";
    std::getline(std::cin, username);
    fstream out("students.txt", ios::app);
    // out << username << endl;
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "password : ";
    std::cin >> password;
    // std::cout << password;
    ofstream outfile("student.txt", ios::app);
    if (outfile.is_open()) {
        outfile << s_id << "," << firstName << "," << lastName << "," << department << "," << username << "," << password << "," << reg_date << "," << gender << "," << contactNo << "," << qualification << "," << address << endl;
        std::cout << "New student added successfully." << endl;
        outfile.close();
    }
    else {
        std::cout << "Unable to open file." << endl;
    }
    system("cls");


}

bool feestatus(string fee)
{
    std::cout << "enter fee status :(true/false)" << endl;
    std::cin >> fee;
    if (fee == "paid")
    {
        return true;
    }
    else
    {
        return false;
    }
}
string course(string courses)
{

    std::cout << "enter courses:(seprated by , :" << endl;
    std::getline(std::cin, courses);

    return courses;
}
void edit_teacher()
{
    string t_id;;
    std::cout << "Enter the teacher id of the teacher you want to edit: ";
    std::cin >> t_id;

    ifstream infile("teacher.txt");
    ofstream outfile("temp.txt", ios::app);
    bool found = false;

    if (infile.is_open() && outfile.is_open()) {
        string line;
        while (std::getline(infile, line)) {
            //stringstream ss(line);
            string tRollNo, firstName, lastName, t_id, address, contactNo;

            // std::getline(std::cin, sRollNo, ',');
            std::getline(std::cin, firstName, ',');
            std::getline(std::cin, lastName, ',');
            //std::getline(std::cin, feeStatus, ',');
            std::getline(std::cin, address, ',');
            std::getline(std::cin, contactNo, ',');

            if (t_id == t_id) {
                found = true;
                std::cout << "Enter new details for the teacher :" << endl;
                std::cout << "First Name: ";
                std::cin >> firstName;
                std::cout << "Last Name: ";
                std::cin >> lastName;
                std::cout << "Address: ";
                std::cin.ignore();
                std::getline(std::cin, address);
                std::cout << "Contact No: ";
                std::cin >> contactNo;
            }

            outfile << t_id << "," << firstName << "," << lastName << "," << address << "," << contactNo << endl;
        }

        infile.close();
        outfile.close();

        if (found) {
            remove("teacher.txt");
            rename("temp.txt", "teacher.txt");
            std::cout << "teacher details updated successfully." << endl;
        }
        else {
            remove("temp.txt");
            std::cout << "teacher not found." << endl;
        }

    }
    else {
        std::cout << "Unable to open file." << endl;
    }
}


void add_teacher()
{
    string firstName, t_id, lastName, department, username, password, gender, contactNo, qualification, address;
    std::cout << "Enter the following details to add a new teacher:" << endl;
    std::cout << "First Name: ";
    std::cin >> firstName;
    std::cout << "Last Name: ";
    std::cin >> lastName;
    std::cout << "teacher id :";
    std::cin >> t_id;
    std::cout << "Department Name (1. Computer Science, 2. Electric Engineering, 3. Software Engineering, 4. Business, 5. Social Sciences): ";
    int choice;
    std::cin >> choice;
    switch (choice) {
    case 1:
        department = "Computer Science";
        break;
    case 2:
        department = "Electric Engineering";
        break;
    case 3:
        department = "Software Engineering";
        break;
    case 4:
        department = "Business";
        break;
    case 5:
        department = "Social Sciences";
        break;
    default:
        std::cout << "Invalid choice." << endl;
        return;
    }
    static int teacherCount = 0;
    teacherCount++;
    string tID = department.substr(0, 1) + "-" + to_string(teacherCount);

    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;
    std::cout << "Registration Date: ";
    string regDate;
    std::cin.ignore();
    std::getline(std::cin, regDate);
    std::cout << "Gender: ";
    std::cin >> gender;
    std::cout << "Contact No: ";
    std::cin >> contactNo;
    std::cout << "Qualification: ";
    std::cin.ignore();
    std::getline(std::cin, qualification);
    std::cout << "Address: ";
    std::getline(std::cin, address);

    ofstream outfile("Teacher.txt", ios::app);
    if (outfile.is_open()) {
        outfile << tID << "," << firstName << "," << lastName << "," << department << "," << username << "," << password << "," << regDate << "," << gender << "," << contactNo << "," << qualification << "," << address << endl;
        std::cout << "New teacher added successfully." << endl;
        outfile.close();
    }
    else {
        std::cout << "Unable to open file." << endl;
    }
    system("cls");
}
class HOD {
private:
    //username password already defined
    string hod_username;
    string hod_password;

public:
    //user name password from user
    string hod_usr;
    string hod_pas;
    HOD() {
        hod_username = "hod_nuces@nu.edu.pk";
        hod_password = "12345678";
    }
    bool hod_signinn()
    {
        std::cout << " enter your username : " << endl;
        std::cin >> hod_usr;
        std::cout << endl;
        std::cout << " enter your password :" << endl;
        std::cin >> hod_pas;
        if (hod_pas == hod_password && hod_usr == hod_username)
        {
            return true;
        }
        return false;
    }
    void hod_menu_display()
    {
        std::cout << "  __SELECT THE DESIRED OPTION__" << endl;
        std::cout << " 1. access student module " << endl;
        std::cout << " 2. view all students " << endl;
        std::cout << " 3. view all tachers " << endl;
    }

};

class Teacher
{
public:

    Teacher()
    {
    }
    // void time_table();
    void time_table();
    void marks();
    bool attendance();
    char grades();

    friend class Student;
};

void Teacher::time_table()
{
    std::cout << "timetable" << endl;
    std::cout << "lecture   date    section " << endl;
    std::cout << "opp      26 may     2b    " << endl;
}
void Teacher::marks()
{
    int marks;
    std::cout << "enter marks ?" << endl;
    std::cin >> marks;

}
bool Teacher::attendance()
{
    bool attendance;
    std::cout << "enter attendance ?" << endl;
    std::cin >> attendance;
    return attendance;
}
char Teacher::grades()
{
    char grade;
    std::cout << "enter grade";
    std::cin >> grade;
    return grade;
}


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
Administraton A;
// Studentei

Student::Student(string name, int roll_number) : name_(name), roll_number_(roll_number), marks_(0), attendance_(false), grade_('F') {}
void Student::student_display_menu()
{
    std::cout << "student portal" << endl;
    std::cout << "enter 1 for attendance" << endl;
    std::cout << "enter 2 for marks" << endl;
    std::cout << "enter 3 for grades" << endl;
    std::cout << "enter 4 for registered courses" << endl;
    std::cout << "enter 5 for fee status" << endl;
}
void Student::admin()
{
    Administraton A;
}
string Student::course(Administraton& s, string course_name)
{
    //course_name = s.course();
    return course_name;
}
void Student::marks(Teacher& s, int marks)
{
    marks = marks;
}

//bool Student::feestatus(Administraton&a,bool fee)
//{
//    fee == A.feestatus(A,bool +fee);
//}
bool Student::attendance(Teacher& s, bool attendance)
{
    attendance = attendance;
    return attendance;
}

void assign_grade(Teacher& student, char grade)
{
    grade = student.grades();
}
