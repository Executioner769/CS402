#include <bits/stdc++.h>
using namespace std;

// Enter plain text and key in Uppercase only

// Encrypt the text using Vigenere Cipher
string encrypt(string str,string key) {
	string modifiedKey;
	for(int i = 0; i < str.size(); i++) {
		modifiedKey.push_back(key[i%(key.size())]);
	}
	
	string cipher;
	for(int i = 0; i < str.size(); i++) {
		cipher.push_back(((modifiedKey[i] + str[i]) % 26 ) + 65);
	}
	return cipher;
}

// Decrypt the text using Vigenere Cipher
string decrypt(string str,string key) {
	string modifiedKey;
	for(int i = 0; i < str.size(); i++) {
		modifiedKey.push_back(key[i%(key.size())]);
	}
	
	string txt;
	for(int i = 0; i < str.size(); i++) {
		txt.push_back(((str[i] - modifiedKey[i] + 26) % 26 ) + 65);
	}
	return txt;
}


int main() {
	string msg;
	cin>>msg;

	string key;
	cin>>key;

	string res;
	res = encrypt(msg,key);

	cout<<"Cipher Text: "<<res<<endl;

	res = decrypt(res,key);

	cout<<"Plain Text: "<<res<<endl;

	return 0;
}