#include <algorithm>
#include <cstring>
#include <iostream>
#include <iterator>
#include <string>

using namespace std;

int main() {
    string test = "../../data";
    cout << "test length = " << test.size() << endl;

    //    for (string::iterator iter = test.begin(); iter != test.end(); ++iter) {
    //        cout << iter.base() << endl;  //  cout all the char from iter
    //        cout << *iter << endl;        // cout only the char pointed by iter
    //    }

    //    test.erase(test.find("data"));
    //    cout << test << endl;

    //    size_t num = test.find("/");
    //    cout << num << endl;

    /***************************/
    /*** find the last substring behind the last / in a string like ../../data ***/
    /***************************/
    string rootName;
    string rootPath;
    for (string::reverse_iterator riter = test.rbegin(); riter != test.rend(); ++riter) {
        if (riter == test.rbegin()) {
            continue;
        }
        string current = riter.base().base();
        // cout << current << endl;
        if (strcmp(current.c_str(), "/") == 0) {
            break;
        }
        rootName.append(current);
        test.erase(riter.base());
    }
    reverse(rootName.begin(), rootName.end());
    cout << test << endl;
    cout << rootName << endl;
    return 0;
}
