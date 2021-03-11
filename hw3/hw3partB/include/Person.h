#ifndef __PERSON_H
#define __PERSON_H
#include <string>
using namespace std;
#include "Phone.h"
class Person{
public:
Person( const string name = "" );
~Person();
Person( const Person& personToCopy );
void operator=( const Person &right );
string getName();
bool addPhone( const int areaCode, const int number );
bool removePhone( const int areaCode, const int number );
void displayPhoneNumbers();
void displayAreaCode(const int areaCode);
bool isEmpty(const int areaCode);
int noPhone();
private:
struct PhoneNode {
Phone p;
PhoneNode* next;
};
PhoneNode *head;
string name;
PhoneNode* findPhone( const int areaCode, const int number );
};
#endif
