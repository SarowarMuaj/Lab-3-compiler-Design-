#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool isAlphaOrUnderscore(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
}

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

bool isAlnumOrUnderscore(char c) {
    return isAlphaOrUnderscore(c) || isDigit(c);
}

bool isValidVariableName(const string& variableName) {
    if (variableName.empty() || !isAlphaOrUnderscore(variableName[0]))
        return false;
 for (size_t i = 0; i < variableName.length(); ++i) {
    char c = variableName[i];
    if (!isAlnumOrUnderscore(c))
        return false;
}

    return true;
}

int main() {
    ifstream inputFile("Keyword.txt");
    string input;
     cout<<"enter the identifier which you want to search for: ";
     cin>>input;

     string s;
     bool found = false;
     if(!isValidVariableName(input)){
        return 1;
     }
     while(inputFile>>s){
        if (s==input){
            cout<<"identifier is a built in identifier";
            found=true;
            break;
        }
     }
     if(!found){
        cout<<"identifier is a correct identifier";
     }

    inputFile.close();

    //cout << "Is valid variable name: " << boolalpha << isValidVariableName(variableName) << endl;

    return 0;
}
