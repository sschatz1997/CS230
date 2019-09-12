//Student.cpp
#include"Student.h"
//constructors
Student::Student()  //default constructor definition
{ 
    first_name = "";
    last_name = "";
    id = "";
    gpa = 0.0;
                    }

Student::Student(string first, string last)//overloaded constructor definition
{ 
    first_name = first;
    last_name = last;
    id = "";
    gpa = 0.0;
                        }

Student::Student(string first, string last, string i, double g)
{
    first_name = first;
    last_name = last;
    id = i;
    gpa = g;}
//accessors
void Student::print() const
{
     cout <<"Student information\n"
          <<"===================\n"
          <<"Full Name: "<<first_name<<" "<<last_name<<"\n"
          <<"Student ID: "<<id<<"\n"
          <<"GPA = "<<gpa<<endl;
                 }
double Student::getGPA() const { return gpa;}

//mutators
void Student::setName(string first, string last)
{
     first_name = first;
     last_name = last;
}
 
 void Student::setGPA(double g){ 
      
      if (g>=0.0 && g <= 4.0)
         gpa = g;
      else
          gpa = -1;
      
 }
 
 void Student::setID(string i)
 {
      id = "Capitol " + i;
 }
