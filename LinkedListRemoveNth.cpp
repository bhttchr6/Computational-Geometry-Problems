// Leet Code Practise Problems
#include <stdio.h>
#include <iostream>
#include <vector>

// Define a Node of a linkedlist

struct Node{

    int val;
    Node* next;

    //Constructors
    Node(): val{0}, next{nullptr}{}
    Node(int x): val{x}, next{nullptr}{}
    Node(int x, Node *next): val{x}, next{next} {}


};

class solution
{

    public:
    Node* removeNthFromEnd(Node* head, int n)
    {

        // first get the length of the linkedlist
        int listLength = 0; 
        int ctr = 0;
        int N = 0;
        Node* dummyHead = head;
        Node* dummy = new Node(0, head);

        while(dummyHead)
        {
            ++listLength;
            dummyHead = dummyHead->next;
        }

        
        std::cout << "Length of the linked list is " << listLength << std::endl;

        while(head)
        {
            N = listLength - ctr;

            if(N == n + 1)
            {
                head->next = (head->next)->next;
               
            }

            head = head->next;

            ++ctr;
        }

        return dummy->next;

    }

};