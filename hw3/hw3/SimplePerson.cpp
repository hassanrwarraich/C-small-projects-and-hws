#include "SimplePerson.h"
#include <iostream>
using namespace std;

Person::Person(string name )
{
    this->name = name;
}

Person::~Person()
{}

Person::Person (Person &personToCopy )
{
    name = personToCopy.name;
}

void Person::operator=( const Person &right )
{
    name = right.name;
}

string Person::getName()
{
    return name;
}
