#include <iostream>
using namespace std;
#include "Person.h"


Person::Person( const string name)
{
    head = NULL;
    this->name = name;
}

Person::~Person()
{
    while(head != NULL)
    {
        PhoneNode *cur;
        cur = head;
        head = head->next;
        cur->next = NULL;
        delete cur;
        cur = NULL;
    }
}

Person::Person( const Person& personToCopy )
{
    name = personToCopy.name;
    if (personToCopy.head == NULL)
      head = NULL;
    else {
      head = new PhoneNode;
      head->p = personToCopy.head->p;
      PhoneNode *newPtr = head;
      for (PhoneNode *origPtr = personToCopy.head->next; origPtr != NULL; origPtr = origPtr->next){
         newPtr->next = new PhoneNode;
         newPtr = newPtr->next;
         newPtr->p = origPtr->p;
      }
      newPtr->next = NULL;
   }
}

void Person::operator=( const Person &right )
{
    PhoneNode *cur2;
    cur2 = right.head;
    if (right.head == NULL)
    {
        while(head != NULL)
        {
            PhoneNode *cur;
            cur = head;
            head = head->next;
            cur->next = NULL;
            cur = NULL;
            delete cur;
        }
    }

    else {
        while(head != NULL)
        {
            PhoneNode *cur;
            cur = head;
            head = head->next;
            cur->next = NULL;
            cur = NULL;
            delete cur;
        }
        while(cur2 != NULL)
        {
            bool b = addPhone(cur2->p.getAreaCode(), cur2->p.getNumber());
            cur2 = cur2->next;
        }

    }
    name = right.name;
    cur2 = NULL;
    delete cur2;
}

string Person::getName()
{
    return name;
}

bool Person::addPhone( const int areaCode, const int number )
{
    PhoneNode *cur;
    cur = head;
    while (cur != NULL)
    {
        if (cur->p.getAreaCode() == areaCode && cur->p.getNumber() == number)
        {
            cout<<"number already exists"<<endl;
            cur = NULL;
            delete cur;
            return false;
        }
        else {
            cur = cur->next;
        }
    }
    cur = head;
    Phone a(areaCode, number);
    PhoneNode* temp = new PhoneNode();
    temp->p = a;
    if(cur == NULL)
        head = temp;
    else {
        while (cur->next != NULL)
            cur = cur->next;
        cur->next = temp;
    }
    temp->next = NULL;
    temp = NULL;
    cur = NULL;
    delete cur;
    delete temp;
    return true;
}

bool Person::removePhone( const int areaCode, const int number )
{
    PhoneNode *cur;
    cur = head;
    if (cur != NULL)
    {
        if (cur->p.getAreaCode() == areaCode && cur->p.getNumber() == number)
        {
            head = head->next;
            cur = NULL;
            delete cur;
            return true;
        }


        while (cur->next != NULL)
        {
            if (cur->next->p.getAreaCode() == areaCode && cur->next->p.getNumber() == number)
            {
                PhoneNode *prev = findPhone(areaCode, number);
                cur->next = prev->next;
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
    cur = NULL;
    delete cur;
    cout<<"number not found"<<endl;
    return false;
}

void Person::displayPhoneNumbers()
{
    PhoneNode *cur;
    cur = head;
    int gg = 0;
    while (cur !=NULL)
    {
        cout<<"Phone number: " << cur->p.getAreaCode() <<" "<< cur->p.getNumber() <<endl;
        cur = cur->next;
        gg++;
    }
    if (gg == 0)
    {
        cout<<"--EMPTY--"<<endl;
    }
    cur = NULL;
    delete cur;
}

Person::PhoneNode* Person::findPhone( const int areaCode, const int number )
{
    PhoneNode *cur;
    cur = head;
    while (cur != NULL)
    {
        if (cur->p.getAreaCode() == areaCode && cur->p.getNumber() == number)
        {
           return cur;
        }
        else {
            cur = cur->next;
        }
    }
    cur = NULL;
    delete cur;
    return NULL;
}

void Person::displayAreaCode(const int areaCode)
{
    PhoneNode *cur;
    cur = head;
    int pos;
    pos = 0;
    while (cur != NULL)
    {
        if (cur->p.getAreaCode() == areaCode)
        {
            cout<<"Phone Number: "<< cur->p.getAreaCode()<<" "<< cur->p.getNumber()<<endl;
            pos = 1;
        }
        cur = cur->next;
    }
    cur = NULL;
    delete cur;

}

bool Person::isEmpty(int areaCode)
{
    PhoneNode *cur;
    cur = head;
    if(head == NULL)
        return true;
    else
    {
        while (cur != NULL)
        {
            if (cur->p.getAreaCode() == areaCode)
                return false;
            cur= cur->next;
        }
    }
    cur = NULL;
    delete cur;
    return true;
}

int Person::noPhone()
{
    PhoneNode *cur;
    cur = head;
    int i;
    i = 0;
    while(cur != NULL)
    {
        i = i + 1;
        cur = cur->next;
    }
    cur = NULL;
    delete cur;
    return i;
}
