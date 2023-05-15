#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>
#include <cctype>
#include <algorithm>
#include <regex>

using namespace std;

const string MENU_OPTIONS_FILE = "./data/menu_options.txt";
const int MENU_LOWERBOUND = 1;
const int MENU_UPPERBOUND = 4;

void printWelcomeMessage(string inputFileName, const vector<string> functionNames);

void parseFunctionNames(vector<string> &functionNames, string line);

vector<string> getInputFunctionNames(string fileName);

void loadMenuOptions(vector<string>& list);

void printMenuOptions(const vector<string>& list);

int getMenuOptionChoice();

bool isDigits(string input);

int main(int argc, char* argv[]) {
    try{
        if(argc < 2) {
            throw runtime_error("Not enough arguments provided. Missing input file name.\n");
        } else {
            string inputFileName = argv[1];
            vector<string> menuOptions;
            vector<string> inputFunctionNames;
            vector<string> inputFunctions;

            inputFunctionNames = getInputFunctionNames(inputFileName);
            loadMenuOptions(menuOptions);
            printWelcomeMessage(inputFileName, inputFunctionNames);
            printMenuOptions(menuOptions);
            getMenuOptionChoice();
        }
    } catch (exception& error){
        cerr << endl << "Error: " << error.what() << endl;
    }
    return 0;
}

void printWelcomeMessage(string inputFileName, const vector<string> functionNames) {
    cout << endl <<  "Welcome to Stinky Code Smell Detection!" << endl << endl
         << "The file \"" << inputFileName << "\" contains the following methods/functions: ";
    for(int index = 0; index < (int) functionNames.size(); index++) {
        cout << functionNames[index];
        if(index < (int) (functionNames.size() - 1)){
            cout << ", ";
        }
    }
    cout << endl;
}

void parseFunctionNames(vector<string> &functionNames, string line)
{
    regex regex(R"(^\s*[\w\s]+\b([a-zA-Z_][a-zA-Z0-9_]*)\s*\()");

    smatch match;
    if (regex_search(line, match, regex)) {
        string possibleFunctionName = match[1];
        if(possibleFunctionName != "for" && possibleFunctionName != "while" && possibleFunctionName != "if"){
            for (size_t i = 1; i < match.size(); i++) {
                functionNames.push_back(match[i]);
            }
        }
    }
}

void loadMenuOptions(vector<string>& list){
    ifstream inFile;
    string line;

    inFile.open(MENU_OPTIONS_FILE);
    if(!inFile.fail()) {
        while(getline(inFile, line)) {
            list.push_back(line);
        }
    } else {
        cout << endl << "Menu option file was unable to be opened." << endl;
    }

    inFile.close();
}

vector<string> getInputFunctionNames(string fileName)
{
    ifstream inputFile;
    vector<string> inputFunctionNames;
    string line;

    //cout << "opening " << fileName << endl;
    inputFile.open(fileName);

    if(!inputFile.fail()){
        cout << "reading from " << fileName << endl;
        while(getline(inputFile, line)) {
            // cout << "current line: " << line << endl;
            parseFunctionNames(inputFunctionNames, line);
        }
    } else {
        cout << "Failed to open " << fileName << endl;
    }

    inputFile.close();
    return inputFunctionNames;
}

void printMenuOptions(const vector<string>& list)
{
    cout << endl << "============== MENU ==============" << endl;
    for(const string & value : list) {
        cout << value << endl;
    }
    cout << "==================================" << endl;
}

int getMenuOptionChoice() {
    int userMenuChoice = 0;
    string userInput;

    while(userMenuChoice < MENU_LOWERBOUND || userMenuChoice > MENU_UPPERBOUND) {
        cout << "Please select an option: ";
        cin >> userInput;
        if(isDigits(userInput)){
            userMenuChoice = stoi(userInput);
        } else {
            cout << "Invalid option. ";
        }
    }

    cout << endl << "You have chosen option " << userMenuChoice << "." << endl;

    return userMenuChoice;
}

bool isDigits(string input){
    bool isOnlyDigits = true;
    for(int index = 0; index < (int) input.length(); index++) {
        if(!isdigit(input[index])){
            isOnlyDigits = false;
        }
    }
    return isOnlyDigits;
}