#include <cstdlib>
#include <iostream>
#include "Job.h"

using namespace std;

int addJobs(int counter, Job* jbPTR)
{
    int jobNums;
    
    cout <<"How many jobs do you want to enter?: ";
    cin >>jobNums;
    
    for (int i = 0; i < jobNums; i++)
    {
    }
    
    return counter;
}

int menu()
{
    int choice;
    cout <<"Main Menu\n"
         <<"=========\n"
         <<"1. Add a new job\n"
         <<"2. view the jobs\n"
         <<"5. EXIT\n"
         <<"Enter your choice: ";
    cin >>choice;
    return choice;
}

int main(int argc, char *argv[])
{
    Job jb[100];  //buffer
    int job_counter = 0;
    int option;
    do
    {
        option = menu();
        switch(option)
        {
                      case 1: job_counter = addJobs(job_counter, jb);
                           break;
                      case 2:
                           break;
                      case 5: cout <<"Goodbye!\n";
                           break;
        }
        
        
        
        
        }while (option != 5);
        
        
    
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
