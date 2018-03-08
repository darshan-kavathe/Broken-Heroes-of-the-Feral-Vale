//
// Created by Darshan on 3/1/2018.
//
#include "queue.h"
using std::deque;

template<typename T>
util::Queue<T>::Queue(){
    //Create an empty queue.
}
/*
template<typename T>
virtual Queue< T >::~Queue(){
}
*/
template<typename T>
unsigned long util::Queue<T>::size()	const{
    //Get the number of elements in the queue.
    //Returns :size
    return q.size();
}

template<typename T>
void util::Queue<T>::add	(T 	element	){
    //Add an element to the back of the queue.
    //Parameters: element	new element
    q.push_back(element);
}

template<typename T>
T& util::Queue<T>::front(){
    // Peek at the front element.
    // Returns front element
    return q.front();
}

template<typename T>
T util::Queue<T>::remove(){
    //Remove and return the front element.
    // Remove the element
    T temp = q.front();
    q.pop_front();
}

template<typename T>
deque<T>& util::Queue<T>::get_elements(){
    // Get all the elements.
    // returns all elements.
    return q;
}

template<typename T>
const deque<T>& util::Queue<T>::get_elements()const{
    // Get all the elements.
    // returns all elements.
    return q;
}