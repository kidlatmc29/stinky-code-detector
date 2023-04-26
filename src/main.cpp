#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

const string MENU_OPTIONS_FILE = "../data/menu_options.txt";

void getMenuOptions(list<string> list);

int main() {
    list<string> menuOptions{};
    getMenuOptions(menuOptions);

    cout << "Hello, World!" << std::endl;
    return 0;
}

void getMenuOptions(list<string> list){
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


