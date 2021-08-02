// knuth morris pratt string matching algorithm
// link: https://youtu.be/sMARZCTPyNI
// https://gist.github.com/dipta10/4658935c9f119fb7db966ba467c8dd7f
//colab between labib and faisal
#include <bits/stdc++.h>
using namespace std;
/*
void kmp(string &text,string &pattern){
	
	int n=pattern.length(),l=text.length(),i=0,j,lps[n];
	lps[0]=0;
	for(j=1;j<n;){
		if(pattern[i]==pattern[j]) lps[j]=i+1,i++,j++;
		else {
			if(i) i=lps[i-1];
			else lps[j]=0,j++;
		}
	}

	i=0,j=0;
	while(i<n){
		if(pattern[j]==text[i])
			i++,j++;
		else {
			if(j) j=lps[j-1];
			else i++;
		}
	}
}


*/
vector<int> lpsGen(string pattern) {
    int len = pattern.size();
    vector<int> lps(len);
    int index = 0, i = 1;
    while(i < len) {
        if(pattern[index] == pattern[i]) {
            lps[i] = index+1;
            index++, i++;
        } else {
            if(index != 0) index = lps[index-1];
            else lps[i] = index, i++;
        }
    }

    return lps;
}

void kmp(string text, string pattern) {
    bool found = false;
    vector<int> lps = lpsGen(pattern);
    int i = 0, j = 0;
    // i -> text
    // j -> pattern
    int text_len = text.size(), pattern_len = pattern.size();
    while(i < text_len) {
        if(text[i] == pattern[j]) {
            i++;
            j++;
        } else {
            if(j != 0) j = lps[j-1];
            else i++;
        }

        if(j == pattern_len) {
            found = true;
            cout << "found\n";
            cout << "index : " << (i - pattern_len) << '\n';
            j = lps[j-1]; // search again
        }
    }

    if(!found) cout << "not found\n";
}

int main() {
    string pattern, text;
    cin >> text >> pattern;
    kmp(text, pattern);
}
