#include <iostream>
#include <fstream>
#include <list>
#include "product.h"

using namespace std;


/**
 * @brief Output all the Products to outs.
 * 
 * @param products the list of Products
 * @param outs the ostream to output to
 */
void outputAll(list<Product*> products, std::ostream& outs);

/**
 * @brief Use input from an istream to generate Products and load them in the products list.
 * 
 * @param products the list of products
 * @param ins the istream to read Product data from
 */
void inputAll(list<Product*>& products, std::istream& ins);


int main(int arc, const char* argv[]) {
    list<Product*> products;

    ifstream fin;
    fin.open("orders.txt");

    // read orders from file
    inputAll(products, fin);
    fin.close();

    // print greeting
    cout << "Welcome to the Scuffed Bobcat Depot!" << endl;
    cout << "All items in the store can be found on campus." << endl;

    // get all the orders until the user is done
    inputAll(products, cin);


    // open ofstream to save orders
    ofstream fout;
    fout.open("orders.txt");

    if (fout.fail()) {
        cout << "Failed to open file." << endl;
        return EXIT_FAILURE;
    }

    // save orders
    outputAll(products, fout);


    return EXIT_SUCCESS;
}


void outputAll(list<Product*> products, ostream& outs) {
    list<Product*>::iterator it;

    if (!products.empty()) {
        it = products.begin();
        do {
            (*it) -> output(outs);
            it++;
        } while (it != products.end());
    }
}

void inputAll(list<Product*>& products, std::istream& ins) {
    int numOptions = 7;
    string options[] = {"Buy Key", "Buy Brick", "Buy Smoothie", "Buy Deer", "Buy Marker", "Display orders", "Quit"};

    int choice = 0;
    bool skip;
    string lineIn;

    Product* p;

    while (!(ins.fail() || ins.eof() || choice == numOptions)) {
        if (&ins == &cin) {
            skip = false;  // menu() will only pass valid option numbers
            choice = (menu(ins, options, numOptions, "What would you like to do?") + 1);
            cout << '\n';
        }
        else {
            skip = true;  // only set to false when lineIn is a valid option
            getline(ins, lineIn);

            // look for an option that matches the string 
            for (int i = 0; i < numOptions - 2; i++) {
                // if lineIn is a valid option
                if (options[i] == "Buy " + lineIn) {
                    skip = false;
                    choice = i + 1;
                    break;
                }
            }
        }

        // run the chosen option
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
            case 6:
                outputAll(products, cout);
                break;
            case 7:
                break;
            default:
                if (&ins == &cin) {
                    cout << "ERROR, defaulting to quit\n";
                }
                choice = numOptions;
                break;
        }

        if (!skip && choice >= 1 && choice <= 5) {
            // set the values of the new Product
            p -> input(ins);

            products.push_back(p);
        }
    }
}
