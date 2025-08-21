#include "Customer.h"


#include <iostream>



//this will initialize the static members



// the ID will start from 1
int Customer::nextId = 1;  



//this is the character code for Customer
const char Customer::code = 'C'; 



//this will draw the layer for the customer
const int Customer::custLayer = 3;  




//this is the constructor
Customer::Customer(std::string name, int rating, const Location& loc)


    : User(code, nextId++, name, rating, loc),


      Drawable(custLayer) {}




//this will override the draw function
void Customer::draw(View& view) 
{


    view.drawCustomer(location.getX(), location.getY(), name[0]);


}




//this static function will be used to compare the function for sorting by its names
int Customer::compNames(Customer* a, Customer* b) 
{

    return a->getName().compare(b->getName());


}




//this static function is being used to reset the nextId
void Customer::resetNextId() 
{

    nextId = 1;


}




//this will override the print function
void Customer::print() const 
{

    //this will print the user's information
    User::print();



    //this will add the specific information for the customer 
    std::cout << "User Type: Customer" << std::endl;



}




//this will get the ID for the customer as a string 
std::string Customer::getIdString() const 
{


    return std::string(1, code) + std::to_string(id);



}



//this will set the location for the customer 
void Customer::setLocation(const Location& loc) 
{


    location = loc;


}
