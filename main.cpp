#include "header.h"
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

int main()
{
    Teacher Teach;
    Administraton  admin;
    string student_name;
    int student_roll = 0;
    int marks = 11;
    bool attendance = true;
    char grades = 'f';
    string course = "diff";



    Student s(student_name, student_roll);
    HOD hod;
    string password;
    string username;
    string username_ADMIN, username_student, password_student;
    string password_ADMIN;
    string username_HOD;
    string password_HOD;

    int choice = 0;

    //menu 1
    std::cout << "  _______WELCOME TO FLEX MANAGMENT SYSTEM________ " << "\n";
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";
    std::cout << " press 1 if you want to LOG IN as Student " << "\n";
    std::cout << "\n"; std::cout << "\n";
    std::cout << " press 2 if you want to LOG IN as ADMIN : " << "\n";
    std::cout << "\n";
    std::cout << " press 3 if you want to LOG IN as Teacher :" << "\n";
    std::cout << "\n"; std::cout << "\n";
    std::cout << " press 4 if you want to LOG IN as HOD : " << "\n";
    std::cin >> choice;
    system("cls");




    if (choice == 1)// SIGN INN as student
    {
        std::cout << "        ----SIGNING in as Student----- " << endl << endl;
        std::cout << " USER : " << endl << endl;
        std::cin >> username_student;
        std::cout << " PASSWORD : " << endl;
        std::cin >> password_student;
        if (username_student == "official_student@nu.edu.pk" && password_student == "12345678")
        {
            std::cout << "     _WELCOME_";
            int choice = 0;
            while (choice != 7)
            {
                s.student_display_menu();
                std::cout << "Enter your choice: ";

                std::cin >> choice;
                std::cout << endl;

                switch (choice)
                {
                case 1:
                    s.attendance(Teach, attendance);
                    break;
                case 2:
                    s.marks(Teach, marks);
                    break;
                case 3:
                    s.grades(Teach, grades);
                    break;
                case 4:
                    s.course(admin, course);
                    break;
                case 5:
                    //s.feestatus(admin,feestatus);
                    break;

                default:
                    std::cout << "Invalid choice. Please try again." << std::endl;
                    break;
                }
            }
        }

    }
    if (choice == 2)//SIGN IN as admin
    {
        std::cout << "        ----SIGNING in as ADMIN----- " << endl << endl;
        std::cout << " USER : " << endl << endl;
        std::cin >> username_ADMIN;
        std::cout << " PASSWORD : " << endl;
        std::cin >> password_ADMIN;
        if (username_ADMIN == "official_admin@nu.edu.pk" && password_ADMIN == "12345678")// if admin password correct
        {
            std::cout << "     _WELCOME_";
            int choice = 0;
            while (choice != 7)
            {
                display_menu();
                std::cout << "Enter your choice: ";

                std::cin >> choice;
                std::cout << endl;

                switch (choice)
                {
                case 1:
                    admin.display_info();
                    break;
                case 2:
                    std::cout << "staff info" << endl;
                    admin.view_teachers();
                    break;
                case 3:
                    admin.view_students();
                    break;
                case 4:
                    admin.view_teachers();
                    break;
                case 5:
                    admin.add_teacher();
                    break;
                case 6:
                    admin.edit_student_details();
                    break;
                case 7:
                    admin.add_student();
                    break;
                case 8:
                    std::cout << " exiting ...... ";
                    break;

                default:
                    std::cout << "Invalid choice. Please try again." << std::endl;
                    break;
                }

                std::cout << std::endl;
            }
        }
        else
        {
            std::cout << " ACCESS DENIED" << endl;
            std::cout << endl;
            std::cout << " incorrect login or password " << endl;
        }
    }
    string username_teacher, password_teacher;

    if (choice == 3)
    {
        std::cout << "          ----------sigining in As teacher---------" << endl;
        std::cout << " USER : " << endl << endl;
        std::cin >> username_teacher;
        std::cout << " PASSWORD : " << endl;
        std::cin >> password_teacher;
        if (username_ADMIN == "official_teacher@nu.edu.pk" && password_ADMIN == "12345678")
        {
            std::cout << "welcome as teacher" << endl;

            std::cout << "enter 1 for timetable" << endl;
            std::cout << "enter 2 assign marks" << endl;
            std::cout << "enter 3 marking attendance" << endl;
            std::cout << "enter 4 assign grades" << endl;
            switch (choice)
            {
            case 1:
                Teach.time_table();
                break;
            case 2:
                Teach.marks();
                break;
            case 3:
                Teach.attendance();
                break;
            case 4:
                Teach.grades();
                break;
            case 5:
                std::cout << "invalid option" << endl;
                break;


            }
        }
    }
    ;
    if (choice == 4)
    {
        std::cout << "        ----SIGNING in as HOD----- " << endl << endl;

        if (hod.hod_signinn() == true)
        {
            hod.hod_menu_display();
            std::cin >> choice;
            switch (choice)
            {
            case 1:
                std::cout << " accessing student module ..." << endl;
                break;
            case 2:
                admin.view_students();
                break;
            case 3:
                admin.view_teachers();
                break;
            default:
                std::cout << " invalid option selected " << endl;
            }
        }

    }
}
