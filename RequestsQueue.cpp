//
// Created by victo on 03/11/2022.
//

#include "RequestsQueue.h"

RequestsQueue::RequestsQueue(StudentsTree &tree, ReadClasses &readClasses){
    this->tree = tree;
    this->readClasses = readClasses;
}

//Introducing a request in the queue
void RequestsQueue::push(Request request){
    requestsQueue.push(request);
}

//Popping the request of the queue, and realizing it
void RequestsQueue::pop(){

    if(!requestsQueue.empty()){

        Request request = requestsQueue.front();

        requestsQueue.pop();

        //To print what request is being executed
        if(request.getAction() == "A") {
            cout << "\nThe class " << request.getUcCode() << "-" << request.getClassCode() << " was added to the student " << request.getStudentCode() << endl;
        } else if (request.getAction() == "R") {
            cout << "\nThe class " << request.getUcCode() << "-" << request.getClassCode() << " was removed from the student " << request.getStudentCode() << endl;
        }

        StudentsTree::node *temp = tree.findByCode(tree.head, request.getStudentCode());
        Class *c = readClasses.findClass(request.getUcCode(),request.getClassCode());

        if(request.getAction() == "A"){
           temp->student.pushClass(c);

        }else if(request.getAction() == "R"){
            temp->student.removeClass(c);

        }

    } else {
        cout << "!!! THE QUEUE OF REQUESTS IS ALREADY EMPTY !!!" << endl;
    }
}

void RequestsQueue::upload(){
    ofstream out;
    out.open("../schedule/queueValues.csv", ios_base::app);

    while(!requestsQueue.empty()){
        Request request = requestsQueue.front();
        requestsQueue.pop();
            out << request.getAction() << ";"
            << request.getStudentCode() << ";"
            << request.getUcCode() << ";"
            << request.getClassCode() << "\n";
    }
    out.close();
}

void RequestsQueue::download() {
    Request request;

    ifstream file("../schedule/queueValues.csv");
    string line;
    string field;
    string delimiter = ";";

    vector<string> array_of_fields;

    while (getline(file, line)) {
        int pos = 0;

        while ((pos = line.find(delimiter)) != string::npos) {
            field = line.substr(0, pos);
            array_of_fields.push_back(field);
            line.erase(0, pos + delimiter.length());
            if (line.find(delimiter) == string::npos) array_of_fields.push_back(line.substr(0, pos));
        }
        request = Request(array_of_fields[0], array_of_fields[1],array_of_fields[2],array_of_fields[3]);
        push(request);
        array_of_fields.clear();
    }
    file.close();

    //Erase all the content that was passed to the queue
    ofstream out("../schedule/queueValues.csv");
    out << "";
    out.close();
}

int RequestsQueue::getSize() {
    return requestsQueue.size();
}
