#include "SimplePhoneBook.h"
#include <iostream>
#include <string>

PhoneBook::PhoneBook()
{
    head = NULL;
    numberOfPeople = 0;
}

PhoneBook::~PhoneBook()
{
    PersonNode* cur = head;

    while( cur != NULL )
    {
        PersonNode* temp = cur->next;
        delete cur;
        cur = temp;
    }
}

PhoneBook::PhoneBook (const PhoneBook& phoneBookToCopy)
{
    numberOfPeople = phoneBookToCopy.numberOfPeople;

    if( numberOfPeople > 0 )
    {
        head = new PersonNode();
        head->t = Person(phoneBookToCopy.head->t);
        PersonNode* cur = head;
        for( PersonNode* i = phoneBookToCopy.head->next; i != NULL; i = i->next )
        {
            PersonNode* newPerson = new PersonNode();
            newPerson->t = Person(i->t);
               cur ->next = newPerson;
               cur = cur->next;


        }
        cur -> next = NULL;
    }
}
void PhoneBook::operator=(const PhoneBook& right)
{
    if( this != &right )
    {
        numberOfPeople = right.numberOfPeople;
        PersonNode* cur = head;
        while(cur != NULL)
        {
            PersonNode* temp = cur-> next;
            delete cur;
            cur = temp;
        }

        head = new PersonNode();
        head->t = right.head->t;
        cur = head;

        for( PersonNode* i = right.head -> next; i != NULL; i = i->next )
        {
            PersonNode* newPerson = new PersonNode();
            newPerson->t = i->t;
            cur ->next = newPerson;
            cur = cur->next;
        }
        cur->next = NULL;
    }
}

bool PhoneBook::addPerson(const string name)
{
    if( findPerson(name) != NULL )
        return false;
    else
    {
        Person newP(name);
        if( head == NULL )
        {
            head = new PersonNode();
            head->t = newP;
        }
        else
        {
            PersonNode* cur = head;
            while(cur->next != NULL)
            {
                cur = cur->next;
            }
            cur->next = new PersonNode();
            cur = cur->next;
            cur->t = newP;
            cur->next = NULL;
        }
        numberOfPeople++;
        return true;
    }
}

bool PhoneBook::removePerson(const string name)
{
    PersonNode* temp = findPerson(name);

    if( temp != NULL)
    {
        if( temp == head )
        {
            PersonNode* cur = head;
            cur = cur->next;
            delete head;
            head = cur;
        }
        else
        {
            for( PersonNode* i = head; i != NULL; i = i->next )
            {
                if( i->next == temp )
                {
                    i->next = temp->next;
                    delete temp;
                    temp->next = NULL;
                }
            }
        }
        numberOfPeople--;
        return true;
    }
    return false;
}

void PhoneBook::displayPeople()
{
    if( numberOfPeople == 0 )
        cout<<"--EMPTY--"<<endl;
    else
    {
        for( PersonNode* i = head; i != NULL; i = i->next )
        {
            cout<<"Person "<<i->t.getName()<<endl;
        }
    }
}
PhoneBook::PersonNode* PhoneBook::findPerson(string name)
{
    bool returned;
    for( PersonNode* i = head; i != NULL; i = i->next)
    {
        if( i->t.getName().length() == name.length() )
        {
            returned = true;
            for(unsigned int j = 0; j < name.length(); j++)
            {
                if( tolower(i->t.getName().at(j)) != tolower(name.at(j)) )
                    returned = false;
            }
        }
        if(returned)
            return i;
    }
    return NULL;
}

