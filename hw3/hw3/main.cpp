#include <iostream>
using namespace std;
#include "SimplePerson.h"
#include "SimplePhoneBook.h"

int main()
{
    PhoneBook p;
    PhoneBook p2;
    p.displayPeople();
    bool b = p.addPerson("WArraich");
    b = p.addPerson("hassan");
     b = p.addPerson("WArraich");
    p.displayPeople();
    b = p.removePerson("warraich");
    b = p.removePerson("war");
    p2 = p;
    p.displayPeople();
    p2.displayPeople();
    b = p.removePerson("hassan");
    p.displayPeople();

}
