#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <map>
#include "parseFastaFile.h"

using namespace std;


int main(int argc, char** argv)
{
  string filename = argv[1];
  tuple<string,vector<string>,string> DNAdata= parseFastaFile(filename);
  cout<<endl;  
cout<<"The whole file contents are :"<<endl;
 cout<<endl;  
string hd = get<0>(DNAdata);
  string sq = get<2>(DNAdata);
  cout<<hd<<endl;
  for (int i=0; i<get<1>(DNAdata).size();i++){
    cout<<get<1>(DNAdata)[i]<<endl;
  }
  cout<<sq<<endl;




 return 0;
}