#include <iostream>
using namespace std;
#include "PhoneBook.h"
#include "Person.h"
#include "Phone.h"

int main()
{
    PhoneBook p;
    bool b;
    b=p.addPerson("hassan");
    b=p.addPerson("Hassan");
    b=p.addPerson("warraich");
    b=p.addPhone("hassan",42,3570);
    b=p.addPhone("hassan",42,1420);
    cout<<"diplay person"<<endl;
    p.displayPerson("hassan");
    cout<<"diplay area code"<<endl;
    p.displayAreaCode(6842);
    cout<<"diplay peolpe"<<endl;
    p.displayPeople();
    b=p.removePhone("hassan",042,1420);
    b=p.removePerson("warraich");
    cout<<"diplay person"<<endl;
    p.displayPerson("hassan");
    cout<<"diplay area"<<endl;
    p.displayAreaCode(542);

    cout<<"diplay people"<<endl;
    p.displayPeople();
    return 0;
}
