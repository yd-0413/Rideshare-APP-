#include "User.h"

#include <iostream>




//this is the constructor
User::User(char code, int id, std::string name, int rating, const Location& loc)

    : code(code), id(id), name(name), rating(rating), location(loc) {}




//these are the getters
std::string User::getName() const 
{


    return name;


}



int User::getRating() const 
{


    return rating;


}



Location User::getLocation() const 
{


    return location;



}




//this is the print function
void User::print() const 
{


    std::cout << "ID: " << code << id << std::endl;


    std::cout << "Name: " << name << std::endl;


    std::cout << "Rating: " << rating << std::endl;


    std::cout << "Location: (" << location.getX() << ", " << location.getY() << ")" << std::endl;
    


}
