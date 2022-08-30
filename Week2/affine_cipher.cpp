#include<bits/stdc++.h>
using namespace std;

string encrypt(string str,int a,int b) {
	string cipher;
	char temp;
	for (int i = 0; i < str.size(); ++i)
	{
		temp = ((a * (str[i] - 'a')) + b ) % 26;
		cipher.push_back(temp + 'a');
	}
	return cipher;

}

int getMulInverse(int a) {
	int a_inv;
	for (int i = 0; i < 26; ++i)
	{
		a_inv = (a * i) % 26;

		if(a_inv == 1) {
			a_inv = i;
			return a_inv;
		}
	}
	return 0;
}

string decrypt(string str,int a, int b) {
	string plain;
	char temp;
	int inv = getMulInverse(a);
	for (int i = 0; i < str.size(); ++i)
	{
		temp = ((inv * (str[i] - 'a' - b + 26)) % 26 );
		plain.push_back(temp + 'a');
	}
	return plain;
}

int main()
{
	string str;
	cin>>str;

	int a,b;
	cin>>a>>b;

	int mod = 26;

	if(__gcd(a,mod) != 1) {
		cout<<"Enter a valid 'a' value.\n";
		return 0;
	}

	str = encrypt(str,a,b);

	cout<<str<<endl;

	str = decrypt(str,a,b);

	cout<<str<<endl;



}