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

        unsigned long size() const;

        void add(T element);

        T &front();

        T remove();

        deque<T>& get_elements();

        const deque<T>& get_elements() const;

    private:
        //unsigned long size_;
        deque<T> q;
    };
}

#endif //PROJECT_1_QUEUE_H
