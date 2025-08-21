#include "Controller.h"


#include <sstream>


#include <vector>




Controller::Controller()
{



}




Controller::~Controller()
{
   
    

}


//this will launch the loop in the main program
void Controller::launch()
{


    //this will initialize the system for RideShare by giving you default
    //drivers and the customers
    initRideShare();



    //this will draw the current map
    displayMap();



    //this will write the menu and it will get user input
    int choice = -1;


    //these are the menu options which are represented as a vector of strings
    vector<string> menu ={
            "Display Map",

            "Print all drivers",

            "Print all customers",

            "Find a ride\n\nTests:\n",

            "Test display map",

            "Test find a ride"


        };




    while(choice!=0)
    {

        //this will display the menu and also get the users choice
        view.menu(menu, choice);


        //this will be handling the user's choices in the menu by using a switch statement
        switch(choice)
        {

            case 1: displayMap(); break;

            case 2: rideShare.printDrivers(); break;

            case 3: rideShare.printCustomers(); break;

            case 4: findRide(); break;

            case 5: testDisplayMap(); break;

            case 6: testFindRide(); break;


        }

    }



    cout<<"Bye!"<<endl;

    
}



void Controller::displayMap()
{

    view.refreshMap();

    rideShare.draw(view);

    view.displayMap();


}



void Controller::findRide()
{


    cout<<"Oops, not implemented yet!"<<endl;

    
}



int Controller::testDisplayMap()
{

    RideShare rideShare;

    vector<string> driverNames = {"Elsa", "Densel", "Carter", "Bob", "Alice"};

    vector<Size> driverSizes = {medium, small, large, small, medium};

    vector<int> driverRatings = {5, 4, 3, 4, 5};

    vector<Location> driverLocations = {Location(3,4), Location(1,1), Location(5,4), Location(2, 2), Location(7, 7)};

    vector<string> customers = {"Sally", "Jesse", "Isabelle", "Philip"};

    vector<int> customerRatings = {2, 5, 4, 3};

    vector<Location> customerLocations = {Location(5, 5), Location(3, 7), Location(4, 5), Location(1, 7)};

    initRideShare(rideShare, driverNames, driverSizes, driverRatings, driverLocations, customers, customerRatings, customerLocations);

    view.refreshMap();

    rideShare.draw(view);

    view.displayMap();



    //this will check if the drivers and the customers are at the right locations on the map
    int score = 0;


    //this will check that the drivers are at the correct locations
    int tempScore = 2;


    for (int i = 0; i < driverNames.size(); ++i)
    {


        char av = driverNames[i][0];


        Location l = driverLocations[i];


        char mapChar = view.getMap(l.x*4-1, l.y*2-1);



        if (mapChar != av)
        {


            cout<<"Driver "<<driverNames[i]<<" is not at the correct location"<<endl;


            cout<<"Expected "<<av<<" at "<<l.x<<", "<<l.y<<endl;


            cout<<"Got "<<mapChar<<" at "<<l.x<<", "<<l.y<<endl;



            tempScore --;

        }

    }



    tempScore = (tempScore < 0? 0: tempScore);



    cout<<"Driver location tests complete, score "<<tempScore<<"/2"<<endl;


    score += tempScore;



    tempScore = 2;




    //this will check if the customers are at the right locations
    for (int i = 0; i < customers.size(); ++i)
    {


        char av = customers[i][0];


        Location l = customerLocations[i];


        char mapChar = view.getMap(l.x*4+1, l.y*2);



        if (mapChar != av)
        {

            cout<<"Customer "<<customers[i]<<" is not at the correct location"<<endl;


            cout<<"Expected "<<av<<" at "<<l.x<<", "<<l.y<<endl;


            cout<<"Got "<<mapChar<<" at "<<l.x<<", "<<l.y<<endl;



            tempScore --;


        }


    }



    tempScore = (tempScore < 0? 0: tempScore);



    cout<<"Customer location tests complete, score "<<tempScore<<"/2"<<endl;



    score += tempScore;



    cout<<"Total score: "<<score<<"/4"<<endl;

    

    return score;



}



//this will test the functionality for find ride
int Controller::testFindRide()
{


    RideShare rideShare;


    initRideShare(rideShare);


    int outof = 4;


    int score = 0;



    vector<string> custIds = {"C1", "C2", "C3", "C4"};



    vector<string> driverNames = {"Carter", "Elsa", "Elsa", "Densel"}; 




    for (int i = 0; i < custIds.size(); ++i)
    {


        string custId = custIds[i];


        Customer* c = rideShare.getCustomer(custId);



        if (c == nullptr)
        {


            cout<<"Customer "<<custId<<" not found"<<endl;


            continue;


        }


        //this will both refresh and display the map
        view.refreshMap();


        rideShare.draw(view);


        view.displayMap();


        cout<<"Finding ride for customer "<<endl;


        c->print();
        



        int rating = c->getRating();


        Size size = small;


        Location loc = c->getLocation();


        Driver* d = rideShare.findRide(rating, size, loc);


        if (d == nullptr)
        {


            cout<<"No driver found for customer "<<custId<<endl;


            continue;


        }



        cout<<"Driver "<<d->getName()<<" found for customer "<<custId<<endl;



        if (d->getName() == driverNames[i])
        {


            cout<<"Correct driver found"<<endl;


            score++;



        } 


        else 
        {


            cout<<"Incorrect driver found"<<endl;


        }


    }



    cout<<"Score: "<<score<<"/"<<outof<<endl;


    return 0;


}



//this will initialize the system for RideShare by giving the default 
//drivers and customers
void Controller::initRideShare()
{

    

    rideShare.addDriver("Elsa", medium, 5, Location(3,4));

    rideShare.addDriver("Densel", small, 4, Location(1,1));

    rideShare.addDriver("Carter", large, 3, Location(5,4));

    rideShare.addDriver("Bob", small, 4, Location(2, 2));

    rideShare.addDriver("Alice", medium, 5, Location(7, 7));



    rideShare.addCustomer("Sally", 2, Location(5, 5));

    rideShare.addCustomer("Jesse", 5, Location(3, 7));

    rideShare.addCustomer("Isabelle", 4, Location(4, 5));

    rideShare.addCustomer("Philip", 3, Location(1, 7));


    
}



//this is the overloaded method which is used for initializing
//the system for RideShare by using a specific amount of data
void Controller::initRideShare(RideShare& rideShare)
{

    
    Customer::resetNextId();

    Driver::resetNextId();



    rideShare.addDriver("Elsa", medium, 5, Location(3,4));

    rideShare.addDriver("Densel", small, 4, Location(1,1));

    rideShare.addDriver("Carter", large, 2, Location(5,4));

    rideShare.addDriver("Bob", small, 4, Location(2, 2));

    rideShare.addDriver("Alice", medium, 5, Location(7, 7));



    rideShare.addCustomer("Sally", 2, Location(5, 5));

    rideShare.addCustomer("Jesse", 5, Location(3, 7));

    rideShare.addCustomer("Isabelle", 4, Location(4, 5));

    rideShare.addCustomer("Philip", 3, Location(1, 7));


    
}



//this is the overloaded method which is used to be initialized in the system
//for Rideshare with the custome data being used
void Controller::initRideShare(RideShare& rideShare,
    vector<string> driverNames,

    vector<Size> driverSizes,

    vector<int> driverRatings,

    vector<Location> driverLocations,

     vector<string> customers,

     vector<int> customerRatings,

     vector<Location> customerLocations){
    


    Customer::resetNextId();

    Driver::resetNextId();


    
    for (int i = 0; i < driverNames.size(); ++i)
    {

        rideShare.addDriver(driverNames[i], driverSizes[i], driverRatings[i], driverLocations[i]);


    }


    for (int i = 0; i < customers.size(); ++i)
    {

        rideShare.addCustomer(customers[i], customerRatings[i], customerLocations[i]);


    }

    
}