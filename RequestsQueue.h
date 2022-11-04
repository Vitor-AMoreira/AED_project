//
// Created by victo on 03/11/2022.
//

#ifndef AED_PROJECT_REQUESTSQUEUE_H
#define AED_PROJECT_REQUESTSQUEUE_H
#include <queue>
#include <fstream>
#include "Request.h"
#include "StudentsTree.h"

class RequestsQueue {
    private :
        queue<Request> requestsQueue;
        StudentsTree tree;
        ReadClasses readClasses;
    public :
        RequestsQueue(StudentsTree &tree, ReadClasses &readClasses);
        void pop();
        void push(Request request);
        void upload(); //Write all the requests in the queue to a file in csv extension
        void download(); //Get all the requests in the file and transfer to the queue

        int getSize();
};

#endif //AED_PROJECT_REQUESTSQUEUE_H
