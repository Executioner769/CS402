#include<bits/stdc++.h>
using namespace std;

map<char,vector<char>> mp;

string encrypt(string str, string key) {

	for (int i = 0; i < str.size(); ++i)
	{
		char t2 = str[i];
		mp[key[i % key.size()]].push_back(t2);
	}

	int rem = str.size() % key.size();

	if(rem != 0) {
		while(rem < key.size()) {
			mp[key[rem]].push_back('_');
			rem++;
		}
	}

	char temp;
	string cipher;
	for(auto it = mp.begin(); it != mp.end(); it++) {
		for(int i = 0; i < it->second.size(); i++) {
			temp = it->second[i];
			cipher.push_back(temp);
		}
	}
	return cipher;
}

string decrypt(string str,string key) {
	string plain;
	int sz = str.size() / key.size();
	for(int i = 0; i < sz; i++) {
		for(int j = 0; j < key.size(); j++) {
			if(mp[key[j]][i] == '_') continue;
			plain.push_back(mp[key[j]][i]);
		}
	}
	return plain;
}

int main() {
	string str;
	getline(cin,str);
	
	string key;
	cin>>key;
	string cipher;
	cipher = encrypt(str,key);
	cout<<cipher<<endl;

	string plain;
	plain = decrypt(cipher,key);
	cout<<plain<<endl;

}
