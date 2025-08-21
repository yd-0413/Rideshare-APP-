#include "Location.h"

#include <cmath>


//this is the constructor 
Location::Location(int x, int y) : x(x), y(y) {}


//this will set the location for the x and y coordinate 
void Location::setLocation(int x, int y) 
{


    //this will update the x and y coordinate
    this->x = x;


    this->y = y;


}



//this will calculate the distance for another location by using the Manhattan distance
int Location::getDistance(const Location& l) const 
{

    //this is the manhattan distance  
    return abs(l.x - x) + abs(l.y - y); 


}


//this will print the location
void Location::print() 
{


    //this will output the street names by using the x and y coordinates
    cout << street(x) << " and " << street(y);


}


//this will convert the street number to its street name
string Location::street(int s) 
{


    switch (s % 10) 
    {

        case 1: return to_string(s) + "st Ave";

        case 2: return to_string(s) + "nd Ave";

        case 3: return to_string(s) + "rd Ave";

        default: return to_string(s) + "th Ave";


    }

    
}
