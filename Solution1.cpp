#include<bits/stdc++.h>
using namespace std;
#define ll long long 

//recursive function to calculate all permutation
void recursive_cal(int i, string s, vector< vector<char> > v)
{
    if (i >= (int) v.size()) {
        cout << s << ", ";
        return;
    }
 	
   for (char c:v[i]) {
        s.push_back(c);
        recursive_cal(i + 1, s, v);
        s.pop_back();
    }
}
 

int main(){


	ios_base::sync_with_stdio(false);
	
    cin.tie(0);

	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

 	vector< vector<char> >v// storing dynamic array

  	string line,word;


  	fstream fin, fout; 
 	fin.open("input.csv", ios::in); //Reading the input.csv file 

  	    //reading every line by line
 	
  	while(getline(fin, line)){
  	 	        stringstream s(line); 
  	 	        
  	 	        vector<char>temp; // will contains all character of first line of csv file
  		        
  		        int i=0;
        		while (getline(s, word, ',')) { 

     			   	if(i==0){temp.push_back(word[1]);i=1;} //if first word of line  then store 2nd character

     			   	else {temp.push_back(word[2]);} //else store 3rd character

     			}
  				v.push_back(temp);
  	}
  	
  	

  	//recursive solution to printing all permutation
   recursive_cal(0, "", v);

   return 0;
}
