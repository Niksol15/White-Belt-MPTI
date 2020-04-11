#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

void mySort(pair<string, string>& p){
    if(p.first > p.second)
        swap(p.first, p.second);
}

int main(){
    int q;
    cin >> q;
    string command, s1, s2;
    set<pair<string, string>> vocabulary;
    map<string, int> numberOfEntries;
    for(; q > 0; q--){
        cin >> command;
        if(command == "ADD"){
            cin >> s1 >> s2;
            pair<string, string> temp = {s1, s2};
            mySort(temp);
            if(!vocabulary.count(temp)){
                ++numberOfEntries[s1];
                ++numberOfEntries[s2];
                vocabulary.insert(temp);
            }
        }
        else if (command == "COUNT"){
            string key;
            cin >> key;
            cout << numberOfEntries[key] << endl;
        }
        else{
            cin >> s1 >> s2;
            pair<string, string> temp = {s1, s2};
            mySort(temp);
            if(vocabulary.count(temp))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}
