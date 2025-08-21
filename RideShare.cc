#include "RideShare.h"

#include "Driver.h"

#include "Customer.h"

#include <limits>


//this static will compare function the
//for Drawable* that will be maintaining the order for insertion
int RideShare::drawableCompare(Drawable* a, Drawable* b) 
{

    return 0; 


}




//this is the constructor
RideShare::RideShare()
    : drivers(Driver::compRatings), customers(Customer::compNames), drawables(drawableCompare) 
    {


}



//this is the destructor
RideShare::~RideShare() 
{


    //this will delete all the drivers
    while (drivers.getSize() > 0) 
    {

        delete drivers.remove(0);

    }


    //this will delete all the customers
    while (customers.getSize() > 0) 
    {

        delete customers.remove(0);

    }


    //this will clear the list for drawables without deleting it
    drawables.clear();


}




//this will add a new driver
void RideShare::addDriver(const std::string& name, Size size, int rating, const Location& loc) 
{

    Driver* newDriver = new Driver(name, rating, size, loc);

    drivers.add(newDriver);

    drawables.add(newDriver);


}



//this will add a new customer
void RideShare::addCustomer(const std::string& name, int rating, const Location& loc) 
{

    Customer* newCustomer = new Customer(name, rating, loc);

    customers.add(newCustomer);

    drawables.add(newCustomer); 


}




//this will get Customer by their ID 
Customer* RideShare::getCustomer(const std::string& id) const 
{

    for (int i = 0; i < customers.getSize(); ++i) 
    {

        Customer* customer = customers.get(i);


        if (customer->getIdString() == id) 
        {


            return customer;


        }

    }

    return nullptr;


}



//this will find the driver thats closest matched
Driver* RideShare::findRide(int rating, Size size, const Location& loc) const 
{

    Driver* closestDriver = nullptr;


    int minDistance = std::numeric_limits<int>::max();



    for (int i = 0; i < drivers.getSize(); ++i) 
    {

        Driver* driver = drivers.get(i);

        if (driver->getSize() >= size && std::abs(driver->getRating() - rating) <= 2) 
        {

            int distance = driver->getDistance(loc);


            if (distance < minDistance) 
            {


                minDistance = distance;

                closestDriver = driver;


            }

        }

    }



    return closestDriver;


}




//this will print all of the customers
void RideShare::printCustomers() const 
{

    for (int i = 0; i < customers.getSize(); ++i) 
    {


        customers.get(i)->print();


    }


}



//this will print all of the drivers
void RideShare::printDrivers() const 
{

    for (int i = 0; i < drivers.getSize(); ++i) 
    {

        drivers.get(i)->print();

    }


}




//this will draw all the of the objects that are drawable
void RideShare::draw(View& view) const 
{
    
    for (int i = 0; i < drawables.getSize(); ++i) 
    {

        drawables.get(i)->draw(view);


    }


}
