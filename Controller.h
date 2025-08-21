#ifndef CONTROLLER_H

#define CONTROLLER_H



#include <iostream>

#include <string>

#include "RideShare.h"

#include "View.h"



using namespace std;


class Controller 
{
		
	public:


		//this is the constructor
		Controller();


		//this is the destructor
		~Controller();


		//this will launch the loop in the main program
		void launch();


        //this will display the customer and drivers in the current mao
		void displayMap();


        //this will do the finding process for findRide
		void findRide();


        //this will test the map's display
		int testDisplayMap();


        //this will test the functionality for the ride
		int testFindRide();


	
	private:

	    //these are the initializers for when testing
		void initRideShare();

	
		void initRideShare(RideShare& rideshare);

		void initRideShare(RideShare& rideShare,

			vector<string> driverNames,

			vector<Size> driverSizes,

			vector<int> driverRatings,

			vector<Location> driverLocations,

			 vector<string> customers,

			 vector<int> customerRatings,

			 vector<Location> customerLocations);


		RideShare rideShare;

		View view;	

};


#endif