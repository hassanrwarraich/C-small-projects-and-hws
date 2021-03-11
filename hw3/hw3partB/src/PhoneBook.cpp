#include "PhoneBook.h"
#include "Phone.h"
#include <string>
#include <iostream>
using namespace std;
#include <algorithm>
#include <cctype>

PhoneBook::PhoneBook()
{
    head = NULL;
    numberOfPeople = 0;
}

PhoneBook::~PhoneBook()
{
    while(head != NULL)
    {
        Node *cur;
        cur = head;
        head = head->next;
        cur->next = NULL;
        delete cur;
        cur = NULL;
    }
}

PhoneBook::PhoneBook( const PhoneBook& systemToCopy )
{
    numberOfPeople = systemToCopy.numberOfPeople;
    if (systemToCopy.head == NULL)
      head = NULL;
    else {
      head = new Node;
      head->t = systemToCopy.head->t;
      Node *newPtr = head;
      for (Node *origPtr = systemToCopy.head->next; origPtr != NULL; origPtr = origPtr->next){
         newPtr->next = new Node;
         newPtr = newPtr->next;
         newPtr->t = origPtr->t;
      }
      newPtr->next = NULL;
   }
}

void PhoneBook::operator=( const PhoneBook &right )
{
    Node *cur2;
    cur2 = right.head;
    Node *cur3;
    cur3 = right.head;
    if (right.head == NULL)
    {
         while(head != NULL)
        {
            Node *cur;
            cur = head;
            head = head->next;
            cur->next = NULL;
            cur = NULL;
            delete cur;
        }
    }
    else
    {
        while(head != NULL)
        {
            Node *cur;
            cur = head;
            head = head->next;
            cur->next = NULL;
            cur = NULL;
            delete cur;
        }
        while(cur2 != NULL)
        {
            bool a = addPerson(cur2->t.getName());
            cur2 = cur2->next;
        }

        Node* moving;
        moving = head;
        while(head != NULL)
        {
            moving->t = cur3->t;
        }
        moving = NULL;
        delete moving;
    }
    cur2 = NULL;
    cur3 = NULL;
    delete cur2;
    delete cur3;
}

bool PhoneBook::addPerson( string name )
{
    string nam = name;
    transform(nam.begin(), nam.end(), nam.begin(), ::tolower);
    Node *cur;
    cur = head;
    while (cur != NULL)
    {
        string nam2 = cur->t.getName();
        transform(nam2.begin(), nam2.end(), nam2.begin(), ::tolower);
        if (nam2 == nam)
        {
            cout<<"name already exists"<<endl;
            cur = NULL;
            delete cur;
            return false;
        }
        else {
            cur = cur->next;
        }
    }
    Node *cur2;
    cur2 = head;
    Person a(name);
    Node* temp = new Node();
    temp->t = a;
    if(cur2 == NULL)
        head = temp;
    else {
        while (cur2->next != NULL)
            cur2 = cur2->next;
        cur2->next = temp;
    }
    temp->next = NULL;
    temp = NULL;
    cur = NULL;
    cur2 = NULL;
    delete cur2;
    delete cur;
    delete temp;
    return true;
}

bool PhoneBook::removePerson( string name )
{
    Node *cur;
    cur = head;
    string nam = name;
    transform(nam.begin(), nam.end(), nam.begin(), ::tolower);
    if (cur != NULL)
    {
        string nam2 = cur->t.getName();
        transform(nam2.begin(), nam2.end(), nam2.begin(), ::tolower);
        if (nam2 == nam)
        {
            head = head->next;
            cur = NULL;
            delete cur;
            return true;
        }
        while (cur->next != NULL)
        {
            string nam2 = cur->next->t.getName();
            transform(nam2.begin(), nam2.end(), nam2.begin(), ::tolower);
            if (nam2 == nam)
            {
                Node *prev;
                prev = findPerson(name);
                cur->next = prev->next;
                prev->next = NULL;
                cur = NULL;
                delete cur;
                prev = NULL;
                delete prev;
                return true;
            }
            else {
                cur = cur->next;
            }
        }
    }
    cout<<"name not found"<<endl;
    cur = NULL;
    delete cur;
    return false;
}

bool PhoneBook::addPhone( string personName, int areaCode, int number )
{
    Node *req;
    req = findPerson(personName);
    if (req != NULL)
    {
        req->t.addPhone(areaCode, number);
    }
    req = NULL;
    delete req;
    return false;
}

bool PhoneBook::removePhone( string personName, int areaCode, int number )
{
    Node *req;
    req = findPerson(personName);
    if (req != NULL)
    {
        req->t.removePhone(areaCode, number);
    }
    req = NULL;
    delete req;
    return false;
}

void PhoneBook::displayPerson( string name )
{
    Node *cur;
    cur = NULL;
    cur = findPerson(name);
    if (cur != NULL)
    {
        cout<<name<<endl;
        cur->t.displayPhoneNumbers();
    }
    else
        cout<<"--Empty--"<<endl;
    cur = NULL;
    delete cur;
}

void PhoneBook::displayAreaCode( int areaCode )
{
    Node *cur;
    cur = head;
    int i = 0;
    cout<<"area Code: "<<areaCode<<endl;
    while (cur != NULL)
    {
        if (cur->t.isEmpty(areaCode))
        {}
        else
        {
            cout<<cur->t.getName()<<endl;
            cur->t.displayAreaCode(areaCode);
            i = 1;
        }
        cur = cur->next;
    }
    if (i == 0)
        cout<<"--Empty--"<<endl;
    cur = NULL;
    delete cur;
}

void PhoneBook::displayPeople()
{
    Node *cur;
    cur = head;
    if (cur == NULL)
        cout<<"empty"<<endl;
    while (cur != NULL)
    {
        cout<<cur->t.getName()<<"  "<<cur->t.noPhone()<<endl;
        cur = cur->next;
    }
    cur = NULL;
    delete cur;
}

PhoneBook::Node* PhoneBook::findPerson( string name )
{
    Node *cur;
    cur = head;
    string nam = name;
    transform(nam.begin(), nam.end(), nam.begin(), ::tolower);
    while (cur != NULL)
    {
        string nam2 = cur->t.getName();
        transform(nam2.begin(), nam2.end(), nam2.begin(), ::tolower);
        if (nam2 == nam )
        {
           return cur;
        }
        else {
            cur = cur->next;
        }
    }
    return NULL;
}
