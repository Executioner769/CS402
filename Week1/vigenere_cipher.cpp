#include <bits/stdc++.h>
using namespace std;

string toUpperCase(string plain)
{
	string modified;
    int i;
    for (i = 0; i < plain.size(); i++) {
        if (plain[i] > 91 && plain[i] < 128)
            modified.push_back(plain[i] - 32);
    }
    return modified;
}

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

	msg = toUpperCase(msg);

	string key;
	cin>>key;

	key = toUpperCase(key);

	string res;
	res = encrypt(msg,key);

	cout<<"Cipher Text: "<<res<<endl;

	res = decrypt(res,key);

	cout<<"Plain Text: "<<res<<endl;

	return 0;
}