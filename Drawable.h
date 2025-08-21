#ifndef DRAWABLE_H

#define DRAWABLE_H



#include "View.h"



class Drawable 
{


public:


    //this will initialize the drawing layer for drawable
    Drawable(int layer);


    //this is te virtual destructor to make sure there is
    //good cleanup for the classes
    virtual ~Drawable() {}



    //this will be used for defining how you are supposed to draw the object
    virtual void draw(View& view) = 0;



protected:


    //this is for drawing the layer for the object that is drawable
    int layer;



};


#endif // DRAWABLE_H
