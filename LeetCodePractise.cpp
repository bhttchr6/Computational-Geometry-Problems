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

int main(){


    // initializing digits on stack memory 

    // number 1
    Node num1Digit1{1};
    Node num1Digit2{2, &num1Digit1};
    Node num1Digit3{3, &num1Digit2};


    //number 2
    Node num2Digit1{4};
    Node num2Digit2{5, &num2Digit1};
    Node num2Digit3{6, &num2Digit2};


    

    // define a vector 
    std::vector<Node*> linkedList;

    linkedList.push_back(&num1Digit3);
    linkedList.push_back(&num2Digit3);

    // 
    int sumdigit1{0}, sumdigit2{0}, sumdigit3{0};

    for(int i = 0; i<linkedList.size(); ++i){

        // define the head
        Node* head = linkedList[i];
        int ctr = 0;
        while(head!=nullptr){

            ctr = ctr + 1;
            std::cout << head->val;
            

            switch (ctr)
            {
            case 1:
               sumdigit1 = sumdigit1 + head->val;
               break;
            case 2:
               sumdigit2 = sumdigit2 + head->val;
               break;
            case 3:
               sumdigit3 = sumdigit3 + head->val;
               break;
            
            }

            head = head->next;
        }
        
        std::cout << std::endl;
    }

    std:: cout << sumdigit1 << sumdigit2 << sumdigit3;


    
    return 0;
}

