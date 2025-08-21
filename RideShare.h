#ifndef RIDESHARE_H

#define RIDESHARE_H


#include <string>

#include "List.h"

#include "Driver.h"

#include "Customer.h"

#include "Drawable.h"

#include "View.h"



class RideShare 
{


public:

    //this is the constructor
    RideShare();



    //this is the destructor
    ~RideShare();



    //these are the member functions
    void addDriver(const std::string& name, Size size, int rating, const Location& loc);



    void addCustomer(const std::string& name, int rating, const Location& loc);



    Customer* getCustomer(const std::string& id) const;



    Driver* findRide(int rating, Size size, const Location& loc) const;



    void printCustomers() const;



    void printDrivers() const;



    void draw(View& view) const;



private:


    List<Driver*> drivers;


    List<Customer*> customers;


    List<Drawable*> drawables;
    


    //this static will compare the function for Drawable*
    static int drawableCompare(Drawable* a, Drawable* b);


};



#endif // RIDESHARE_H
