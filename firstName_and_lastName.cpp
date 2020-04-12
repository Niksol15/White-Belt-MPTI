#include <string>
#include <map>
#include <iostream>
using namespace std;

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        firstName[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        lastName[year] = last_name;
    }
    string GetFullName(int year) {
        string first_name = actualFirstName(year);
        string last_name = actualLastName(year);
        if(first_name == "Incognito" && last_name =="Incognito"){
            return "Incognito";
        }
        else if (first_name == "Incognito"){
            return (last_name + " with unknown first name");
        }
        else if (last_name == "Incognito"){
            return (first_name + " with unknown last name");
        }
        else{
            return (first_name + " " + last_name);
        }
    }
private:
    string actualFirstName(int year){
        if(firstName.empty()){
            return "Incognito";
        }
        else if((firstName.begin() -> first) > year){
            return "Incognito";
        }
        else
            return ((--firstName.upper_bound(year))->second);
    }
    string actualLastName(int year){
        if(lastName.empty()){
            return "Incognito";
        }
        else if((lastName.begin() -> first) > year){
            return "Incognito";
        }
        else
            return ((--lastName.upper_bound(year))->second);
    }
    map<int, string> lastName;
    map<int, string> firstName;
};
