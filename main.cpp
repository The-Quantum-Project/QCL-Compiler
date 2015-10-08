#include "Token.h"
#include <list>
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <unordered_map>

void run(std::list<string> list);

using namespace std;

std::ostream &operator<<(std::ostream &os, TokenType tt) {
    return os << static_cast<int >(tt);
}

std::list<std::string> &split(const std::string &s, char delim, std::list<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        if (!item.empty()) {
            elems.push_back(item);
        }
    }
    return elems;
}

std::list<std::string> split(const std::string &s, char delim) {
    std::list<std::string> elems;
    split(s, delim, elems);
    return elems;
}

int main() {

    char *code = (char *) "var hi\n"
            "set hi 5";

    list<string> list1;
    list1 = split(code, '\n');

    run(list1);

    cout << list1.size() << endl;

    system("pause");
    return 0;
}

void run(std::list<string> list1) {
    unordered_map<string, string> varMap;
    for (std::list<string>::iterator list_iter = list1.begin(); list_iter != list1.end(); list_iter++) {
        list<string> parts = split(*list_iter, ' ');
        if (*parts.begin() == "var") {
            parts.pop_front();
            cerr << parts.size() << endl;
            varMap.insert(make_pair(*parts.begin(), ""));
        }
        if (*parts.begin() == "set") {
            list<string> parts2 = split(*list_iter, ' ');
            parts2.pop_front();
            string dev[3];
            int i = 0;
            for (auto &itr : parts2) {
                dev[i] = itr;
                i++;
            }
            auto it = varMap.find(dev[0]);
            if (it != varMap.end())
                it->second = dev[1];
        }
        std::cout << *list_iter << endl;
    }

    for (int i = 0; i < 10; i++)cout << endl;
    for (auto &itr : varMap) {
        cout << itr.first << ": " << itr.second << endl;
    }

}