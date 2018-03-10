//
// Created by darsh on 3/1/2018.
//
#include "queue.h"
#include "../hero/hero.h"
//#include "../hero/hero.h"
#include <iostream>

using std::deque;
using namespace util;
template<typename T>
Queue<T>::Queue(){
    //Create an empty queue.
}

template<typename T>
Queue< T >::~Queue(){
}

template<typename T>
unsigned long Queue<T>::size()	const{
    //Get the number of elements in the queue.
    //Returns :size
    return q.size();
}

template<typename T>
void Queue<T>::add	(T 	element	){
    //Add an element to the back of the queue.
    //Parameters: element	new element
    q.push_back(element);
}

template<typename T>
T& Queue<T>::front(){
    // Peek at the front element.
    // Returns front element
    return q.front();
}

template<typename T>
T Queue<T>::remove(){
    //Remove and return the front element.
    // Remove the element
    T& temp = q.front();
    q.pop_front();
    return temp;
}

template<typename T>
deque<T>& Queue<T>::get_elements(){
    // Get all the elements.
    // returns all elements.
    return q;
}

template<typename T>
const deque<T>& Queue<T>::get_elements()const{
    // Get all the elements.
    // returns all elements.
    return q;
}

//template<typename T>
//util::Queue<T>::~Queue() {}

template class Queue<int>;
template class Queue<std::string>;
template class Queue<hero::Hero *>;


