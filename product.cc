#include "product.h"

double Product::getPrice() const {
    return price;
}

void Product::setPrice(double pPrice) {
    price = pPrice;
}

int Product::getNumber(std::istream& ins, int min, int max) {
    bool validChoice = false;
    std::string lineIn;
    int choice = 0;

    do {
        if (&ins == &std::cin) {
            std::cout << "Enter a number between " << min << " and " << max << ": ";
        }

        getline(ins, lineIn);
        if(lineIn.length() > 0 && isdigit(lineIn[0])) {
            choice = stoi(lineIn);

            if (choice >= min && choice <= max) {
                validChoice = true;
            }
        }

        if(!validChoice) {
            if (&ins == &std::cin) {
                std::cout << "Invalid choice.\n";
            }
        }
    } while (!validChoice);

    return choice;
}

int Product::menu(std::istream& ins, std::string options[], int numOptions) {
    for (int i = 0; i < numOptions; i++) {
        std::cout << std::setw(5) << (std::to_string(i + 1) + ") ") << options[i] << '\n';
    }

    return (getNumber(ins, 1, numOptions) - 1);
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

}

void Key::output(std::ostream& outs) const {

}