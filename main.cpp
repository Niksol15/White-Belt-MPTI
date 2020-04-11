#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
int main(){
    int q, numOfStops;
    cin >> q;
    string currStop;
    vector<string> currBus;
    map<vector<string>, int> buses;
    for(; q > 0; q--){
        currBus.clear();
        cin >> numOfStops;
        for(int i = 0; i < numOfStops; ++i){
            cin >> currStop;
            currBus.push_back(currStop);
        }
        if(buses.find(currBus) != buses.cend())
            cout << "Already exists for " << buses[currBus] << endl;
        else{
            cout << "New bus ";
            size_t tmp = buses.size() + 1;
            cout << tmp << endl;
            buses[currBus] = tmp;
        }
    }
    return 0;
}
