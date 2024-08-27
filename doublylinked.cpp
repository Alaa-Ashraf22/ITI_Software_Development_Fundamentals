#include <iostream>
using namespace std;
#ifndef NOOODE_H
#define NOOODE_H
#include "stddef.h"
class Node{
public:
    int data;
    Node* prev;
    Node* next;
    Node(int value) {
        data = value;
        prev = NULL;
        next = NULL;}};
    class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = NULL;
        rear = NULL;
    }
    void Enqueue(int data) {
        Node* newNode = new Node(data);
        if (rear == NULL) {
            front = newNode;
            rear = newNode;
        } else {
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }
        cout << data << endl;
    }
    int Dequeue() {
            Node* temp = front;
            int dequeuedData = temp->data;
            if (front == rear) {
                front = NULL;
                rear = NULL;
            } else {
                front = front->next;
                front->prev = NULL;
            }
            delete temp;
            cout << dequeuedData << endl;
            return dequeuedData;
        }
         void DisplayReverse() {
            Node* temp = rear;
            while (temp != NULL) {
                cout << temp->data <<"\t";
                temp = temp->prev;
            }
            cout << endl;
        }
    int GetFront() {
    return front->data;

    }
    void GetRear() {
        cout<<rear->data;
       /* int count = 0;
        Node* temp = front;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;*/

    }
};


#endif // NOOODE_H


int main()
{
 Queue C;

    C.Enqueue(10);
    C.Enqueue(20);
    C.Enqueue(30);

   /* cout << "Front element: " << queue.GetFront() << endl;
    cout << "Rear element: " << queue.GetRear() <<endl;*/

    C.DisplayReverse();

    C.Dequeue();
    C.DisplayReverse();

   // C.Dequeue();
    //C.Dequeue();
   // C.DisplayReverse();

    /*cout << "Front element: " << queue.GetFront() <<endl;*/
C.GetRear();

    return 0;
}
