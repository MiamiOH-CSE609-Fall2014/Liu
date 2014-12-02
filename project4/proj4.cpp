#include<string.h>
#include <cstring> 
#include<stdio.h> 
#include<stdlib.h> 
#include<iostream>
using namespace std;

void encoding(string inFile,string outFile,char *pwd);
void decoding(string inFile,string outFile,char *pwd); 


int main()
{ 
	int c;
	string inFile;
	string outFile;
	char pwd[5];

	cout<<("1. Encrypt a file  2. Decrypt a file\n");	
	
	cin>>c;
	cout<<("Please input In-filename( .txt file):\n"); 
	cin>>inFile;
	cout<<("Please input your Password(4 digits number):\n"); 
	cin>>pwd;
	cout<<("Please input Out-filename( .txt file):\n"); 
	cin>>outFile;
		
	if(c==1)
	{
		cout<<"Encoding.....\nInput File Name: "<<inFile;
		cout<<"\nOutput File Name: "<<outFile;
		cout<<"\nPassword: "<<pwd<<endl;
		encoding(inFile,outFile,pwd);
		cout<<"Encoding Successfully"<<endl;
		
	}
	if(c==2)
	{
		cout<<"Decoding.....\nInput File Name: "<<inFile;
		cout<<"\nOutput File Name: "<<outFile;
		cout<<"\nPassword: "<<pwd<<endl;
		decoding(inFile,outFile,pwd);
  		cout<<"Decoding Successfully"<<endl;
		
	}

	return 0; 
} 



void encoding(string fName,string outfName,char *pwd) 
{ 
	FILE *input,*output; 
	char inFile[30];
	char out_file[30];
	strcpy(inFile, fName.c_str());
	strcpy(out_file, outfName.c_str());
	register char ch; 
	int i=0; 
	input=fopen(inFile,"r");
	if(input==NULL){ 
		cout<<("Error Input File Name\n"); 
		exit(1);
	} 
	output=fopen(out_file,"w"); 
	if(output==NULL){ 
		cout<<("Error Output File Name\n"); 
		exit(1);

	} 

	while(pwd[++i]);  

	ch=fgetc(input); 

	
	while(!feof(input)){ 
		if(i >3)
		i = 0;
		ch+=pwd[i++];
		fputc(ch,output); 
		ch=fgetc(input); 
	} 

} 


void decoding(string fName,string outfName,char *pwd) 
{ 
	char inFile[30];
	char outFile[30];
	FILE *input,*output;
	strcpy(inFile, fName.c_str());
	strcpy(outFile, outfName.c_str());
	register char ch; 
	int i=0; 
	input=fopen(inFile,"r");
	if(input==NULL){ 
		cout<<("Error Input File Name\n"); 
		exit(1);
	} 
	output=fopen(outFile,"w"); 
	if(output==NULL){ 
		cout<<("Error Output File Name\n"); 
		exit(1);
	} 
	
	while(pwd[++i]);  	
	ch=fgetc(input); 
	
	while(!feof(input)){ 
		if(i >3)
		i = 0;
		ch -= pwd[i++];
		fputc(ch,output);
		ch=fgetc(input); 
	} 

} 