#include "Person.h"
#include "Phone.h"
#include <iostream>
#include <string>


Person::Person( const string name )
{
    this->name = name;
    head = NULL;
    numberOfPhone = 0;
}

Person::~Person()
{
    PhoneNode* cur = head;
    while( cur != NULL)
    {
        cur = cur->next;
        delete head;
        head = cur;
    }
}

Person::Person( const Person& personToCopy )
{
    name = personToCopy.name;
    numberOfPhone = personToCopy.numberOfPhone;
    if( personToCopy.head != NULL )
    {
        PhoneNode* newP = new PhoneNode();
        newP->p = Phone(personToCopy.head->p.getAreaCode(),personToCopy.head->p.getNumber());
        head = newP;
        PhoneNode* cur = head;
        for( PhoneNode* i = personToCopy.head->next; i != NULL; i = i->next )
        {
            PhoneNode* newP = new PhoneNode();
            newP->p = Phone(i->p.getAreaCode(),i->p.getNumber());
            cur->next = newP;
            cur = cur->next;
        }
        cur->next = NULL;
    }
}

void Person::operator=( const Person &right )
{
    if( this != &right )
    {
        name = right.name;
        numberOfPhone = right.numberOfPhone;
        if( head != NULL )
        {
            PhoneNode* temp = new PhoneNode();
            temp = head->next;
            while( temp != NULL )
            {
                delete head;
                head = temp;
                temp = temp->next;
            }

        }
        if( right.head != NULL )
        {
            PhoneNode* newP = new PhoneNode();
            newP->p = Phone(right.head->p.getAreaCode(),right.head->p.getNumber());
            head = newP;
            PhoneNode* cur = head;
            for( PhoneNode* i = right.head->next; i != NULL; i = i->next )
            {
                PhoneNode* newP = new PhoneNode();
                newP->p = Phone(i->p.getAreaCode(),i->p.getNumber());
                cur->next = newP;
                cur = cur->next;
            }
            cur->next = NULL;
        }
    }
}

string Person::getName()
{
    return name;
}

int Person::getNo()
{
    return numberOfPhone;
}
bool Person::addPhone( const int areaCode, const int number )
{
    PhoneNode* temp = findPhone(areaCode,number);
    if( temp != NULL )
        return false;
    else
    {
        numberOfPhone++;

        if( head == NULL )
        {
            head = new PhoneNode();
            head->p = Phone(areaCode,number);

        }
        else
        {
            PhoneNode* cur = head;
            while( cur->next != NULL )
                cur = cur->next;
            PhoneNode* temp2 = new PhoneNode();
            temp2->p = Phone(areaCode,number);
            cur->next = temp2;
            cur = cur->next;
            cur->next = NULL;
        }

        return true;
    }
}

bool Person::removePhone( const int areaCode, const int number )
{
    PhoneNode* temp = findPhone(areaCode,number);
    if( temp == NULL )
        return false;
    else
    {
        numberOfPhone--;
        if( temp == head )
        {
            head = head->next;
            delete temp;
            temp->next = NULL;
        }
        else
        {
            for( PhoneNode* i = head; i != NULL; i = i->next)
            {
                if( i->next == temp )
                {
                    i->next = temp->next;
                    delete temp;
                    temp->next = NULL;
                }
            }
        }
        return true;
    }
}
void Person::displayPhoneNumbers()
{
    if( head == NULL)
    {
        cout<<"--EMPTY--"<<endl;
    }
    else
    {
       for( PhoneNode* i = head; i != NULL; i = i->next)
        {
            cout<<"Phone number: "<< i->p.getAreaCode() <<","<< i->p.getNumber()<<endl;
        }
    }

}
bool Person::displayPhoneNumbers( const int areaCode )
{
       bool check = false;
       for( PhoneNode* i = head; i != NULL; i = i->next)
        {
            if( i->p.getAreaCode() == areaCode )
            {
                if(check == false)
                {
                   cout<<getName()<<endl;
                   check = true;

                }
                cout<<"Phone number: " << i->p.getAreaCode() << "," << i->p.getNumber()<<endl;
            }

        }
        if(check)
            return true;
        return false;
}
Person::PhoneNode* Person::findPhone( const int areaCode, const int number )
{
    for( PhoneNode* i = head; i != NULL; i = i->next )
    {
        if( i->p.getAreaCode() == areaCode && i->p.getNumber() == number)
            return i;
    }
    return NULL;
}
