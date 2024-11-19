#pragma once
#include "funcs.h"

int checkInt(std::string str) {
    if (str.find(".") != str.npos) {
        cout << "Ошибка ввода строки" << endl;
        return 0;
    }
    else {
        return stoi(str);
    }
}
double checkDouble(std::string str) {
    return stod(str);

}
std::string checkStr(std::string str) {
    if (str.find("/") != str.npos || str.find(".") != str.npos || std::regex_search(str, std::regex("[0-9]"))) {
        return "Ошибка ввода строки";

    }
    else {
        return(str);
    }
}

void menu() {

}
