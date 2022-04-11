#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <iostream>
#include <iomanip>
#include <cctype>


/**
 * @brief Converts a double to a string, chopping off any extra decimal places.
 * 
 * @param input the double to convert
 * @param numDecimals the number of decimal places to keep (-1 will remove all trailing zeros)
 * @return the double as a string, with the desired number of decimal places
 */
std::string doubleToString(double input, int numDecimals = -1);

/**
 * @brief Print a value, preceded by a label if using cout.
 * 
 * @param outs the ostream to output to
 * @param label the label for the value
 * @param value the value to print
 * @param altValue the alternative value to print if cout is not being used (leave empty to use value in either case)
 */
void outputValue(std::ostream& outs, std::string label, std::string value, std::string altValue = "");

/**
 * @brief Read a line from ins.
 * 
 * @param ins the istream to read a number from
 * @param msg the message used to prompt the user
 * @return the line that gets read
 */
std::string readLine(std::istream& ins, std::string msg = "");

/**
 * @brief Read an integer from ins.
 * 
 * @param ins the istream to read an integer from
 * @param msg the message used to prompt the user
 * @return an integer
 */
int readInt(std::istream& ins, std::string msg = "");

/**
 * @brief Read an integer from ins between min and max.
 * 
 * @param ins the istream to read an integer from
 * @param min the minimum allowed value
 * @param max the maximum allowed value
 * @param msg the message used to prompt the user ("" defaults to a message describing the range)
 * @return an integer between min and max
 */
int readInt(std::istream& ins, int min, int max, std::string msg = "");

/**
 * @brief Read a double from ins.
 * 
 * @param ins the istream to read a double from
 * @param msg the message used to prompt the user
 * @return a double
 */
double readDouble(std::istream& ins, std::string msg = "");

/**
 * @brief Read a double from ins between min and max.
 * 
 * @param ins the istream to read a double from
 * @param min the minimum allowed value
 * @param max the maximum allowed value
 * @param numDecimals the number of decimals to display from min and max (-1 will remove all trailing zeros)
 * @param msg the message used to prompt the user ("" defaults to a message describing the range)
 * @return a double between min and max
 */
double readDouble(std::istream& ins, double min, double max, int numDecimals = -1, std::string msg = "");

/**
 * @brief Read a char and return true if it's a 'y' or 'Y'.
 * 
 * @param ins the istream to read the response from
 * @param msg the message used to prompt the user
 * @return true if the user enters y or Y
 */
bool readYN(std::istream& ins, std::string msg = "");

/**
 * @brief Display a menu and get a choice from the user.
 * 
 * @param ins the istream to get the choice from
 * @param options the array with all the options available
 * @param numOptions the number of options in the array
 * @param msg the message used to prompt the user
 * @return the index of the option that the user chose
 */
int menu(std::istream& ins, std::string options[], int numOptions, std::string msg = "");


class Product {
    public:
        void setPrice(double pPrice);

        virtual void input(std::istream& ins);
        virtual void output(std::ostream& outs) const;

        std::istream& operator >> (std::istream& ins);
        std::ostream& operator << (std::ostream& outs) const;

    private:
        double price;  // the price of the Product
};


class Key:public Product {
    public:
        Key(double pPrice = 45, int pRoomNumber = 0, bool pActive = false, int pStickerColor = 0);

        void input(std::istream& ins);
        void output(std::ostream& outs) const;

    private:
        int roomNumber;    // the number of the room that the key goes to
        bool active;       // true if the key is still active
        int stickerColor;  // the index number of the color of the sticker on the key
};


class Brick:public Product {
    public:
        Brick(double pPrice = 10, int pText = 0, int pAge = 0, int pColor = 0, double pDirtiness = 0);

        void input(std::istream& ins);
        void output(std::ostream& outs) const;

    private:
        int text;          // the index number of the text on the brick
        int age;           // the age of the brick
        int color;         // the index number of the color of the brick
        double dirtiness;  // how dirty the brick is (0-100)
};


class Smoothie:public Product {
    public:
        Smoothie(double pPrice = 6.75, int pFlavor = 0, bool pExtraPowder = false, std::string pName = "", double pPercentConsumed = 0);

        void input(std::istream& ins);
        void output(std::ostream& outs) const;

    private:
        int flavor;              // the index number of the smoothie flavor
        bool extraPowder;        // true if the smoothie should have extra powder
        std::string name;        // the name written on the smoothie
        double percentConsumed;  // how much of the smoothie should already be consumed (0-100)
};


class Deer:public Product {
    public:
        Deer(double pPrice = 100, int pFavoriteBuilding = 0, int pAge = 0, std::string pName = "");

        void input(std::istream& ins);
        void output(std::ostream& outs) const;

    private:
        int favoriteBuilding;  // the index number of the deer's favorite building
        int age;               // the age of the deer
        std::string name;      // the name of the deer
};


class Marker:public Product {
    public:
        Marker(double pPrice = 1.25, int pColor = 0, int pBrand = 0, double pPercentConsumed = 0);

        void input(std::istream& ins);
        void output(std::ostream& outs) const;

    private:
        int color;               // the index number of the color of the marker
        int brand;               // the index number of the brand of the marker
        double percentConsumed;  // how much of the marker should already be used (0-100)
};

#endif