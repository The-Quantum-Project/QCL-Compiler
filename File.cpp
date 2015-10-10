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

File::File(const char *filelocation) {
    ifstream file(filelocation, ios_base::in);
    if (file.is_open()) {
        string x;
        while (getline(file, x)) {
            this->file.append(x);
        }
        file.close();
    } else {
        cerr << filelocation << " was unable to load." << endl;
    }
}

const char *File::GetContents() {
    return file.c_str();
}
