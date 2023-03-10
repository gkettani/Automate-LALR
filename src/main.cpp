#include <iostream>
#include <fstream>
#include <regex>
#include "Lexer/lexer.h"
#include "Automate/automate.h"

const string FORMULES_FILE = "formules.txt";
const string RESULTATS_FILE = "resultats.txt";

const regex WHITESPACE_REGEX("[\r\n\\s]+");

int main()
{
    ifstream inputFile(FORMULES_FILE);
    ofstream outputFile(RESULTATS_FILE);

    if (inputFile.is_open() && outputFile.is_open()) {
        string line;
        while (getline(inputFile, line)) {
            line = regex_replace(line, WHITESPACE_REGEX, "");
            Automate automate = Automate(new Lexer(line));
            int result = automate.lecture();
            if (result == -1) {
                outputFile << "Expression Error : " << line << " is not valid." << endl;
            } else {
                outputFile << result << endl;
            }       
        }
        inputFile.close();
        outputFile.close();
        cout << "All expressions have been evaluated. Check resultats.txt" << endl;
    }
    else {
        cerr << "Unable to open file: " << FORMULES_FILE << " or " << RESULTATS_FILE << endl;
        return 1;
    }

    return 0;
}
