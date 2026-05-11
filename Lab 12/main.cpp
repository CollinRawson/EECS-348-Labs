#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <iomanip>

using namespace std;

double extractNumeric(const std::string& str);

static const double INVALID = -999999.99;

// Converts string to double without using std library
double stringToDouble(string validNum, string sciNotMod) {
    double newDouble = 0;
    bool isNeg = false;
    // Find decimal index
    int decIndex = validNum.find('.');
    if (decIndex == -1) {decIndex = validNum.length();}
    else {validNum.erase(decIndex, 1);}
    // Check if negative and remove sign
    if (validNum[0] == '-') {
        validNum.erase(0, 1);
        isNeg = true;
        decIndex--;
    }
    else if (validNum[0] == '+') {
        validNum.erase(0, 1);
        decIndex--;
    }
    // Iterate through number using equation to convert
    if (decIndex > 19) { return INVALID; }
    for (int i = 0; i < (int)validNum.length(); i++) {
        newDouble += (validNum[i] - '0') * pow(10,(-i + decIndex -1));
    }
    // Correct for negatives
    if (isNeg) {
        newDouble *= -1;
    }
    // Check scientific notation
    if (sciNotMod != "0") {
        newDouble = newDouble * pow(10, stringToDouble(sciNotMod, "0"));
    }
    // Check range
    if (newDouble > 1.7e308 || newDouble < -1.7e308) {return INVALID;}
    return newDouble;
}

double extractNumeric(const std::string& str) {
    bool isDec = false;
    string sciNotMod = "";
    string originalString = "";
    string newString = "";
    string firstNumBeyond = "";
    string endResult = "";
    // Copies string
    for (char c : str) {
        originalString += c;
    }
    // Fixes error of only sign
    if (originalString == "-" || originalString == ".") {return INVALID;}
    // Finds start of num
    char lastDigit = 'a';
    int pos = 0;
    for (char c : str) {
        if (!isdigit(c) && !(c == '.' || (c == '-' && !isdigit(lastDigit)
            && pos+1 < (int)str.size() && (isdigit(str[pos+1]) || str[pos+1] == '.')))) { 
            originalString.erase(0,1);
            lastDigit = c;
            pos++;
            if (originalString == "") {
                return INVALID;
            }
        }
        else {
            if (lastDigit == '-' || c == '-') {
                newString += "-";
                originalString.erase(0,1);
            }
            else if (lastDigit == '.' || c == '.') {
                newString += ".";
                isDec = true;
                originalString.erase(0,1);
            }
            break;
        }
    }
    // Copies string
    for (char c : originalString) {
        firstNumBeyond += c;
    }
    // Find end of num
    for (char c : firstNumBeyond) {
        if (c == '.' || isdigit(c)) {
            if (c == '.') {
                if (isDec) {
                    return INVALID;
                }
                isDec = true;
            }
            newString += c;
            originalString.erase(0,1);
        }
        else {
            break;
        }
    }
    // Copies string
    for (char c : originalString) {
        endResult += c;
    }
    // Handles scientific notation
    if (originalString[0] == 'e' || originalString[0] == 'E') {
        endResult.erase(0,1);
        bool hasExpDigit = false;
        for (int i = 1; i < (int)originalString.size(); i++) {
            char c = originalString[i];
            if (c == '+' || c == '-' || isdigit(c)) {
                if (isdigit(c)) hasExpDigit = true;
                sciNotMod += c;
                endResult.erase(0,1);
            }
            else { break; }
        }
        if (!hasExpDigit) { return INVALID; }
    }
    else {sciNotMod = "0";}
    // Checks to ensure no invalid overflow
    for (char c : endResult) {
        if (isdigit(c)) {
            return INVALID;
        }
    }
    return stringToDouble(newString, sciNotMod);
}

int main() {
    while (true) {
        string userString = "";
        cout << "Enter a string (or 'END' to quit): ";
        getline(cin, userString);
        if (userString == "END") {break;}
        double result = extractNumeric(userString);
        if (result != INVALID) {
            cout << "Extracted number: " << fixed << setprecision(4) << result << "\n";
        }
        else {
            cout << "Invalid input: no valid floating-point number found" << "\n";
        }
    }
}