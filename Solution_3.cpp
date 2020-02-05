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


// Returns 0 if current node has a child 
// If all children are NULL, return 1. 
bool isLastNode(trie* root) 
{ 
	for (int i = 0; i < alpha; i++) 
		if (root->children[i]) 
			return 0; 
	return 1; 
}


//suggestions
void booblesugg(trie* root, string curr,std::vector<string>& output) 
{ 
	// found a string in Tree with the given prefix 
	if (root->is_leaf) 
	{ 
		if(output.size()==5)return;//only 5 word sugesstion
		output.push_back(curr);
	} 

	// All children struct node pointers are NULL 
	if (isLastNode(root)) 
		return; 

	for (int i = 0; i < alpha; i++) 
	{ 
		if (root->children[i]) 
		{ 
			// append current character to currPrefix string 
			curr.push_back(97 + i); 

			// recur over the rest 
			booblesugg(root->children[i], curr,output);
			
			// remove last character 
			curr.pop_back(); 
		} 
	} 
} 


// print suggestions for given query string 
int print(trie* root, const string q) 
{ 
	trie* curr = root; 

	
	int level; 
	int n = q.length(); 
	for (level = 0; level < n; level++) 
	{ 
		int index = q[level]-'a'; 

		// no string in the Tree 
		if (!curr->children[index]) 
			return 0; 

		curr=curr->children[index]; 
	} 

	// If prefix is present as a word. 
	bool is_leaf = (curr->is_leaf == true); 

	bool isLast = isLastNode(curr); 
	if (is_leaf && isLast) 
	{ 
		cout << q << endl; 
    // no string found
		return -1; 
	} 

	// If there are are nodes below 
	std::vector<string> output;
	//output.push_back("-1"); //storing all output strings
	if (!isLast) 
	{ 
		string prefix = q; 
		booblesugg(curr, prefix,output); 
		 
	} 
	
	while(output.size()<5){
		output.push_back(q);
	}
	//cout<<output.size();
		//printing the string array

	for(int i=0;i<5;i++){
		cout<<output[i]<<endl;
	}
} 



// Main Driver Code 
int main() 
{ 
	trie* root = new_node(); 
	
	

	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    
    fstream fin, fout; 
 	fin.open("input.csv", ios::in); //Reading the input.csv file 

  	vector<string>v; //storing the string input from input.csv
  	
   	 string line,word;
   	 
   	    //reading every line by line
   	 	while( getline(fin, line)){
  	 	        stringstream s(line); 
  	 	        //reading specefic line
         while (getline(s, word, ',')) { 
     			   if(isdigit(word[0])==false)v.push_back(word); //only string allowed

  	}
  	}
  	for(int i=0;i<v.size();i++)insert(root,v[i]);//inserting 
  
  		//string to find
  		string string_to_find;
  		cin>>string_to_find;
  		
  		
  		//printing all suggestions
        print(root,string_to_find);
        
        
	return 0; 
} 
