
If you put your code in a single file like this:

#include <iostream>
#include <string>

using namespace std;

string trim(const string& str)
{
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first)
    {
        return str;
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

int main() {
    string s = "abc ";
    cout << trim(s);
return 0;
}
