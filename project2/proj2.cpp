#include <iostream>
#include <fstream>
#include <string.h>
#include <math.h>
using namespace std;

int main()
{
	double * score=NULL;

	score=new double[100];
	string * name=NULL;
	name = new string[100];
	string new_name;
	double new_score;
	bool test= true;
	int number=0;
	while(test)
	{
		cout<<"Please enter a student's name, or 'none' to quit\n";
		cin>>new_name;
		if(new_name.compare("none")!=0)
		{
			cout<<"Please enter the score\n"<<endl;
			cin>>new_score;
			*(name+number)=new_name;
			*(score+number)=new_score;					
			number++;	
		}
		else
		{
			test=false;
		}
	
	}
	

	double mean = 0.0;
	double std = 0.0;
	
//	cout<<"NUM "<<number;
	double sum=0.0;
	for (int i=0;i<number;i++)
	{
		sum+=score[i];
	}
//	cout<<"SUM "<<sum;
	mean=sum/(double)number;
//	cout<<"MEAN "<<mean<<endl;
	double temp=0.0;
	for (int i=0;i<number;i++)
	{
		temp+= (score[i]-mean)*(score[i]-mean);
	}
	std=sqrt(temp/number);
	cout<<"STD "<<std<<endl;

	double c=mean-0.5*std;
	double b=c+std;
	double a=b+std;
	double d=c-std;
	double f=d-std;
	cout.precision(1);
	cout<<"Grading scale\n";
	if (a>100)
	{
	cout<<"A above 100%\n";
	}
	else
	{
	cout<<"A above "<<fixed<<a<<"%\n";	
	}	
	cout<<"B "<<fixed<<b<<"%-"<<a<<"%\n";
	cout<<"C "<<c<<"%-"<<b<<"%\n";
	cout<<"D "<<d<<"%-"<<c<<"%\n";
	cout<<"F "<<f<<"%-"<<d<<"%\n";

	cout<<"Name   Score   Grade\n";
	for (int i=0;i<number;i++)
	{
		cout<<i+1<<". "<<name[i]<<"   "<<score[i]<<"%   ";
		if(score[i]>=a){cout<<"A\n";}
		else if(score[i]>=b){cout<<"B\n";}
		else if(score[i]>=c){cout<<"C\n";}
		else if(score[i]>=d){cout<<"D\n";}
		else{ cout<<"F\n";}
		
	}
	cout.precision(2);
	cout<<"Class average= "<<fixed<<mean<<"%\n";
	cout<<"Standard Deviation "<<std<<endl;
	return 0;
}
