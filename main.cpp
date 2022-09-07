//
//  main.cpp
//  week_6
//
//  Created by Ragupathi on 06/09/2022.
//
/*
 Write a C++ program to perform insert, delete, display, and search operations on a circular linked list. The insertion and deletion can happen in the beginning, end, or anywhere in between. Utilize function overloading wherever necessary (At least for 2 different operations). Maintain proper boundary conditions and code modularly. The menu for the program is,

 Insert
 Delete
 Search
 Display
 Exit
 */


#include <iostream>
using namespace std;
class node{
private:
    int data;
    node *next;
    
public:
    //the last pointer will point to the last element
    //last next would be head;
    node *last = NULL, *head = NULL;
    node * newnode(int data){
        node * newNode = new node;
        newNode->data = data;
        newNode->next = NULL;
        return newNode;
    }
    //insert at end
    void insert(int data){
        node *newNode = newnode(data);
        if(head == NULL){
            head = last = newNode;
        }
        else{
            newNode->next = head;
            last->next = newNode;
            last = newNode;
        }
    }
    //insert at head
    void insert_head(int data){
        node *newNode = newnode(data);
        if(head == NULL){
            head = last = newNode;
        }
        else{
        newNode->next = head;
        last->next = newNode;
        head = newNode;
        }
    }
    int length(){
        node *temp = head;
        int len = 0;
        if(head == NULL){
            return len;
        }
        else{
            len++;
            temp = temp->next;
            while(temp != head){
                len++;
                temp = temp->next;
            }
            //cout << len << endl;
            
        }
        return len;
    }
    //insert at k
    //boundary conditions
    void insert(int data, int pos){
        int size = length(), k =pos;
        
        if(k == 1){
            insert_head(data);
        }
        else if(size+1 == k){
            insert(data);
        }
        else if(k > size+1){
            cout << "\nposition doesn't exist\n";
        }
        else{
        node *newNode = newnode(data), *temp = head;
        int i=0;
        while(temp->next != head && i < k-2){
            temp = temp->next;
            i++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        }
    }
    //delete at head
    void deletion_head(){
        node *temp =head;
        cout << "\ndata to be deleted " << temp->data << endl;
        head = head->next;
        last->next = head;
        delete temp;
    }
    
    //delete at end
    void deletion(){
        node *temp = head;
        while(temp->next != last){
            temp = temp->next;
        }
        cout << "\ndata to be deleted " << temp->next->data << endl;
        temp->next = last->next;
        last = temp;
        temp = temp->next;
        delete temp;
    }
    
    //deletion at k
    void deletion(int pos){
        int size = length(), k = pos;
        if(k == 1){
            deletion_head();
        }
        else if(size == k){
            deletion();
        }
        else if(k > size){
            cout << "\nposition doesn't exist\n";
        }
        else{
            node *temp = head;
            int i=0;
            while(temp->next != head && i<k-2){
                temp= temp->next;
                i++;
            }
            cout << "\ndata to be deleted " << temp->next->data << endl;
            temp->next = temp->next->next;
            delete temp;
            
        }
    }
    
    void search(int data){
        node *temp = head;
        int count = 1, len = length();
        if(temp->data == data){
            cout << "\n " << data << " is present at head" << endl;
        }
        else if(last->data == data){
            cout << "\n " << data << " is present at the tail" << endl;
        }
        else{
            temp = temp->next;
            while(temp->next != head){
                if(temp->data == data){
                    cout << "\n " << data << " is present at " << count+1 << " position" << endl;
                    break;
                }
                count++;
                temp = temp->next;
            }
            if(count == len-1){
                cout << "\n " << data << " is not present in the list"<< endl;
            }
        }
    }
    
    void display(){
        node *temp = head;
        cout << temp->data << " ";
        temp = temp->next;
        while(temp != head){
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    
    
};

int main(){
    node CLL;
    int choice = 6, element, option, pos;
    cout << "\nCircular Singly Linked List\n";
    while(choice != 5){
        cout << "\nTo insert: press 1\nTo delete: press 2\nTo Search: press 3\nTo Display: press 4\nTo Exit: press 5\n";
        cin >> choice;
        switch(choice){
            case 1:
                cout << "\nFor insertion press:\n1 for insertion at head\n2 for insertion at end\n3 for insertion at k-th position" << endl;
                cin >> option;
                if(option == 1){
                    cout << "\nplease enter the value of the element: ";
                    cin >> element;
                    CLL.insert_head(element);
                    break;
                }
                else if(option == 2){
                    cout << "\nplease enter the value of the element: ";
                    cin >> element;
                    CLL.insert(element);
                    break;
                }
                else if(option == 3){
                    cout << "\nplease enter the value of the element: ";
                    cin >> element;
                    cout << "\nplease enter the position: ";
                    cin >> pos;
                    CLL.insert(element, pos);
                    break;
                }
                else{
                    cout << "\nplease enter a valid choice\n";
                    break;
                }
                
            case 2:
                cout << "\nFor deletion press:\n1 for deletion at head\n2 for deletion at end\n3 for deletion at k-th position" << endl;
                cin >> option;
                if(option == 1){
                    CLL.deletion_head();
                    break;
                }
                else if(option == 2){
                    CLL.deletion();
                    break;
                }
                else if(option == 3){
                    cout << "\nplease enter the position: ";
                    cin >> pos;
                    CLL.deletion(pos);
                    break;
                }
                else{
                    cout << "\nplease enter a valid choice\n";
                    break;
                }
                
            case 3:
                cout << "\nFor searching, please enter the value: ";
                cin >> element;
                CLL.search(element);
                break;
                
            case 4:
                cout << "\n List: ";
                CLL.display();
                break;
            case 5:
                cout << "\nyou've successfully exited the program :)\n";
                break;
                
            default:
                cout << "\nplease enter a valid choice\n";
                break;
        }
    }
    
    return 0;
}
