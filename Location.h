#ifndef LOCATION_H

#define LOCATION_H




#include <iostream>


#include <string>


using namespace std;




class Location 
{

public:

    
    Location(int x = 0, int y = 0);


    //this will set the location for the x and y coordinate
    void setLocation(int x, int y);


    //this will get the x-coordinate of the location
    int getX() const {return x;} 


    //this will get the y-coordinate of the loaction
    int getY() const {return y;} 


    //this will calculate the distance for the other location by using Manhattan
    int getDistance(const Location& l) const; 


    //this will print the location
    void print();

   
    //these are the public variables that will represent x and y
    int x, y;


private:


    //this will convert the street number to its street name
    string street(int);


};


#endif
