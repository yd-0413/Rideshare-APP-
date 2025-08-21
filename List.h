#ifndef LIST_H

#define LIST_H



#include <iostream>

#include <string>

#include <iomanip>

#include <cstdlib>

#include "defs.h"




template <typename T>


class List 
{


public:


    //this is the constructor
    List(int (*compFunc)(T, T));



    //this is the destructor
    ~List();




    //this will add an element in its correct order
    void add(T t);




    //this will remove the element at its specified index
    T remove(int index);



    //this will get an element at its specified index
    T get(int index) const;




    //this will get the number of elements
    int getSize() const;




    //this will check if the list is full
    bool isFull() const;




    //this will clear the list
    void clear();




private:




    int numElements;




    T* elements;



    int (*compare)(T, T); 


};




//this is the constructor
template <typename T>



List<T>::List(int (*compFunc)(T, T))



    : compare(compFunc), numElements(0) 
    {



    elements = new T[MAX_ARRAY];

}






//this is the destructor
template <typename T>




List<T>::~List() 
{



    clear();



    delete[] elements;



}




//this will add a new element in the correct order
template <typename T>


void List<T>::add(T t) 
{


    if (numElements >= MAX_ARRAY) 
    {


        std::cerr << "List is full" << std::endl;


        exit(1);


    }


    int i = numElements - 1;



    //this will shift the elements to make room for the new element
    while (i >= 0 && compare(elements[i], t) > 0) 
    {

        elements[i + 1] = elements[i];


        --i;
    }


    elements[i + 1] = t;

    ++numElements;

}





//this will remove the element at its specified index
template <typename T>




T List<T>::remove(int index) 
{


    if (index < 0 || index >= numElements) 
    {



        std::cerr << "Index out of bounds" << std::endl;



        exit(1);


    }
    


    T temp = elements[index];



    //this will shift the elements to fill in the gap
    for (int i = index; i < numElements - 1; ++i) 
    {


        elements[i] = elements[i + 1];


    }



    --numElements;



    return temp;


}




//this will get an element at its specified index
template <typename T>


T List<T>::get(int index) const 
{



    if (index < 0 || index >= numElements) 
    {



        std::cerr << "Index out of bounds" << std::endl;



        exit(1);


    }


    return elements[index];

}




//this will get the number of elements
template <typename T>



int List<T>::getSize() const 
{


    return numElements;



}




//this will check if the list is full
template <typename T>



bool List<T>::isFull() const 
{


    return numElements >= MAX_ARRAY;



}



//this will clear the list
template <typename T>



void List<T>::clear() 
{

    

    //this will delete the elements after removal
    numElements = 0;


}



#endif // LIST_H
