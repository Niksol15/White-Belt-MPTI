#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

std::string str_toupper(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c){ return std::toupper(c); });
    return s;
}

int main(){
    int n;
    cin >> n;
    vector<string> arr(n);
    for(auto& i: arr)
        cin >> i;
    sort(arr.begin(), arr.end(), [](const auto& x, const auto& y){ return str_toupper(x) < str_toupper(y);});
    for(const auto& i: arr)
        cout << i << " ";
    return 0;
}
//[](int x){ return (x >= 0);}