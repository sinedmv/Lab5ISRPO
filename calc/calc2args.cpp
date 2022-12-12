#include "calc2args.h"

bool CheckForFloat(const std::string& str) {
    std::string temp = str;
    if (temp[0] == '-') {
        temp.erase(temp.begin());
    }
    if (temp[0] == '.' || temp[temp.size() - 1] == '.' || (temp[0] == '0' && temp.size() > 1 && temp[1] != '.')) {
        return false;
    }
    std::istringstream iss(temp);
    double f;
    iss >> f;
    return iss.eof() && !iss.fail();
}

bool CheckForOperation(CalcTwoArgs& temp, const std::string& str) {
    if (str == "+") {
        temp.isPlus = true;
        return true;
    }
    if (str == "-") {
        temp.isMinus = true;
        return true;
    }
    if (str == "*") {
        temp.isMult = true;
        return true;
    }
    if (str == "/") {
        temp.isDiv = true;
        return true;
    }
    return false;
}

CalcTwoArgs ArgParser(const std::string& str) {
    CalcTwoArgs ans;
    std::vector<std::string> input_words;
    std::string temp;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != ' ') {
            temp += str[i];
        } else {
            if (temp.length() != 0) {
                input_words.push_back(temp);
                temp.clear();
            }
        }
    }
    if (temp.length() != 0) {
        input_words.push_back(temp);
        temp.clear();
    }
    if (input_words.size() != 3) {
        ans.valid = false;
        std::cerr << "Please, enter your expression like this:" << std::endl;
        std::cerr << "val1 *operation* val2" << std::endl;
        return ans;
    }
    if (!CheckForOperation(ans, input_words[1])) {
        ans.valid = false;
        std::cerr << "Use this operations: + - * /" << std::endl;
        return ans;
    }

    if (CheckForFloat(input_words[0]) && CheckForFloat(input_words[2])) {
        ans.firstArg = std::stod(input_words[0]);
        ans.secondArg = std::stod(input_words[2]);
        ans.valid = true;
        return ans;
    }

    std::cerr << "Enter only Integer or Float values" << std::endl;
    ans.valid = false;
    return ans;
}

