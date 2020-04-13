#include <string>
#include <map>
#include <deque>
using namespace std;

class Person {
public:
    void ChangeFirstName(int year, const string& first_name){
        if(firstName.count(year)){
           firstName.erase(year);
        }
        firstName[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        if(lastName.count(year)){
            lastName.erase(year);
        }
        lastName[year] = last_name;
    }
    string GetFullName(int year) {
        string first_name;
        if(getActualFirstNameRecord(year) == firstName.end()){
            first_name = "Incognito";
        }
        else{
            first_name = getActualFirstNameRecord(year)->second;
        }
        string last_name;
        if(getActualLastNameRecord(year) == lastName.end()){
            last_name = "Incognito";
        }
        else{
            last_name = getActualLastNameRecord(year) ->second;
        }
        if(first_name == "Incognito" && last_name =="Incognito"){
            return "Incognito";
        }
        else if (first_name == "Incognito"){
            return last_name + " with unknown first name";
        }
        else if (last_name == "Incognito"){
            return first_name + " with unknown last name";
        }
        else{
            return first_name + " " + last_name;
        }
    }
    string GetFullNameWithHistory(int year) {
        string first_name_history = getFirstNameHistory(year);
        string last_name_history = getLastNameHistory(year);
        string res;
        if(getActualFirstNameRecord(year) == firstName.end()
            && getActualLastNameRecord(year) == lastName.end()){
            return  "Incognito";
        }
        else if(getActualFirstNameRecord(year) == firstName.end()){
            res += getActualLastNameRecord(year) -> second;
            res += last_name_history;
            res += " with unknown first name";
            return res;
        }
        else if(getActualLastNameRecord(year) == lastName.end()) {
            res += getActualFirstNameRecord(year)->second;
            res += first_name_history;
            res += " with unknown last name";
            return res;
        }
        else{
            res += getActualFirstNameRecord(year) -> second;
            res += first_name_history + " ";
            res += getActualLastNameRecord(year) -> second;
            res += last_name_history;
        }
        return res;
    }
private:
    map<int, string>::iterator getActualFirstNameRecord(int year){
        if(firstName.empty()){
            return firstName.end();
        }
        else if((firstName.begin() -> first) > year){
            return firstName.end();
        }
        else
            return --(firstName.upper_bound(year));
    }
    map<int, string>::iterator getActualLastNameRecord(int year){
        if(lastName.empty()){
            return lastName.end();
        }
        else if((lastName.begin() -> first) > year){
            return lastName.end();;
        }
        else
            return --(lastName.upper_bound(year));
    }
    string getFirstNameHistory(int year){
        deque<string> first_name_history;
        if(getActualFirstNameRecord(year) != firstName.end()) {
            auto it_first_name = firstName.begin();;
            while (it_first_name != getActualFirstNameRecord(year) && it_first_name != firstName.end()){
                if (it_first_name->second != first_name_history.front())
                    first_name_history.push_front(it_first_name->second);
                ++it_first_name;
            }
            if(first_name_history.front() == getActualFirstNameRecord(year) -> second){
                first_name_history.pop_front();
            }
        }
        string res;
        if(!first_name_history.empty()){
            if(first_name_history.size() > 1){
                res += " (";
                for(const auto& fn: first_name_history)
                    res += fn + ", ";
                res.pop_back();
                res.back() = ')';
            }
            else
                return " (" + first_name_history.front() + ")";
        }
        return res;
    }
    string getLastNameHistory(int year){
        deque<string> last_name_history;
        if(getActualLastNameRecord(year) != lastName.end()) {
            auto it_last_name = lastName.begin();
            while (it_last_name != getActualLastNameRecord(year) && it_last_name != lastName.end()){
                if (it_last_name->second != last_name_history.front())
                    last_name_history.push_front(it_last_name->second);
                ++it_last_name;
            }
            if(last_name_history.front() == getActualLastNameRecord(year) -> second){
                last_name_history.pop_front();
            }
        }
        string res ;
        if(!last_name_history.empty()){
            if(last_name_history.size() > 1){
                res += " (";
                for(const auto& fn: last_name_history)
                    res += fn + ", ";
                res.pop_back();
                res.back() = ')';
            }
            else
                return " (" + last_name_history.front() + ")";
        }
        return res;
    }
    map<int, string> lastName;
    map<int, string> firstName;
};
