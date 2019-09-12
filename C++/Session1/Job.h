//Job.h
#include<iostream>
#include<string>
using namespace std;

class Job{
      public:
             Job();
             void setData(string, string, double);
             void print();
      private:
              string job_title;
              string company;
              double salary;
      };
