//============================================================================
// Name        : cpp-basics.cpp
// Author      : Petr Stepanov
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>

using namespace std;

void printStringView(string_view s) {
    // Iterating string_view
    for (char c : s){
        printf("%c", c);
    }
    printf("\n");
}

void printStringC(string s) {
    // Iterating C string
    const char* c = s.c_str();  // Mutable pointer to an immutable string
    while (*c != 0){
        printf("%c", *c);
        c++;
    }
    printf("\n");
}

struct Entry {
    string name;
    int number;
};

int main(int argc, char* argv[]) {

    //      _        _
    //  ___| |_ _ __(_)_ __   __ _
    // / __| __| '__| | '_ \ / _` |
    // \__ \ |_| |  | | | | | (_| |
    // |___/\__|_|  |_|_| |_|\__, |
    //                       |___/

    // Initialization
    string name1 = "Niels Stroustrup";
    string name2 ("Petr Stepanov");       // Constructor
    string name3 (3, 's');                // Three characters 's' - good for reservation
    string name4 {"Annemarie"};           // Initializer list (c++20)
    cout << name1 << '\n' << name2 << '\n' << name3 << '\n' << name4 << endl;

    // Mutability
    string s = "mY";
    s = s+' ';
    s += "String";
    cout << s << endl;

    // Character access
    s[0] = toupper(s[0]);
    s[1] = tolower(s[1]);

    // Character iteration
    printStringView(s);
    printStringC(s);

    // Substring manipulation
    s.replace(0,2,"Your");                 // (position, length, replace_string)
    cout << s << endl;
    string s_sub = s.substr(5,6);          // (position, length)
    cout << s_sub << endl;

    //                 _
    // __   _____  ___| |_ ___  _ __
    // \ \ / / _ \/ __| __/ _ \| '__|
    //  \ V /  __/ (__| || (_) | |
    //   \_/ \___|\___|\__\___/|_|

    // Initialization
    vector<int> v1 = {1, 2, 3, 4};         // size is 4
    vector<string> v2;                     // size is 0
    vector<Entry*> v3(23);                 // size is 23; initial element value: nullptr
    vector<double> v4(32, 9.9);            // size is 32; initial element value: 9.9

    // Iteration


    // Initializer list for custom class
    vector<Entry> phone_book = {
            {"David Hume", 123456},
            {"Karl Popper", 234567},
            {"Bertrand Arthur William Russell", 345678}
    };
    for (int i = 0; i!=phone_book.size(); ++i){
        cout << phone_book[i].name << ' ' << phone_book[i].number << endl;
    }
    for (const Entry& entry : phone_book){
        cout << entry.name << ' ' << entry.number << endl;
    }

    //     _ _     _
    //    | (_)___| |_
    //    | | / __| __|
    //    | | \__ \ |_
    //    |_|_|___/\__|

    // Doubly-linked list


    //     _ __ ___   __ _ _ __
    //    | '_ ` _ \ / _` | '_ \
    //    | | | | | | (_| | |_) |
    //    |_| |_| |_|\__,_| .__/
    //                    |_|

    // Initialization
    map<string,int> phone_book_map {
        {"David Hume",123456},
        {"Karl Popper",234567},
        {"Bertrand Arthur William Russell",345678}
    };

    cout << phone_book_map["David Hume"] << endl;

    return 0;
}
