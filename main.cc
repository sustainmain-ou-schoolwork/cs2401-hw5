#include <iostream>
#include <fstream>
#include <list>
#include "product.h"

using namespace std;

int main(int arc, const char* argv[]) {
    list<Product*> products;
    list<Product*>::iterator it;

    int numOptions = 6;
    string options[] = {"Key", "Brick", "Smoothie", "Deer", "Marker", "Quit"};

    int choice;
    Product* p;

    ifstream fin;
    fin.open("orders.txt");

    // read orders from file
    while ((!fin.fail()) && (!fin.eof())) {
        bool skip = false;
        string lineIn;
        getline(fin, lineIn);

        if (lineIn == "Key") {
            p = new Key();
        }
        else if (lineIn == "Brick") {
            p = new Brick();
        }
        else if (lineIn == "Smoothie") {
            p = new Smoothie();
        }
        else if (lineIn == "Deer") {
            p = new Deer();
        }
        else if (lineIn == "Marker") {
            p = new Marker();
        }
        else {
            skip = true;
        }

        if (!skip) {
            p -> input(fin);
            products.push_back(p);
        }   
    }
    fin.close();

    // print greeting
    cout << "Welcome to the Scuffed Bobcat Depot!" << endl;
    cout << "All items in the store can be found on campus." << endl;


    do {
        cout << "Select an item to buy." << endl;
        choice = (menu(cin, options, numOptions) + 1);

        switch (choice) {
            case 1:
                p = new Key();
                break;
            case 2:
                p = new Brick();
                break;
            case 3:
                p = new Smoothie();
                break;
            case 4:
                p = new Deer();
                break;
            case 5:
                p = new Marker();
                break;
        }

        if (choice != numOptions) {
            p -> input(cin);
            products.push_back(p);
        }
    } while (choice != numOptions);


    // open ofstream to save orders
    ofstream fout;
    fout.open("orders.txt");

    if (fout.fail()) {
        cout << "Failed to open file." << endl;
        return EXIT_FAILURE;
    }

    // save orders
    if (!products.empty()) {
        it = products.begin();
        do {
            (*it) -> output(fout);
            it++;
        } while (it != products.end());
    }


    return EXIT_SUCCESS;
}