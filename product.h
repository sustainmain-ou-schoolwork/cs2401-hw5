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
         * @brief Display a menu and get a choice from the user.
         * 
         * @param ins the istream to get the choice from
         * @param options the array with all the options available
         * @param numOptions the number of options in the array 
         * @return the index of the option that the user chose
         */
        int menu(std::istream& ins, std::string options[], int numOptions);

    private:
        double price;  // the price of the Product
};


class Key:public Product {
    public:
        Key();

        void input(std::istream& ins);
        void output(std::ostream& outs) const;

    private:
        int roomNumber;    // the number of the room that the key goes to
        bool active;       // true if the key is still active
        int stickerColor;  // the color of the sticker on the key
};

#endif