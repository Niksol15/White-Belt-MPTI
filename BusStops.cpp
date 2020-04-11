#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

string output;
int main(){
    int q;
    cin >> q;
    map<string, vector<string>> bus;
    map<string, vector<string>> stop;
    string command, busName, stopName;
    for(; q > 0; --q){
        cin >> command;
        if(command == "NEW_BUS"){
            cin >> busName;
            int stopCounter;
            cin >> stopCounter;
            for(int i = 0; i < stopCounter; ++i){
                cin >> stopName;
                bus[busName].push_back(stopName);
                stop[stopName].push_back(busName);
            }
        }
        else if(command == "BUSES_FOR_STOP"){
            cin >> stopName;
            if(stop.find(stopName) != stop.cend()){
                for(const string& busForStop: stop[stopName])
                    output += busForStop + " ";
                output += '\n';
            } else
                output += "No stop\n";
        }
        else if(command == "STOPS_FOR_BUS"){
            cin >> busName;
            if(bus.find(busName) != bus.cend()){
                for(const string& stopForBus: bus[busName]){
                    output += "Stop " + stopForBus + ":" ;
                        if (stop[stopForBus].size() != 1) {
                            for (const auto &currBusName: stop[stopForBus])
                                if (currBusName != busName)
                                    output += " " + currBusName;
                        } else
                            output += " no interchange";
                        output += "\n";
                }
            } else
                output += "No bus\n";
        }
        else{
            if(!bus.empty())
                for(const auto& currBus: bus){
                    output += "Bus " + currBus.first + ":";
                    for(const auto& currStop: currBus.second)
                        output += " " + currStop;
                    output += "\n";
                }
            else
                output += "No buses\n";
        }
    }
    cout << output;
    return 0;
}

/*int main(){
    int q;
    cin >> q;
    map<string, vector<string>> bus;
    map<string, vector<string>> stop;
    string command, busName, stopName;
    for(; q > 0; --q){
        cin >> command;
        if(command == "NEW_BUS"){
            cin >> busName;
            int stopCounter;
            cin >> stopCounter;
            for(int i = 0; i < stopCounter; ++i){
                cin >> stopName;
                bus[busName].push_back(stopName);
                stop[stopName].push_back(busName);
            }
        }
        else if(command == "BUSES_FOR_STOP"){
            cin >> stopName;
            if(!stop[stopName].empty()){
                for(const string& busForStop: stop[stopName])
                    cout << busForStop << " ";
                cout << endl;
            } else
                cout << "No stop" <<  endl;
        }
        else if(command == "STOPS_FOR_BUS"){
            cin >> busName;
            if(!bus[busName].empty()){
                for(const string& stopForBus: bus[busName]){
                    cout << "Stop " << stopForBus << ":" ;
                    if(!stop[stopForBus].empty()){
                        for(const auto& currBusName: stop[stopForBus])
                            cout << " " << currBusName;
                    }
                    else
                        cout << " no interchange";
                    cout << endl;
                }
            } else
                cout << "No bus" <<  endl;
        }
        else{
            if(!bus.empty())
                for(const auto& currBus: bus){
                    cout << "Bus " << currBus.first << ":";
                    for(const auto& currStop: currBus.second)
                        cout << " " << currStop;
                    cout << endl;
                }
            else
                cout << "No buses" << endl;
        }
    }
    return 0;
}*/