#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <iostream>
#include <iomanip>
#include <cctype>


class Product {
    public:
        double getPrice() const;

        void setPrice(double pPrice);

        virtual void input(std::istream& ins);
        virtual void output(std::ostream& outs) const;

        std::istream& operator >> (std::istream& ins);
        std::ostream& operator << (std::ostream& outs) const;

        /**
         * @brief Read a line from ins.
         * 
         * @param the istream to read a number from
         * @param msg the message used to prompt the user
         * @return the line that gets read
         */
        std::string readLine(std::istream& ins, std::string msg = "");

        /**
         * @brief Read a number from ins.
         * 
         * @param ins the istream to read a number from
         * @param msg the message used to prompt the user
         * @return a number
         */
        int readNumber(std::istream& ins, std::string msg = "");

        /**
         * @brief Read a number from ins between min and max.
         * 
         * @param ins the istream to read a number from
         * @param min the minimum allowed value
         * @param max the maximum allowed value
         * @return a number between min and max
         */
        int readNumber(std::istream& ins, int min, int max);

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