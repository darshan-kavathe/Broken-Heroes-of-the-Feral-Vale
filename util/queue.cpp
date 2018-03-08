//
// Created by Darshan on 3/1/2018.
//
#include "queue.h"
Queue::Queue(){
    //Create an empty queue.

}
virtual util::Queue< T >::~Queue(){
    //Destructor

}
unsigned long util::Queue::size()	const{
    //Get the number of elements in the queue.
    //Returns :size

}
void util::Queue::add	(T 	element	){
    //Add an element to the back of the queue.
    //Parameters: element	new element

}
T & util::Queue::front(){
    // Peek at the front element.
    // Returns front element
}
T util::Queue::remove(){
    //Remove and return the front element.
    // Remove the element

}
deque< T > & util::Queue::get_elements(){
    // Get all the elements.
    // returns all elements.

}
const deque< T > & util::Queue::get_elements()const{
    // Get all the elements.
    // returns all elements.

}