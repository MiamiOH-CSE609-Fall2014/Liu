#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
#include<iostream>
using namespace std;

void encfile(char *inFile,char *pwd,char *outFile);
void decryptfile(char *inFile,char *pwd,char *outFile); 

int main()
{ 
	int option;
	char inFile[30];
	char outFile[30]; 
	char pwd[8];

	cout<<("1. Encrypt a file  2. Decrypt a file\n");	
	
	cin>>option;
	cout<<("Please input In-filename:\n"); 
	cin>>inFile;
	cout<<("Please input your Password:\n"); 
	cin>>pwd;
	cout<<("Please input Out-filename:\n"); 
	cin>>outFile;
		
	switch(option){
	case 1: 
		cout<<"Input File Name: "<<inFile;
		cout<<"\nOutput File Name: "<<outFile;
		cout<<"\nPassword: "<<pwd<<endl;
		encfile(inFile,pwd,outFile);
		cout<<"Encrypting Successfully-Remember Your Password Please"<<endl;
		break;
	case 2:
		decryptfile(inFile,pwd,outFile);
		break;
	default:
		break;
	}	
	return 0; 
} 


void encfile(char *inFile,char *pwd,char *out_file) 
{ 
	FILE *fp1,*fp2; 
	register char ch; 
	int j=0; 
	fp1=fopen(inFile,"r");
	if(fp1==NULL){ 
		cout<<("Error Input\n"); 
		exit(1);
	} 
	fp2=fopen(out_file,"w"); 
	if(fp2==NULL){ 
		cout<<("Error Input\n"); 
		exit(1);
	} 

	while(pwd[++j]);  

	ch=fgetc(fp1); 

	
	while(!feof(fp1)){ 
		if(j >7)
		   j = 0;
		ch += pwd[j++];
		fputc(ch,fp2); 
		ch=fgetc(fp1); 
	} 
	fclose(fp1);
	fclose(fp2);
} 


void decryptfile(char *inFile,char *pwd,char *outFile) 
{ 
	FILE *fp1,*fp2; 
	register char ch; 
	int j=0; 
	fp1=fopen(inFile,"r");
	if(fp1==NULL){ 
		cout<<("Error Input\n"); 
		exit(1);
	} 
	fp2=fopen(outFile,"w"); 
	if(fp2==NULL){ 
		cout<<("Error Input\n"); 
		exit(1);
	} 
	
	while(pwd[++j]);  	
	ch=fgetc(fp1); 
	
	while(!feof(fp1)){ 
		if(j >7)
		   j = 0;
		ch -= pwd[j++];
		fputc(ch,fp2);
		ch=fgetc(fp1); 
	} 
	fclose(fp1);
	fclose(fp2);
} 