#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>
#include <clang-c/Index.h>

using namespace std;

const string MENU_OPTIONS_FILE = "./data/menu_options.txt";

void printWelcomeMessage(string inputFileName);

void getInputFunctionNames(vector<string> inputFunctions);

vector<string> getInputFunctions(string fileName);

vector<string> getFunctionInfo(CXCursor CURRENT_CURSOR);

void loadMenuOptions(vector<string>& list);

void printMenuOptions(const vector<string>& list);

int getMenuOptionChoice();

int main(int argc, char* argv[]) {
    try{
        if(argc < 2) {
            throw runtime_error("Not enough arguments provided. Missing input file name.\n");
        } else {
            string inputFileName = argv[1];
            vector<string> menuOptions{};
            vector<string> inputFunctionNames{};
            vector<string> inputFunctions{};

            getInputFunctions(inputFileName);
            loadMenuOptions(menuOptions);
            printWelcomeMessage(inputFileName);
            printMenuOptions(menuOptions);
        }
    } catch (exception& error){
        cerr << endl << "Error: " << error.what() << endl;
    }
    return 0;
}

void printWelcomeMessage(string inputFileName) {
    cout << endl <<  "Welcome to Stinky Code Smell Detection!" << endl << endl
         << "The file \"" << inputFileName << "\" contains the following methods/functions: "
         << endl;

    // TODO: Create a getFxnsFrom input file method

}

void getInputFunctionNames(vector<string> inputFunctions)
{
    cout << "Getting input function names " << endl;
    // TODO: Parse the function names from the inputFunctions, this is called after reading from input file
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

vector<string> getInputFunctions(string fileName)
{
    vector<string> inputFunctions{};
    CXIndex INDEX = clang_createIndex(0,0);
    CXTranslationUnit TRANSLATION_UNIT = clang_parseTranslationUnit(INDEX, fileName.c_str(), nullptr, 0, nullptr, 0, CXTranslationUnit_None);

    cout << "Getting input functions from: " << fileName << endl;

    try {
        if(TRANSLATION_UNIT == nullptr) {
            throw runtime_error("Failed to parse translation unit from clang.\n");
        }

        CXCursor CURRENT_CURSOR = clang_getTranslationUnitCursor(TRANSLATION_UNIT);
        clang_visitChildren(CURRENT_CURSOR, [CURRENT_CURSOR](CXCursor cursor, CXCursor parent, CXClientData clientData) -> CXChildVisitResult {
            getFunctionInfo(CURRENT_CURSOR);
            return CXChildVisit_Recurse;
        }, nullptr);

        clang_disposeTranslationUnit(TRANSLATION_UNIT);
        clang_disposeIndex(INDEX);

    } catch (exception& error){
        cerr << endl << "Error: " << error.what() << endl;
    }

    return inputFunctions;
}

vector<string> getFunctionInfo(CXCursor CURRENT_CURSOR){
    vector<string> functionNames{};
    CXString currentFunctionName = clang_getCursorSpelling(CURRENT_CURSOR);
    CXCursorKind currentCursorKind = clang_getCursorKind(CURRENT_CURSOR);

    if(currentCursorKind == CXCursor_FunctionDecl) {
        cout << "Function Name: " << clang_getCString(currentFunctionName);
        functionNames.push_back(clang_getCString(currentFunctionName));
    }

    clang_disposeString(currentFunctionName);
    return functionNames;
}

void printMenuOptions(const vector<string>& list)
{
    cout << endl << "Please select an option:" << endl;
    for(const auto & value : list) {
        cout << value << endl;
    }
}

int getMenuOptionChoice() {
    //int userMenuOptionChoice = 0;

    //while(userMenuOptionChoice < 1 || userMenuOptionChoice > 4) {

    //}

    return 0;
}

