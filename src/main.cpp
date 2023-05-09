#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

const string MENU_OPTIONS_FILE = "../data/menu_options.txt";

void printWelcomeMessage();

void loadMenuOptions(vector<string>& list);

void printMenuOptions(const vector<string>& list);

 int getMenuOptionChoice();

int main() {
    vector<string> menuOptions{};

    loadMenuOptions(menuOptions);
    printWelcomeMessage();
    printMenuOptions(menuOptions);


    return 0;
}

void printWelcomeMessage() {
    cout << "Welcome to Stinky Code Smell Detection!" << endl
         << "The file you input contains the following methods/functions: "
         << endl;

    // TODO: Create a getFxnsFrom input file method


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
        cout << "Menu option file was unable to be opened." << endl;
    }

    inFile.close();
}

void printMenuOptions(const vector<string>& list)
{
    cout << "Please select an option:" << endl;
    for(const auto & value : list) {
        cout << value << endl;
    }
}


int getMenuOptionChoice() {
    int userMenuOptionChoice = 0;

    while(userMenuOptionChoice < 1 || userMenuOptionChoice > 4) {

    }

}

