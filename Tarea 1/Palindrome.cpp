#include <iostream>
#include <string>
//Jose Manuel Beauregard Mendez A01021716
using namespace std;

bool test_palindrome(string word, int f, int i)
{
	if(i>f) 
		return true;
	else if(word[i] == word[f]) 
		test_palindrome(word,f-1,i+1);
		return true;
	else if(word[i] != word[f]) 
		return false;
}

int main()
{
	string word;
	cout<< "Type a word" << endl;
	cin>>word;
	int length = word.length();
	if (test_palindrome(word,length, 0)) 
		cout << word <<" is a palindrome."<<endl;
	else 
		cout << word << " is not a palindrome" << endl;
	return 0;
}