/*
 *   Copyright (C) 2015 The Quantum Project
 *
 *      This program is free software: you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation, either version 3 of the License, or
 *      (at your option) any later version.
 *
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License
 *      along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "File.hpp"
#include "Token.hpp"

#include <list>
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <unordered_map>
#include <bits/stream_iterator.h>

void run(std::list<string> list);

using namespace std;

std::ostream &operator<<(std::ostream &os, TokenType tt) {
    return os << static_cast<int >(tt);
}


std::string join(std::list<string> &elements, const char *const seperator) {
    switch (elements.size()) {
        case 0:
            return "";
        case 1:
            return *elements.begin();
        default:
            ostringstream os;
            copy(elements.begin(), elements.end(), std::ostream_iterator<string>(os, seperator));
            return os.str();
    }
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

template<typename T>
std::string to_string(T const &value) {
    stringstream sstr;
    sstr << value;
    return sstr.str();
}

int main(int argc, char *argv[]) {

    for (int i = 1; i < argc; i++) {

    }


//    char *code = (char *) "var hi\n"
//            "var hello\n"
//            "var ans\n"
//            "set hi 5\n"
//            "set hello 10\n"
//            "mult ans hi hello\n"
//            "sub ans ans hi\n"
//            "printvar ans\n"
//            "input hi\n"
//            "printvar hi";

    //TODO Functions/Methods

    // This code waits for use to enter two numbers, then multiplies together and outputs to screen
    char *multiplication_code = (char *) "var num1;var num2;var ans;input num1;input num2;mult ans num1 num2;printvar ans;";
    char *addition_code = (char *) "var num1;var num2;var ans;input num1;input num2;add ans num1 num2;printvar ans;";
    char *subtraction_code = (char *) "var num1;var num2;var ans;input num1;input num2;sub ans num1 num2;printvar ans;";
    char *division_code = (char *) "var num1;var num2;var ans;input num1;input num2;div ans num1 num2;printvar ans;";
    char *deg_code = (char *) "var deg;var rad;var onee;var pi;var data;var ans;var uIn;set pi 3.1415;set onee 180;set rad torad;set deg todeg;input data;input uIn;ifeq uIn rad;div ans pi onee;endif;ifeq uIn deg;div ans onee pi;endif;mult ans data ans;printvar ans;";


    //first input is num1, second is operator (+-*/), third is num2
    char *calc_code = (char *) "var vdiv;set vdiv /;var vmult;set vmult *;var vadd;set vadd +;var vmin;set vmin -;var num1;var num2;var opt;var ans;input num1;input opt;input num2;ifeq opt vadd;add ans num1 num2;endif;ifeq opt vmin;sub ans num1 num2;endif;ifeq opt vmult;mult ans num1 num2;endif;ifeq opt vdiv;div ans num1 num2;endif;printvar ans;";

//    char *if_code = (char *) "var div;set div /;";

    File file("Calc.quciel");
    const char *code = file.GetContents();

    run(split(code, ';'));

    exit(0);
}

int ifLevel = 0;

void run(std::list<string> list1) {
    unordered_map<string, string> varMap;
    for (std::list<string>::iterator list_iterator = list1.begin(); list_iterator != list1.end(); list_iterator++) {
//        std::cout << "\t" << *list_iterator << " : " << ifLevel << endl;
        list<string> parts = split(*list_iterator, ' ');
        if (ifLevel < 1) {
            if (*parts.begin() == "var") {
                parts.pop_front();
                varMap.insert(make_pair(*parts.begin(), ""));
            }
            if (*parts.begin() == "set") {
                parts.pop_front();
                string var = *parts.begin();
                parts.pop_front();
                string data = join(parts, " ");
                auto it = varMap.find(var);
                if (it != varMap.end())
                    it->second = data;
            }
            if (*parts.begin() == "printvar") {
                parts.pop_front();
                cout << varMap[*parts.begin()] << endl;
            }
            if (*parts.begin() == "add") {
                parts.pop_front();
                string var = *parts.begin();
                parts.pop_front();
                string v2 = *parts.begin();
                parts.pop_front();
                string v3 = *parts.begin();
                double nVal = strtod(varMap[v2].c_str(), NULL) + strtod(varMap[v3].c_str(), NULL);
                auto it = varMap.find(var);
                if (it != varMap.end())
                    it->second = to_string(nVal);
            }
            if (*parts.begin() == "mult") {
                parts.pop_front();
                string var = *parts.begin();
                parts.pop_front();
                string v2 = *parts.begin();
                parts.pop_front();
                string v3 = *parts.begin();
                double nVal = strtod(varMap[v2].c_str(), NULL) * strtod(varMap[v3].c_str(), NULL);
                auto it = varMap.find(var);
                if (it != varMap.end())
                    it->second = to_string(nVal);
            }
            if (*parts.begin() == "div") {
                parts.pop_front();
                string var = *parts.begin();
                parts.pop_front();
                string v2 = *parts.begin();
                parts.pop_front();
                string v3 = *parts.begin();
                double nVal = strtod(varMap[v2].c_str(), NULL) / strtod(varMap[v3].c_str(), NULL);
                auto it = varMap.find(var);
                if (it != varMap.end())
                    it->second = to_string(nVal);
            }
            if (*parts.begin() == "sub") {
                parts.pop_front();
                string var = *parts.begin();
                parts.pop_front();
                string v2 = *parts.begin();
                parts.pop_front();
                string v3 = *parts.begin();
                double nVal = strtod(varMap[v2].c_str(), NULL) - strtod(varMap[v3].c_str(), NULL);
                auto it = varMap.find(var);
                if (it != varMap.end())
                    it->second = to_string(nVal);
            }
            if (*parts.begin() == "input") {
                parts.pop_front();
                string var = *parts.begin();

                string uInput;
                cin >> uInput;

                auto it = varMap.find(var);
                if (it != varMap.end())
                    it->second = uInput;
            }
        } else {
            if (*parts.begin() == "endif") {
                ifLevel--;
            }
        }
        if (*parts.begin() == "ifeq") {
            parts.pop_front();
            string var = *parts.begin();
            parts.pop_front();
            string var2 = *parts.begin();
            cout << "\t\t" << varMap[var] << " : " << varMap[var2] << " : " << (varMap[var] == varMap[var2]) << endl;
            if (varMap[var] != varMap[var2]) ifLevel++;
        }

    }

    for (int i = 0; i < 10; i++)
        cout << endl;

}