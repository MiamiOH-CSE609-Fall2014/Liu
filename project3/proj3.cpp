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
void coutMatrix2(vector< vector<int> > );
vector< vector<int> > parseScoringFile(string);
pair<int,int> scoreSequence(string,string, vector<vector<int>>);
tuple<int,int,string> findHighScore(string,vector<string>,vector<vector<int>>);

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


void coutMatrix(vector<vector<int>> matrix)
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
void coutMatrix2(vector<vector<int>> matrix)
{	
   for(vector<int> temp : matrix)
     {
     for (int i : temp)
     {
        cout<<i<<" ";
     }
   cout<<"\n";          
     }
	cout<<endl;
}
vector<vector<int>> parseScoringFile(string fileName){
  fstream input;
  input.open(fileName, fstream::in);
  vector<vector<int>> score_matrix ;
  vector<int> row;
  char buf[500];
  while (input.getline(buf,500,','))
    {
      row.push_back(stoi(buf));

      input.getline(buf,500,',');
      row.push_back(stoi(buf));

      input.getline(buf,500,',');
      row.push_back(stoi(buf));

      input.getline(buf,500);
      row.push_back(stoi(buf));

      score_matrix.push_back(row);
      row.clear();

    }
	input.close();
  return score_matrix;
}
pair<int,int> scoreSequence(string haystack,string needle, vector<vector<int>> scoring_m){
  pair<int,int> max_score={0,0};int tempScore=0;int tempTotalScore=0;
  map<char,int> AGCTmap={{'A',0},{'G',1},{'C',2},{'T',3}};
  string hayPart;
  int end = haystack.length()-needle.length();
  for (int i=0;i<end+1;i++)
  {
    tempTotalScore=0;
    tempScore = 0;
    hayPart=haystack.substr(i,needle.length());
    for (int i=0;i<needle.length();i++)
    {
	tempScore=scoring_m[AGCTmap[hayPart[i]]][AGCTmap[needle[i]]];
	tempTotalScore+=tempScore;
    }
    if(tempTotalScore>=max_score.second)
    {
      max_score.first=i;
      max_score.second=tempTotalScore;
    }
  }
    return max_score;
}
tuple<int,int,string> findHighScore(string haystack,vector<string> needle,vector<vector<int>> scoring_m){
    tuple<int,int,string> high_scorer;
    pair<int,int> score;
    for(int i=0;i<needle.size();i++)
    {
      score=scoreSequence(haystack,needle[i],scoring_m);
      if (score.second>get<1>(high_scorer))
      {
       get<0>(high_scorer)=score.first;
       get<1>(high_scorer)=score.second;
       get<2>(high_scorer)= needle[i];
      }
    }
    score.first=0;
    score.second=0;
    return high_scorer;
  }
///////////////////////////////////////////////////////////////////////////////
int main(int argc, char** argv)
{
  string fileName;
  fileName = argv[1];
  tuple<string,vector<string>,string> DNA= parseFastaFile(fileName); 
  coutMatrix(digramFreqMatrix(digramFreqScores(get<2>(DNA))));
	
  string scoring_path;
  scoring_path= argv[2];
  vector<vector<int>> score_matrix;
  score_matrix=parseScoringFile(scoring_path);
  coutMatrix(score_matrix);

 cout<<"How many sequences would you like to score? "<<endl;
 int num_seq=0;
 cin>>num_seq;
 string oneSeq;
 vector<string> seqs;
 for(int i=0;i<num_seq;i++){
   cout<<"Please enter the sequence "<<i+1<<endl;
   cin>>oneSeq;
   seqs.push_back(oneSeq);
   oneSeq="";
 }
/*vector<tuple<int,int,string>> high_scorers;

for (int i=0;i<num_seq;i++)
{
 tuple<int,int,string>high_scorer;
 high_scorer=findHighScore(get<2>(DNA),seqs,score_matrix);
 high_scorers.push_back(high_scorer);
}
 
for (int i=0;i<num_seq;i++)
{
  cout<<"sequence\n";
  cout<<get<2>(high_scorers[i])<<"\n";
  cout<<"Score: "<<get<1>(high_scorers[i])<<" at position "<<get<0>(high_scorers[i])<<"\n";
  cout<<"\n";
}*/
  tuple<int,int,string>high_scorer;
  high_scorer=findHighScore(get<2>(DNA),seqs,score_matrix);
  cout<<"sequence\n";
  cout<<get<2>(high_scorer)<<"\n";
  cout<<"\nScore: "<<get<1>(high_scorer)<<" at position "<<get<0>(high_scorer)<<"\n";
  cout<<"The needle which produces the maximum score: "<<get<2>(high_scorer);
  cout<<"\n";


 return 0;
}
