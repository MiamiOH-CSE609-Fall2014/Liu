//CSE609 Project1 Yizhou Liu
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int ArowNum, BrowNum, AcolNum, BcolNum;
	cin>>ArowNum;
	cin>>AcolNum;
	cin>>BrowNum;
	cin>>BcolNum;
	if(AcolNum!=BrowNum)
	{
	cout<<"Invild Input\n";
	return 1;
	}
	cout<<"------"<<endl;
	int A[ArowNum][AcolNum];
	int B[BrowNum][BcolNum];
	int C[ArowNum][BcolNum];
	for (int i=0;i<ArowNum;i++)
	{
		for (int j=0;j<AcolNum;j++)
		{
			cin>>A[i][j];
		}
	}
	cout<<"-----"<<endl;

	for (int i=0;i<BrowNum;i++)
	{
		for (int j=0;j<BcolNum;j++)
		{
			cin>>B[i][j];
		}
	}

	cout<<"-----"<<endl;

	for (int i=0;i<ArowNum;i++)
	{
		for (int j=0;j<BcolNum;j++)
		{
			C[i][j]=0;
			for (int k=0;k<AcolNum;k++)
				{
					C[i][j]+=A[i][k]*B[k][j];
				}
		}
	}
	
	for (int i=0;i<ArowNum;i++)
	{
		for (int j=0;j<AcolNum;j++)
		{
			cout<<A[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"-----"<<endl;

	for (int i=0;i<BrowNum;i++)
	{
		for (int j=0;j<BcolNum;j++)
		{
			cout<<B[i][j]<<" ";
		}
		cout<<"\n";
	}

	cout<<"-----"<<endl;

	for (int i=0;i<ArowNum;i++)
	{
		for (int j=0;j<BcolNum;j++)
		{
			cout<<C[i][j]<<" ";
		}
		cout<<"\n";
	}
	


	return 0;
}
