#include "product.h"

double Product::getPrice() const {
    return price;
}

void Product::setPrice(double pPrice) {
    price = pPrice;
}

void Product::input(std::istream& ins) {
    price = readNumber(ins, "Enter the price: $");
}

void Product::output(std::ostream& outs) const {
    if (&outs == &std::cout) {
        outs << "Price: $";
    }
    outs << price << '\n';
}

std::string Product::readLine(std::istream& ins, std::string msg) {
    std::string lineIn;

    if (&ins == &std::cin) {
        std::cout << msg;
    }

    getline(ins, lineIn);

    return lineIn;
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
        if((lineIn.length() > 0 && isdigit(lineIn[0])) || (lineIn.length() > 1 && lineIn[0] == '-' && isdigit(lineIn[1]))) {
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

bool Product::readYN(std::istream& ins, std::string msg) {
    std::string lineIn;
    char checkChar;

    // output the message if using cin
    if (&ins == &std::cin) {
        std::cout << msg;
    }

    while (true) {
        // get a line from cin
        getline(ins, lineIn);

        // make sure that lineIn has input
        if(lineIn.length() > 0) {
            // check for Y if using cin, otherwise check for 1
            if (&ins == &std::cin) {
                checkChar = 'Y';
            }
            else {
                checkChar = '1';
            }

            // check for the character selected above
            if (toupper(lineIn[0]) == checkChar) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            // print error message if lineIn is empty
            if (&ins == &std::cin) {
                std::cout << "Invalid answer.\n";
            }
        }
    }
}

int Product::menu(std::istream& ins, std::string options[], int numOptions) {
    for (int i = 0; i < numOptions; i++) {
        std::cout << std::setw(5) << std::to_string(i + 1) << ") " << options[i] << '\n';
    }

    return readNumber(ins, 1, numOptions);
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
    const int NUM_COLORS = 6;
    std::string colors[] = {"Red", "Orange", "Yellow", "Green", "Blue", "Purple"};

    Product::input(ins);

    roomNumber = readNumber(ins, "Enter the room number: ");
    active = readYN(ins, "Do you want the key to still work? [Y/N] ");
    std::cout << "Pick a sticker color:\n";
    stickerColor = (menu(ins, colors, NUM_COLORS) - 1);
}

void Key::output(std::ostream& outs) const {
    std::string colors[] = {"Red", "Orange", "Yellow", "Green", "Blue", "Purple"};

    // print price
    Product::output(outs);

    // print room number
    if (&outs == &std::cout) {
        outs << "Room number: ";
    }
    outs << roomNumber << '\n';

    // print whether the key is active or not
    if (&outs == &std::cout) {
        outs << "Key is " << (active ? "active" : "inactive") << '\n';
    }
    else {
        outs << active << '\n';
    }
    
    // print sticker color
    if (&outs == &std::cout) {
        outs << "Sticker color: " << colors[stickerColor] << '\n';
    }
    else {
        outs << stickerColor << '\n';
    }
}


Brick::Brick() {
    setPrice(10);
    text = "";
    age = 0;
    color = 0;
    dirtiness = 0;
}

void Brick::input(std::istream& ins) {
    const int NUM_COLORS = 4;
    std::string colors[] = {"Red", "Orange", "Grey", "Brown"};

    Product::input(ins);

    text = readLine(ins, "Enter the text on the brick: ");
    age = readNumber(ins, "Enter the age of the brick: ");
    std::cout << "Pick a color:\n";
    color = (menu(ins, colors, NUM_COLORS) - 1);
}

void Brick::output(std::ostream& outs) const {
    std::string colors[] = {"Red", "Orange", "Grey", "Brown"};

    // print price
    Product::output(outs);

    // print text
    if (&outs == &std::cout) {
        outs << "Text: ";
    }
    outs << text << '\n';

    // print age
    if (&outs == &std::cout) {
        outs << "Age: ";
    }
    outs << age << '\n';
    
    // print color
    if (&outs == &std::cout) {
        outs << "Color: " << colors[color] << '\n';
    }
    else {
        outs << color << '\n';
    }
}


Smoothie::Smoothie() {

}

void Smoothie::input(std::istream& ins) {

}

void Smoothie::output(std::ostream& outs) const {

}


Deer::Deer() {

}

void Deer::input(std::istream& ins) {

}

void Deer::output(std::ostream& outs) const {

}


Marker::Marker() {

}

void Marker::input(std::istream& ins) {

}

void Marker::output(std::ostream& outs) const {

}
