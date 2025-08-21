#ifndef DRIVER_H

#define DRIVER_H


#include <string>

#include "User.h"

#include "Drawable.h"

#include "Location.h"

#include "View.h"

#include "defs.h"



class Driver : public User, public Drawable 
{


public:


    //this is the constructor
    Driver(std::string name, int rating, Size size, const Location& loc);



    //these are the member functions
    int getDistance(const Location& otherLocation) const;


    void draw(View& view) override;




    //these are the static functions
    static int compRatings(Driver* a, Driver* b);


    static void resetNextId();




    //this will override the print function
    void print() const override;


    //this is the match function
    bool match(Size requiredSize, int customerRating) const;


    //this will set the location of the driver
    void setLocation(const Location& loc);


    //this will get the size of the driver
    Size getSize() const;


private:


    //this is the size for the driver
    Size size;                      


    //this static member is used to track next ID
    static int nextId;              


    //this is the character code for the driver
    static const char code;        


    //this will draw the layer for the driver
    static const int driverLayer;   



    //this helper function is used to change the Size enum to a string
    std::string sizeToString(Size s) const;



};



#endif // DRIVER_H
