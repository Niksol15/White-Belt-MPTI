#include <iostream>
#include <vector>
#include <string>
using namespace std;
int mySize(const string& s){
    int size = 0;
    for(auto ch: s)
        if(ch == ' ')
            size++;
    return size;
}

int main(){
    int q;
    cin >> q;
    const vector<int> year = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31};
    vector<string> month(year[0]);
    string command, doing;
    int index, currentMonth = 0;
    for(; q > 0; q--){
        cin >> command;
        if(command == "ADD"){
            cin >> index;
            --index;
            cin >> doing;
            month[index] += doing + " ";
        }
        else if(command == "DUMP"){
            cin >> index;
            --index;
            cout << mySize(month[index]) << " ";
            cout << month[index] << endl;
        }
        else if(command == "NEXT"){
            if(year[currentMonth] < year[currentMonth + 1])
                month.resize(year[currentMonth + 1]);
            else{
                while(month.size() != year[currentMonth + 1]){
                    month[month.size() - 2] += month.back();
                    month.pop_back();
                }
            }
            currentMonth = (currentMonth + 1) % 12;
        }
    }
    return 0;
}
