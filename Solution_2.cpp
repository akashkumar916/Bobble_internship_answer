#include<bits/stdc++.h>
using namespace std;
#define ll long long 

//Number of alphabet
const int alpha=26;

//Structure for my tree 
struct trie{
	trie* children[alpha];
	bool is_leaf;
};

//Making the new node 
trie* new_node(){
	trie* temp=new trie();
	for(int i=0;i<alpha;i++){
		temp->children[i]=NULL;
	}
	temp->is_leaf=false;
}

//Inserting each character of string in a tree
void insert(trie*  root,string m){
	trie* temp=root;
	for(int i=0;i<m.size();i++){
		int index=m[i]-'a';
		if(!temp->children[index]){
			temp->children[index]=new trie();
		}
		temp=temp->children[index];
	}
	temp->is_leaf=true;
}

//Traversing the tree
void traverse(trie* root,string s,vector<string>&ouput){

	if(root->is_leaf==true){
		
		//s[index]='\0';
		ouput.push_back(s);
	}
	for(int i=0;i<alpha;i++){
		if(root->children[i]){
			s.push_back(i+'a');		
		traverse(root->children[i],s,ouput);}

	}
}

//creating the tree through this function
vector<string> create(vector<string>&v){

	trie* root=new_node();
	for(int i=0;i<v.size();i++){
		insert(root,v[i]);
	}
	vector<string>ouput;
	string s;
	traverse(root,s,ouput);
	sort(v.begin(),v.end());
	ouput=v;
	return v;
}

//traversing the tree this function
void load(vector<string>&v){
	vector<string>output=create(v);
	for(int i=0;output.size();i++){
		cout<<output[i]<<endl;
	}
	
}
//Main Driven function
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	fstream fin, fout; 
  	fin.open("input.csv", ios::in); //Reading the input.csv file 

 
  	vector<string>output;  //storing the ouput string 

  	cout<<"1. create"<<endl<<"2. load"<<endl;
  	int choice;

  	vector<string>v; //stroing the string input from input.csv
  	string line,word;
  	while( getline(fin, line)){
  			        stringstream s(line); 
  			        while (getline(s, word, ',')) { 
  			   			v.push_back(word); 
        											}

  								}
  	cin>>choice;
  	if(choice==1){
  		
  		//Creating the character tree
  			output=create(v); 

  			//storing the output string in output.csv
  	
			fout.open("output.csv",ios::out);//output.csv file

			for(int i=0;i<output.size();i++){
				fout<<output[i]<<", "; //every string into ouput
			}
  				
  	}
  	
  	else {
			// loading and recreate the tree and print it.  		
  		load(v);
  		}







	return 0;
}