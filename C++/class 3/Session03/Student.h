//Student.h
#include<iostream>
#include<string>
using namespace std;

class Student{
      public:
             //constructor
          Student();
          Student(string first, string last);
          Student(string first, string last, string i, double g);
          
          //accessors
          void print() const;
          string getName() const;
          string getID() const;
          double getGPA() const;
          
          //mutators
          void setName(string first, string last);
          void setGPA(double);
          void setID(string);
      private:
              string first_name;
              string last_name;
              string id;
              double gpa;
      
      };
