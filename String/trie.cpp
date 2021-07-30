/* ref: http://www.shafaetsplanet.com/?p=1679
 *
 */

#include <bits/stdc++.h>
using namespace std;

struct Node {
    bool endmark;
    Node *next[26];
    Node() {
        endmark = false;
        for(int i = 0; i < 26; i++) {
            next[i] = NULL;
        }
    }
} *Root;

void insert(string s) {
    Node *cur = Root;
    for(int i = 0; i < s.size(); i++) {
        int id = s[i] - 'a';
        if(cur->next[id] == NULL) {
            cur->next[id] = new Node();
        }
        cur = cur->next[id];
    }
    cur->endmark = true;
}

bool search(string s) {
    Node *cur = Root;
    for(int i = 0; i < s.size(); i++) {
        int id = s[i] - 'a';
        if(cur->next[id] == NULL) return false;
        else cur = cur->next[id];
    }
    return cur->endmark;
}

void del(Node *cur) {
    for(int i = 0; i < 26; i++) {
        if(cur->next[i]) {
            del(cur->next[i]);
        }
    }
    delete(cur);
}


int main() {
    Root = new Node();
    int n, q; cin >> n >> q;
    string s;
    while(n--) {
        cin >> s;
        insert(s);
    }
    while(q--) {
        cin >> s;
        cout << s;
        if(!search(s)) cout << " not";
        cout << " found!\n";
    }
    delete(Root);
}
