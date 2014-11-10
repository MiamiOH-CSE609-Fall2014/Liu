#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <map>
#include "parseFastaFile.h"

using namespace std;


int main(int argc, char** argv)
{
  string fileName = argv[1];
  tuple<string,vector<string>,string> DNA= parseFastaFile(fileName); 
  string header = get<0>(DNA);
  string sequence = get<2>(DNA);
  cout<<header<<endl;
  for (int i=0; i<get<1>(DNA).size();i++)
  {
    cout<<get<1>(DNA)[i]<<endl;
  }
  cout<<sequence<<endl;

  return 0;
}
