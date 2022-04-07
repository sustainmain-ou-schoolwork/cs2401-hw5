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

    if (fin.fail()) {
        cout << "Failed to open file." << endl;
        return EXIT_FAILURE;
    }

    Key* k = new Key();
    products.push_back(k);

    it = products.begin();

    string options[] = {"object 1", "object 2", "object 3"};
    cout << (*it) -> getPrice() << endl;
    cout << (*it) -> readNumber(fin, 1, 3) << endl;
    cout << (*it) -> readNumber(fin, "test") << endl;
    cout << (*it) -> menu(fin, options, 3) << endl;

    fin.close();

    return EXIT_SUCCESS;
}