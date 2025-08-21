#ifndef CUSTOMER_H


#define CUSTOMER_H



#include "User.h"

#include "Drawable.h"

#include "Location.h"

#include "View.h"

#include <string>




class Customer : public User, public Drawable 
{

    
public:


    //this is the constructor
    Customer(std::string name, int rating, const Location& loc);



    //this will override the draw function
    void draw(View& view) override;



    //the static will compare the function for sorting by its names
    static int compNames(Customer* a, Customer* b);



    //static function is used to reset nextId
    static void resetNextId();



    //this will override the print function
    void print() const override;



    //this will get the ID for customer by using a string
    std::string getIdString() const;



    //this will set the location for the customers
    void setLocation(const Location& loc);




private:



    //this is used for generating the IDs
    static int nextId;           


    //this used for the character code for the customer
    static const char code;      


     //this will draw the layer for the Customer
    static const int custLayer; 


};

#endif // CUSTOMER_H
