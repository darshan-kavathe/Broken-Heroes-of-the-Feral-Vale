//
// Created by darsh on 3/1/2018.
//

#ifndef PROJECT_1_QUEUE_H
#define PROJECT_1_QUEUE_H

#include <deque>

using std::deque;

namespace util {
    template<typename T>
    class Queue {
    public:
        //Create an empty queue.
        Queue();

        //Destructor
        virtual ~Queue();

        //Get the number of elements in the queue.
        //Returns :size
        unsigned long size() const;

        //Add an element to the back of the queue.
        //Parameters: element	new element
        void add(T element);

        // Peek at the front element.
        // Returns front element
        T &front();

        //Remove and return the front element.
        // Remove the elements
        T remove();

        // Get all the elements.
        // returns all elements
        deque<T>& get_elements();

        // Get all the elements.
        // returns all elements
        const deque<T>& get_elements() const;

    private:
        //unsigned long size_;
        deque<T> q;
    };
}

#endif //PROJECT_1_QUEUE_H
