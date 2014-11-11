#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <tuple>
#include <map>
#include <list>
#include <iterator>
//#include <stdlib.h>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

//Headers
tuple<string,vector<string>,string> parseFastaFile(string);
map<string, int> digramFreqScores(string);
vector<vector<int>> digramFreqMatrix(map<string,int>);
void coutMatrix(vector< vector<int> > );

//Functions
tuple<string, vector<string>, string> parseFastaFile(string fileName)
{
	fstream input;
	input.open(fileName, fstream::in);

	string header;
	vector<string> comments;
	string sequence;

	char temp[500];
	while (input.getline(temp, 500))
	{
		if (temp[0] == '>'){
			header = temp;
		}
		else if (temp[0] == ';'){
			comments.push_back(temp);
		}
		else {
			sequence += temp;
		}

	}
	tuple<string, vector<string>, string> DNAdata{ header, comments, sequence };
	input.close();
	return DNAdata;
}

map<string,int> digramFreqScores(string s){
  map<string,int> map1=
 {
    {"AA",0},{"AC",0},{"GT",0},
    {"AG",0},{"CC",0},{"CA",0},
    {"CG",0},{"TT",0},{"GG",0},
    {"GC",0},{"AT",0},{"GA",0},
    {"TG",0},{"TA",0},{"TC",0},
    {"CT",0}
  };
  for (int i=1;i<s.size();i++)
    {
	++map1[s.substr(i-1,2)];
    }
  return map1;
}

vector< vector<int> > digramFreqMatrix(map<string, int> map1){
  vector< vector<int> > matrix;
  vector<int> A,G,C,T;
//forming each rows
  A.push_back(map1["AA"]);
  A.push_back(map1["AG"]);
  A.push_back(map1["AC"]);
  A.push_back(map1["AT"]);
  G.push_back(map1["GA"]);
  G.push_back(map1["GG"]);
  G.push_back(map1["GC"]);
  G.push_back(map1["GT"]);
  C.push_back(map1["CA"]);
  C.push_back(map1["CG"]);
  C.push_back(map1["CC"]);
  C.push_back(map1["CT"]);
  T.push_back(map1["TA"]);
  T.push_back(map1["TG"]);
  T.push_back(map1["TC"]);
  T.push_back(map1["TT"]);
//forming big matrix
  matrix.push_back(A);
  matrix.push_back(G);
  matrix.push_back(C);
  matrix.push_back(T);
  return matrix;
}


void coutMatrix(vector< vector<int> > matrix)
{
    cout<<"  A  G  C  T"<<"\n";
	int k=1;	
for(int i = 0; i < 4; i++)
     {  
	if(k==1)cout<<"A ";
	if(k==2)cout<<"G ";
	if(k==3)cout<<"C ";
	if(k==4)cout<<"T ";
        for(int j = 0; j < 4; j++)
	{
	 cout<<matrix[i][j]<<" ";

	}
	cout<<"\n";
	k++;
     }
           
}
///////////////////////////////////////////////////////////////////////////////
int main(int argc, char** argv)
{
  string fileName;
  fileName = argv[1];
  tuple<string,vector<string>,string> DNA= parseFastaFile(fileName); 
  coutMatrix(digramFreqMatrix(digramFreqScores(get<2>(DNA))));

  return 0;
}
