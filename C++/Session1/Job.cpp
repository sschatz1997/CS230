#include "Job.h"

Job::Job()
{
          job_title = "";
          company = "";
          salary = 0.0;
}
void Job::setData(string jbT, string co, double sal)
{
     job_title = jbT;
     company = co;
     salary = sal;
}

void Job::print()
{
     cout <<"Company: "<<company<<"\n"
          <<"Job Title: "<<job_title<<"\n"
          <<"Salary =$"<<salary<<endl;
}
