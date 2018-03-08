//
// Created by darsh on 3/1/2018.
//

#ifndef PROJECT_1_QUEUE_H
#define PROJECT_1_QUEUE_H

namespace util {
    template<typename T>
    class util::Queue<T> {
    public:
        //Create an empty queue.
        Queue();

        //Destructor
        virtual util::Queue<T>::~Queue();

        unsigned long size() const;

        void add(T element);

        T &front();

        T remove();

        deque <T> &get_elements();

        const deque <T> &get_elements() const;

    private:
        unsigned long size_;
    };
}
#endif //PROJECT_1_QUEUE_H
