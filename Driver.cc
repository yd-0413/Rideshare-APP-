#include "Driver.h"



#include <cmath>

#include <iostream>



//this will initialize the static members



//the ID will be starting from 1
int Driver::nextId = 1;   




//this is the character code for the Driver
const char Driver::code = 'D';  



//this will draw the layer for the driver 
const int Driver::driverLayer = 1;   




//this is the constructor
Driver::Driver(std::string name, int rating, Size size, const Location& loc)

    : User(code, nextId++, name, rating, loc),

      Drawable(driverLayer),

      size(size) {}




//this is the match function
bool Driver::match(Size requiredSize, int customerRating) const 
{


    //this will check if the driver's size is at least the requiredSize
    bool sizeMatch = (size >= requiredSize);


    //this will check if the difference in the rating is at most 2
    bool ratingMatch = (std::abs(rating - customerRating) <= 2);


    return sizeMatch && ratingMatch;


}



//this get the distance for the other location
int Driver::getDistance(const Location& otherLocation) const 
{


    return location.getDistance(otherLocation);


}


//this will override the draw function
void Driver::draw(View& view)
{

    view.drawDriver(location.getX(), location.getY(), name[0]);


}




//this static function will compare the function for sorting by its ratings
int Driver::compRatings(Driver* a, Driver* b)
{

    return b->getRating() - a->getRating();


}



//this static function will be used to reset the nextId
void Driver::resetNextId()
{

    nextId = 1;


}



//this will override the print function
void Driver::print() const 
{


    //this will print the user's information
    User::print();



    //this will add the specific information for the driver
    std::cout << "User Type: Driver" << std::endl;


    std::cout << "Vehicle Size: " << sizeToString(size) << std::endl;



}



//this helper function is used to change Size enum to a string
std::string Driver::sizeToString(Size s) const 
{


    switch(s) 
    {

        case small: return "Small";

        case medium: return "Medium";

        case large: return "Large";

        default: return "Unknown";


    }


}



//this will set the location for the driver
void Driver::setLocation(const Location& loc) 
{


    location = loc;


}




//this will get the size for the driver
Size Driver::getSize() const
{


    return size;


}

