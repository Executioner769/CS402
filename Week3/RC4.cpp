
#include<bits/stdc++.h>
using namespace std;

vector<char>K(256),S(256);

void KSA(string key){
    int n = key.size();
    for (int i = 0; i < 256;i++){
        S[i] = i;
        K[i] = key[i % n];
    }
    int j = 0;
    for (int i = 0; i < 256;i++){
        j = (j + S[i] + K[i]) % 256;
        swap(S[i], S[j]);
    }
}

string encrypt(string&p){
    int i = 0, j = 0;
    string c="";
    for (int x = 0;x<p.size();x++){
        i=(i+1)%256;
        j=(j+S[i])%256;
        swap(S[i], S[j]);
        int t = (S[i] + S[j]) % 256;
        c.push_back(p[x] ^ S[t]);
    }
    return c;
}

int main(){
    string p = "yash";
    string key = "key";
    KSA(key);
    string cipher = encrypt(p);
    KSA(key);
    string plain = encrypt(cipher);
    cout << cipher << endl;
    cout << plain << endl;
    return 0;
}
