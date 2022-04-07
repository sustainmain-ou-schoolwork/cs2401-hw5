#include <iostream>
#include <fstream>
#include <list>
#include "product.h"

using namespace std;

int main(int arc, const char* argv[]) {
    list<Product*> products;
    list<Product*>::iterator it;

    ifstream fin;
    fin.open("input.txt");

    ofstream fout;
    fout.open("output.txt");

    if (fin.fail()) {
        cout << "Failed to open file." << endl;
        return EXIT_FAILURE;
    }

    if (fout.fail()) {
        cout << "Failed to open file." << endl;
        return EXIT_FAILURE;
    }

    products.push_back(new Key());

    it = products.begin();

    string options[] = {"object 1", "object 2", "object 3"};
    // cout << (*it) -> getPrice() << endl;
    // cout << (*it) -> readNumber(fin, 1, 3) << endl;
    // cout << (*it) -> readNumber(fin, "test") << endl;
    // cout << (*it) -> menu(fin, options, 3) << endl;
    // cout << (*it) -> readYN(cin, "[y/n]") << endl;

    (*it) -> input(cin);
    (*it) -> output(fout);
    (*it) -> output(cout);

    fin.close();

    return EXIT_SUCCESS;
}