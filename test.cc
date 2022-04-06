#include <iostream>
#include <list>
#include "product.h"

using namespace std;

int main(int arc, const char* argv[]) {
    list<Product*> products;
    list<Product*>::iterator it;

    Key* k = new Key();
    products.push_back(k);

    it = products.begin();

    string options[] = {"object 1", "object 2", "object 3"};
    cout << (*it) -> getPrice() << endl;
    cout << (*it) -> getNumber(cin, 1, 3) << endl;
    (*it) -> menu(cin, options, 3);
}