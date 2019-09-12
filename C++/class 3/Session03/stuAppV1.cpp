#include <cstdlib>
#include <iostream>
#include "Student.h"

using namespace std;
int addStudents(Student* stuPTR, int counter)
{
    string first, last, id;
    double gpa;
    int stuNum;
    cout <<"How many students do you want to enter?: ";
    cin >>stuNum;
    for (int i = 0; i < counter; i++)
        stuPTR++;        
        
    for (int i = 0; i < stuNum; i++)
    {
        cout <<"Enter student full name: ";
        cin >>first>>last;
        cout <<"Enter student ID: ";
        cin >>id;
        cout <<"Enter the GPA = ";
        cin >>gpa;
        
        //update the object where you're pointing
        stuPTR ->setName(first, last);
        stuPTR ->setID(id);
        stuPTR ->setGPA(gpa);
        
        //move the pointer
        stuPTR++;
        //update the counter
        counter++; 
    }
    
    
    return counter;
}

void printStudents(Student* stuPTR, int counter)
{
     for (int i = 0; i < counter; i++)
     {
         stuPTR -> print();
         stuPTR++;
     }
}

int menu()
{
    int choice;
    cout <<"\t\tMain Menu\n"
         <<"\t\t=========\n"
         <<"\t\t1. Add Students\n"
         <<"\t\t2. View ALL Students\n"
         <<"\t\t3. EXIT\n"
         <<"\tEnter your choice: ";
    cin >>choice;
    return choice;
}

int main(int argc, char *argv[])
{
    int option;
    Student stu[100];  //student buffer
    int rec = 0;  //record counter
    
    do
    {
        system("CLS");
        option = menu();
        
        switch(option)
        {
                      case 1: rec = addStudents(stu, rec);
                           break;
                      case 2:printStudents(stu, rec);
                           break;
                      case 3: cout <<"Goobye!\n";
                           break;
                      default: cout <<"Invalide choice!\n";
                      
                      
        }
        
        system("PAUSE");
    }while (option != 3);
    
    return EXIT_SUCCESS;
}
