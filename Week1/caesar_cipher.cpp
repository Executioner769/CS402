#include<bits/stdc++.h>
using namespace std;

// Enter the plain text in lowercase Only
string toLowerCase(string plain)
{
	string modified;
    int i;
    for (i = 0; i < plain.size(); i++) {
        if (plain[i] > 64 && plain[i] < 91)
            modified.push_back(plain[i] + 32);
    }
    return modified;
}

// Convert Message to Cipher Text
string encrypt(string s,int key) {
	string cipher;
	char temp;
	for(int i = 0; i < s.size(); i++) {
		temp = (((s[i] - 97) + key) % 26 ) + 65;
		cipher.push_back(temp);
	}
	return cipher;
}


// Concert Cipher text to Message
string decrypt(string s,int key) {
	string msg;
	char temp;
	for(int i = 0; i < s.size(); i++) {
		temp = abs((((s[i] - 65) - key + 26) % 26 )) + 97;
		msg.push_back(temp);
	}
	return msg;
}

// Brute Force attack to find the Message text
void attack(string s) {
	for (int k = 0; k < 26; ++k)
	{
		string str;
		char temp;
		for(int i = 0; i < s.size(); i++) {
			temp = abs((((s[i] - 65) - k + 26) % 26 )) + 97;
			str.push_back(temp);
		}
		cout<<k+1<<" "<<str<<endl;
	}
}

int main() {
	string str;
	int key;
	cin>>key;

	cin>>str;

	str = toLowerCase(str);

	string str2;
	str2 = encrypt(str,key);

	cout<<"Cipher Text: "<<str2<<endl;

	str2 = decrypt(str2,key);

	cout<<"Message: "<<str2<<endl;

	// cout<<str2<<endl;

	cout<<"Brute Force Attack: "<<endl;
	attack(str);

	return 0;
}