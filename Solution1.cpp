#include<bits/stdc++.h>
using namespace std;
#define ll long long 
void recursive_cal(int i, string s, vector< vector<char> > v)
{
    if (i >= (int) v.size()) {
        cout << s << ", ";
        return;
    }
 	vector<char>::iterator it;
   for (it=v[i].begin();it!=v[i].end();it++) {
        s.push_back(*it);
        recursive_cal(i + 1, s, v);
        s.pop_back();
    }
}
 

int main(){


	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
 	vector< vector<char> >v;
 	string line,word;
   	fstream fin, fout; 
 	fin.open("in.csv", ios::in); //Reading the input.csv file 

   	    //reading every line by line
 	
   	 	while( getline(fin, line)){
  	 	        stringstream s(line); 
  	 	        //reading specefic line
  	 	        vector<char>temp;
  	 	        int i=0;
         while (getline(s, word, ',')) { //cout<<word[2]<<" "<<word.size()<<endl;
     			   if(i==0){temp.push_back(word[1]);i=1;} //only string allowed
     			   else {temp.push_back(word[2]);}
     			}
  	v.push_back(temp);
  	}
  	
  	//for(int i=0;i<temp.size();i++)cout<<temp[i]<<" ";
  	//	cout<<endl;
  	//}

   recursive_cal(0, "", v);

    return 0;
}