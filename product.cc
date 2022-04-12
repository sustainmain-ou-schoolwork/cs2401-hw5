#include "product.h"


std::string doubleToString(double input, int numDecimals) {
    std::string output;

    if (numDecimals <= -1) {  // remove all trailing zeros
        output = std::to_string(input);

        // run through the whole string backwards
        for (int i = output.length() - 1; i > 0; i--) {
            if (output[i] == '0') {
                // remove the last char from output and keep going
                output = output.substr(0, i);
            }
            else if (output[i] == '.') {
                // remove the decimal point and stop removing characters
                output = output.substr(0, i);
                break;
            }
            else{
                break;
            }
        }
    }
    else if (numDecimals <= 0) {
        // special case for 0 so decimal point is removed
        output = std::to_string(static_cast<int>(input));
    }
    else {
        output = std::to_string(input);
        output = output.substr(0, (output.find('.') + numDecimals + 1));
    }

    return output;
}

void outputValue(std::ostream& outs, std::string label, std::string value, std::string altValue) {
    if (&outs == &std::cout) {
        outs << label;
        outs << value << '\n';
    }
    else {
        if (altValue == "") {
            outs << value << '\n';
        }
        else{
            outs << altValue << '\n';
        }
    }
}

std::string readLine(std::istream& ins, std::string msg) {
    std::string lineIn;

    if (&ins == &std::cin) {
        std::cout << msg;
    }

    getline(ins, lineIn);

    return lineIn;
}

int readInt(std::istream& ins, std::string msg) {
    return static_cast<int>(readDouble(ins, msg));
}

int readInt(std::istream& ins, int min, int max, std::string msg) {
    return static_cast<int>(readDouble(ins, min, max, -1, msg));
}

double readDouble(std::istream& ins, std::string msg) {
    bool valid = false;
    std::string lineIn;
    double choice;

    while (!valid) {
        // output the message if using cin
        if (&ins == &std::cin) {
            std::cout << msg;
        }

        // get a line from cin
        getline(ins, lineIn);

        // try to cast lineIn
        try {
            choice = stod(lineIn);

            valid = true;
        }
        catch (const std::invalid_argument& ia) {
            // print error message if lineIn cannot be cast
            if (&ins == &std::cin) {
                std::cout << "Invalid input.\n";
            }
        }
    }

    return choice;
}

double readDouble(std::istream& ins, double min, double max, int numDecimals, std::string msg) {
    bool valid = false;
    std::string lineIn;
    double choice;

    while (!valid) {
        // read a number
        if (msg == "") {
            msg = "Enter a number between " + doubleToString(min, numDecimals) + " and " + doubleToString(max, numDecimals) + ": ";
        }
        choice = readDouble(ins, msg);

        // check if the number is within the bounds
        if (choice >= min && choice <= max) {
            valid = true;
        }

        // print error message if number is out of bounds
        if(!valid) {
            if (&ins == &std::cin) {
                std::cout << "Invalid input.\n";
            }
        }
    }

    return choice;
}

bool readYN(std::istream& ins, std::string msg) {
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

int menu(std::istream& ins, std::string options[], int numOptions, std::string msg) {
    int choice;

    if (&ins == &std::cin) {
        if (msg != "") {
            std::cout << msg << '\n';
        }

        // print each option
        for (int i = 0; i < numOptions; i++) {
            std::cout << std::setw(5) << std::to_string(i + 1) << ") " << options[i] << '\n';
        }

        // get the choice number and subtract 1 to get the index number
        choice = (readInt(ins, 1, numOptions) - 1);
    }
    else {
        // get the index number directly
        choice = readInt(ins, 0, (numOptions - 1));
    }

    return choice;
}



void Product::setPrice(double pPrice) {
    price = pPrice;
}

void Product::input(std::istream& ins) {
    if (&ins != &std::cin) {
        price = readDouble(ins, "Enter the price: $");
    }
}

void Product::output(std::ostream& outs) const {
    outputValue(outs, "Price: $", doubleToString(price, 2));
}

std::istream& Product::operator >> (std::istream& ins) {
    input(ins);
    return ins;
}

std::ostream& Product::operator << (std::ostream& outs) const {
    output(outs);
    return outs;
}


Key::Key(double pPrice, int pRoomNumber, bool pActive, int pStickerColor) {
    setPrice(pPrice);
    roomNumber = pRoomNumber;
    active = pActive;
    stickerColor = pStickerColor;
}

void Key::input(std::istream& ins) {
    const int NUM_COLORS = 6;
    std::string colors[] = {"Red", "Orange", "Yellow", "Green", "Blue", "Purple"};

    // get values
    Product::input(ins);
    roomNumber = readInt(ins, "Enter the room number: ");
    active = readYN(ins, "Do you want the key to still work? [Y/N] ");
    stickerColor = menu(ins, colors, NUM_COLORS, "Pick a sticker color:");
}

void Key::output(std::ostream& outs) const {
    std::string colors[] = {"Red", "Orange", "Yellow", "Green", "Blue", "Purple"};

    // print item name
    outs << "Key\n";

    // print values
    Product::output(outs);
    outputValue(outs, "Room number: ", std::to_string(roomNumber));
    std::string tmp = (active ? "active" : "inactive");
    outputValue(outs, "Key is " + tmp, "", std::to_string(active));
    outputValue(outs, "Sticker color: ", colors[stickerColor], std::to_string(stickerColor));

    outs << '\n';
}


Brick::Brick(double pPrice, int pText, int pAge, int pColor, double pDirtiness) {
    setPrice(pPrice);
    text = pText;
    age = pAge;
    color = pColor;
    dirtiness = pDirtiness;
}

void Brick::input(std::istream& ins) {
    const int NUM_TEXTS = 3;
    std::string texts[] = {"Athens Block", "Nelsonville Block", ""};
    const int NUM_COLORS = 4;
    std::string colors[] = {"Red", "Orange", "Grey", "Brown"};

    // get values
    Product::input(ins);
    text = menu(ins, texts, NUM_TEXTS, "Pick the text you want on the brick:");
    age = readInt(ins, "Enter the age of the brick: ");
    color = menu(ins, colors, NUM_COLORS, "Pick a color:");
    dirtiness = readDouble(ins, 0, 100, 2, "Enter the dirtiness of the brick as a number 0-100: ");
}

void Brick::output(std::ostream& outs) const {
    std::string colors[] = {"Red", "Orange", "Grey", "Brown"};
    std::string texts[] = {"Athens Block", "Nelsonville Block", ""};

    // print item name
    outs << "Brick\n";

    // print values
    Product::output(outs);
    outputValue(outs, "Text: ", texts[text], std::to_string(text));
    outputValue(outs, "Age: ", std::to_string(age));
    outputValue(outs, "Color: ", colors[color], std::to_string(color));
    outputValue(outs, "Dirtiness: ", doubleToString(dirtiness, 2));

    outs << '\n';
}


Smoothie::Smoothie(double pPrice, int pFlavor, bool pExtraPowder, std::string pName, double pPercentConsumed) {
    setPrice(pPrice);
    flavor = pFlavor;
    extraPowder = pExtraPowder;
    name = pName;
    percentConsumed = pPercentConsumed;
}

void Smoothie::input(std::istream& ins) {
    const int NUM_FLAVORS = 8;
    std::string flavors[] = {"Chocolate-Covered Strawberry", "Hawaiian Sunrise", "Mango Madness", "Pina Colada", "Strawberry Banana", "Summer Sunset", "Tropical Blend", "West Green Warrior"};

    // get values
    Product::input(ins);
    flavor = menu(ins, flavors, NUM_FLAVORS, "Pick the flavor:");
    extraPowder = readYN(ins, "Do you want extra powder? [Y/N] ");
    name = readLine(ins, "Enter your name: ");
    percentConsumed = readDouble(ins, 0, 100, 2, "Enter how much of the smoothie should be consumed already as a number 0-100: ");
}

void Smoothie::output(std::ostream& outs) const {
    std::string flavors[] = {"Chocolate-Covered Strawberry", "Hawaiian Sunrise", "Mango Madness", "Pina Colada", "Strawberry Banana", "Summer Sunset", "Tropical Blend", "West Green Warrior"};

    // print item name
    outs << "Smoothie\n";

    // print values
    Product::output(outs);
    outputValue(outs, "Flavor: ", flavors[flavor], std::to_string(flavor));
    std::string tmp = (extraPowder ? "Extra powder" : "No extra powder");
    outputValue(outs, tmp, "", std::to_string(extraPowder));
    outputValue(outs, "Name: ", name);
    outputValue(outs, "Percent consumed: ", doubleToString(percentConsumed, 2));

    outs << '\n';
}


Deer::Deer(double pPrice, int pFavoriteBuilding, int pAge, std::string pName) {
    setPrice(pPrice);
    favoriteBuilding = pFavoriteBuilding;
    age = pAge;
    name = pName;
}

void Deer::input(std::istream& ins) {
    const int NUM_BUILDINGS = 7;
    std::string buildings[] = {"ARC", "Convo", "Glidden", "Morton", "Nelson", "Pruitt Field", "Stocker"};

    // get values
    Product::input(ins);
    favoriteBuilding = menu(ins, buildings, NUM_BUILDINGS, "What should the deer's favorite building be:");
    age = readInt(ins, "Enter the age of the deer: ");
    name = readLine(ins, "Enter the name of the deer: ");
}

void Deer::output(std::ostream& outs) const {
    std::string buildings[] = {"ARC", "Convo", "Glidden", "Morton", "Nelson", "Pruitt Field", "Stocker"};

    // print item name
    outs << "Deer\n";

    // print values
    Product::output(outs);
    outputValue(outs, "Favorite building: ", buildings[favoriteBuilding], std::to_string(favoriteBuilding));
    outputValue(outs, "Age: ", std::to_string(age));
    outputValue(outs, "Name: ", name);

    outs << '\n';
}


Marker::Marker(double pPrice, int pColor, int pBrand, double pPercentConsumed) {
    setPrice(pPrice);
    color = pColor;
    brand = pBrand;
    percentConsumed = pPercentConsumed;
}

void Marker::input(std::istream& ins) {
    const int NUM_COLORS = 4;
    std::string colors[] = {"Black", "Blue", "Green", "Red"};
    const int NUM_BRANDS = 3;
    std::string brands[] = {"AmazonBasics", "EXPO", "U Brands"};

    // get values
    Product::input(ins);
    color = menu(ins, colors, NUM_COLORS, "Pick a marker color:");
    brand = menu(ins, brands, NUM_BRANDS, "Pick a marker brand:");
    percentConsumed = readDouble(ins, 0, 100, 2, "Enter how much of the marker should be used already as a number 0-100: ");
}

void Marker::output(std::ostream& outs) const {
    std::string colors[] = {"Black", "Blue", "Green", "Red"};
    std::string brands[] = {"AmazonBasics", "EXPO", "U Brands"};

    // print item name
    outs << "Marker\n";

    // print values
    Product::output(outs);
    outputValue(outs, "Color: ", colors[color], std::to_string(color));
    outputValue(outs, "Brand: ", brands[brand], std::to_string(brand));
    outputValue(outs, "Percent used: ", doubleToString(percentConsumed, 2));

    outs << '\n';
}
