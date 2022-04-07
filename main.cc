#include <iostream>
#include <fstream>
#include <list>
#include "product.h"

using namespace std;

int main(int arc, const char* argv[]) {
    list<Product*> products;
    list<Product*>::iterator it;

    bool firstItem = true;

    int numOptions = 6;
    string options[] = {"Key", "Brick", "Smoothie", "Deer", "Marker", "Quit"};

    int choice;
    Product tmp;

    ifstream fin;
    fin.open("inventory.txt");

    ofstream fout;
    fout.open("inventory.txt");

    if (fin.fail()) {
        cout << "Failed to open file." << endl;
        return EXIT_FAILURE;
    }

    if (fout.fail()) {
        cout << "Failed to open file." << endl;
        return EXIT_FAILURE;
    }

    while (!fin.eof()) {
        string lineIn;
        getline(fin, lineIn);

        Product* tmp;
        if (lineIn == "Key") {
            tmp = new Key();
        }
        else if (lineIn == "Brick") {
            tmp = new Brick();
        }
        else if (lineIn == "Smoothie") {
            tmp = new Smoothie();
        }
        else if (lineIn == "Deer") {
            tmp = new Deer();
        }
        else if (lineIn == "Marker") {
            tmp = new Marker();
        }
        else {
            break;
        }

        tmp -> input(fin);
        products.push_back(tmp);
    }

    // print greeting
    cout << "Welcome to the OU Merch Store!" << endl;
    cout << "All items in the store can be found on campus." << endl;


    do {
        cout << "Select an item to buy." << endl;
        choice = tmp.menu(cin, options, numOptions);

        switch (choice) {
            case 1:
                products.push_back(new Key());
                break;
            case 2:
                products.push_back(new Brick());
                break;
            case 3:
                products.push_back(new Smoothie());
                break;
            case 4:
                products.push_back(new Deer());
                break;
            case 5:
                products.push_back(new Marker());
                break;
        }

        if (choice != 6) {
            if (firstItem) {
                firstItem = false;
                it = products.begin();
            }

            (*it) -> input(cin);
        }
    } while (choice != 6);

    // output items
    if (!products.empty()) {
        it = products.begin();
        do {
            (*it) -> output(fout);
            it++;
        } while (it != products.end());
    }


    return EXIT_SUCCESS;
}