#include<bits/stdc++.h>
using namespace std;
vector<int> ans(string s,string c){
	vector<int> v;
	int a;
	int aa=((c[0]-'A')-(c[1]-'A'));
	int aaa=((s[0]-'A'))-((s[1]-'A'));
	int k= aa/aaa;
	while(k<0){
		k+=26;
	}
	while(k>25){
		k-=26;
	}
	//cout<<k<<endl;
	int b=(c[0]-'A')-(k*(s[0]-'A'));
	//cout<<b<<endl;
	while(b<0){
		b+=26;
	}
	while(b>25)b-=26;
	v.push_back(k);
	v.push_back(b);
	return v;
}
int main(){
	string s,c;
	cin>>s>>c;
	vector<int> v=ans(s,c);
	for(int i=0;i<2;i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
	return 0;
}