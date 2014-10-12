#include <iostream>
#include <fstream>
#include <string.h>
#include <math.h>
using namespace std;

int main()
{
	double * score=NULL;
	score=new double[10];
	string * name=NULL;
	name = new string[10];
	string new_name;
	double new_score;
	bool test= true;
	int i=0;
	while(test)
	{
		cout<<"Please enter a student's name, or 'none' to quit\n";
		cin>>new_name;
		if(new_name.compare("none")!=0)
		{
			cout<<"Please enter the score\n"<<endl;
			cin>>new_score;
			*(name+i)=new_name;
			*(score+i)=new_score;					
			i++;		
		}
		else
		{
			test=false;
		}
	
	}
	

	double mean = 0.0;
	double std = 0.0;
	int number = sizeof(name)-1;
	cout<<"NUM "<<number;
	double sum=0.0;
	for (int i=0;i<number;i++)
	{
		sum+=score[i];
	}
	cout<<"SUM "<<sum;
	mean=sum/(double)number;
	cout<<"MEAN "<<mean<<endl;
	double temp=0.0;
	for (int i=0;i<number;i++)
	{
		temp+= (score[i]-mean)*(score[i]-mean);
	}
	std=sqrt(temp/number);
	cout<<"STD "<<std<<endl;
	
	
}
