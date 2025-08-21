#ifndef USER_H

#define USER_H



#include <string>

#include "Location.h"



class User 
{


public:


    //this is the constructor that  will be initializing the user 
    User(char code, int id, std::string name, int rating, const Location& loc);


    //this is the destructor
    virtual ~User() {}



    //this will get the user's name
    std::string getName() const;


    //this will get the user's rating
    int getRating() const;


    //this will get the user's location
    Location getLocation() const;



    //this will print the user's details
    virtual void print() const;



protected:



    //this be representing the user's type
    char code;



    //this is what we are using for identifying the user
    int id;



    //this for the user's name
    std::string name;



    //this will be for the user's rating
    int rating;



    //this will be for the user's location
    Location location;



};



#endif // USER_H
