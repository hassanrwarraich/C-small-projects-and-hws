#include "SimplePerson.h"
#include "SimplePhoneBook.h"
#include <iostream>
#include <algorithm>
#include <cctype>
using namespace std;

PhoneBook::PhoneBook()
{
    numberOfPeople = 0;
    head = NULL;
}

PhoneBook::~PhoneBook()
{
    while(head != NULL)
    {
        PersonNode *cur;
        cur = head;
        head = head->next;
        cur->next = NULL;
        delete cur;
        cur = NULL;
    }
}

PhoneBook::PhoneBook (const PhoneBook& phoneBookToCopy)
{
    numberOfPeople = phoneBookToCopy.numberOfPeople;
    if (phoneBookToCopy.head == NULL)
      head = NULL;
    else {
      head = new PersonNode;
      head->t = phoneBookToCopy.head->t;
      PersonNode *newPtr = head;
      for (PersonNode *origPtr = phoneBookToCopy.head->next; origPtr != NULL; origPtr = origPtr->next){
         newPtr->next = new PersonNode;
         newPtr = newPtr->next;
         newPtr->t = origPtr->t;
      }
      newPtr->next = NULL;
   }
}

void PhoneBook::operator=(const PhoneBook& right)
{
    PersonNode *cur1;
    cur1 = head;
    PersonNode *cur2;
    cur2 = right.head;

    if (right.head == NULL)
    {
        while(head != NULL)
        {
            PersonNode *aa;
            aa = head;
            head = head->next;
            aa->next = NULL;
            delete aa;
        }
    }

    else {
            if(numberOfPeople < right.numberOfPeople)
            {
                for (int i = 1; i <= numberOfPeople; i++)
                {
                    cur1->t = cur2->t;
                    if (cur1->next != NULL)
                    {
                        cur1 = cur1->next;
                        cur2 = cur2->next;
                    }
                }
                for (int i = 0; i < right.numberOfPeople - numberOfPeople; i++)
                {
                    Person p(cur2->t.getName());
                    PersonNode* temp = new PersonNode();
                    temp->t = p;
                    if (cur1 == NULL)
                    {
                        cur1 = temp;
                    }
                    else
                    {
                        cur1 = cur1->next;
                        cur1 = temp;
                    }
                    temp->next = NULL;
                    cur1 = cur1->next;
                    cur2 = cur2->next;
                    temp = NULL;
                    delete temp;
                }
            }
            else {
                if (numberOfPeople >= right.numberOfPeople)
                {
                    for (int i = 1; i <= numberOfPeople; i++)
                    {
                        cur1->t = cur2->t;
                        if (cur1->next != NULL)
                        {
                            cur1 = cur1->next;
                            cur2 = cur2->next;
                        }
                    }
                    cur1 = cur1->next;
                    while (cur1 != NULL)
                    {
                        PersonNode *now;
                        now = cur1;
                        cur1 = cur1->next;
                        now->next = NULL;
                        now = NULL;
                        delete now;
                    }
                }
            }
    }
    numberOfPeople = right.numberOfPeople;
    cur1 = NULL;
    cur2 = NULL;
    delete cur1;
    delete cur2;
}

bool PhoneBook::addPerson(string name)
{
    PersonNode *cur;
    cur = head;
    string nam = name;
    transform(nam.begin(), nam.end(), nam.begin(), ::tolower);
    if (cur != NULL)
    {
        while (cur->next != NULL)
        {
            if (cur != NULL)
            {
                string nam2 = cur->t.getName();
                transform(nam2.begin(), nam2.end(), nam2.begin(), ::tolower);
                if (nam2 == nam)
                {
                    cur = NULL;
                    delete cur;
                    return false;
                }
                cur =cur->next;
            }
        }
        string nam2 = cur->t.getName();
        transform(nam2.begin(), nam2.end(), nam2.begin(), ::tolower);
        if (nam2 == nam)
        {
            cur = NULL;
            delete cur;
            return false;
        }
    }
    Person p(name);
    PersonNode* temp = new PersonNode();
    temp->t = p;
    if(cur == NULL)
        head = temp;
    else
        cur->next = temp;
    cur = NULL;
    delete cur;
    temp = NULL;
    delete temp;
    numberOfPeople++;
    return true;
}


bool PhoneBook::removePerson(string name)
{
    if (numberOfPeople == 0)
        return false;
    PersonNode *cur;
    cur = head;
    string nam = name;
    transform(nam.begin(), nam.end(), nam.begin(), ::tolower);
    string nam2 = cur->t.getName();
    transform(nam2.begin(), nam2.end(), nam2.begin(), ::tolower);
    if (nam2 == nam)
    {
        head = head->next;
        cur = NULL;
        delete cur;
        numberOfPeople--;
        return true;
    }
   while (cur->next != NULL)
   {
        string nam2 = cur->next->t.getName();
        transform(nam2.begin(), nam2.end(), nam2.begin(), ::tolower);
        if (nam2 == nam)
        {
           PersonNode *prev = findPerson(name);
           cur->next = prev->next;
           cur = NULL;
           delete cur;
           numberOfPeople--;
           prev->next = NULL;
           prev = NULL;
           delete prev;
           return true;
        }
        else {
            cur = cur->next;
        }
   }
   cur = NULL;
   delete cur;
   return false;
}

void PhoneBook::displayPeople()
{
    PersonNode *cur;
    cur = head;
    if(numberOfPeople != 0)
    {
        for(int i = 0; i < numberOfPeople; i++)
        {
            if (cur != NULL)
            {
                cout<<"Person " << cur->t.getName() <<endl;
                cur = cur->next;
            }
        }
    }
    else{
        cout<<"--EMPTY--"<<endl;
    }
    delete cur;
    cur = NULL;
}

PhoneBook::PersonNode* PhoneBook::findPerson(string name)
{
    PersonNode *cur;
    cur = head;
    string nam = name;
    transform(nam.begin(), nam.end(), nam.begin(), ::tolower);
    string nam2 = cur->t.getName();
    transform(nam2.begin(), nam2.end(), nam2.begin(), ::tolower);
    if (nam2 == nam)
    {
        return cur;
    }
    for (int i = 0; i < numberOfPeople - 1; i++)
    {
        string nam2 = cur->t.getName();
        transform(nam2.begin(), nam2.end(), nam2.begin(), ::tolower);
        if (nam2 == nam)
        {
           return cur->next;
        }
        else {
            cur = cur->next;
        }
    }
    return NULL;
}
