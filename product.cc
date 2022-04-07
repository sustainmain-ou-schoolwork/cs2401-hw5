#include "product.h"

double Product::getPrice() const {
    return price;
}

void Product::setPrice(double pPrice) {
    price = pPrice;
}

void Product::input(std::istream& ins) {
    if (&ins == &std::cin) {
        std::cout << "Enter the price: $";
    }
    ins >> price;
}

void Product::output(std::ostream& outs) const {
    if (&outs == &std::cout) {
        outs << "Price: ";
    }
    outs << price << '\n';
}

int Product::readNumber(std::istream& ins, std::string msg) {
    bool valid = false;
    std::string lineIn;
    int choice;

    while (!valid) {
        // output the message if using cin
        if (&ins == &std::cin) {
            std::cout << msg;
        }

        // get a line from cin
        getline(ins, lineIn);

        // make sure that lineIn can be cast to int, then cast it
        if(lineIn.length() > 0 && isdigit(lineIn[0])) {
            choice = stoi(lineIn);

            valid = true;
        }
        else {
            // print error message if lineIn cannot be cast
            if (&ins == &std::cin) {
                std::cout << "Invalid number.\n";
            }
        }
    }

    return choice;
}

int Product::readNumber(std::istream& ins, int min, int max) {
    bool valid = false;
    std::string lineIn;
    int choice;

    while (!valid) {
        // read a number
        choice = readNumber(ins, "Enter a number between " + std::to_string(min) + " and " + std::to_string(max) + ": ");

        // check if the number is within the bounds
        if (choice >= min && choice <= max) {
            valid = true;
        }

        // print error message if number is out of bounds
        if(!valid) {
            if (&ins == &std::cin) {
                std::cout << "Invalid number.\n";
            }
        }
    }

    return choice;
}

int Product::menu(std::istream& ins, std::string options[], int numOptions) {
    for (int i = 0; i < numOptions; i++) {
        std::cout << std::setw(5) << (std::to_string(i + 1) + ") ") << options[i] << '\n';
    }

    return (readNumber(ins, 1, numOptions) - 1);
}

std::istream& Product::operator >> (std::istream& ins) {
    input(ins);
    return ins;
}

std::ostream& Product::operator << (std::ostream& outs) const {
    output(outs);
    return outs;
}


Key::Key() {
    setPrice(45);
    roomNumber = 0;
    active = false;
    stickerColor = 0;
}

void Key::input(std::istream& ins) {

    Product::input(ins);

    roomNumber = readNumber(ins, "Enter the room number: ");
}

void Key::output(std::ostream& outs) const {
    Product::output(outs);


}