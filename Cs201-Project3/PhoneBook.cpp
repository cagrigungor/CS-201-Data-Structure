#include "PhoneBook.h"
#include <iostream>
#include <string>

PhoneBook::PhoneBook()
{
    head = NULL;
    numberOfPeople = 0;
}

PhoneBook::~PhoneBook()
{
    Node* cur = head;

    while( cur != NULL )
    {
        Node* temp = cur->next;
        delete cur;
        cur = temp;
    }
}

PhoneBook::PhoneBook (const PhoneBook& phoneBookToCopy)
{
    numberOfPeople = phoneBookToCopy.numberOfPeople;

    if( numberOfPeople > 0 )
    {
        head = new Node();
        head->t = Person(phoneBookToCopy.head->t);
        Node* cur = head;
        for( Node* i = phoneBookToCopy.head->next; i != NULL; i = i->next )
        {
            Node* newPerson = new Node();
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
        Node* cur = head;
        while(cur != NULL)
        {
            Node* temp = cur-> next;
            delete cur;
            cur = temp;
        }

        head = new Node();
        head->t = right.head->t;
        cur = head;

        for( Node* i = right.head -> next; i != NULL; i = i->next )
        {
            Node* newPerson = new Node();
            newPerson->t = i->t;
            cur ->next = newPerson;
            cur = cur->next;
        }
        cur->next = NULL;
    }
}
bool PhoneBook::addPerson( string name )
{
    if( findPerson(name) != NULL )
    {
        cout<<"The person had been added, enter another person."<<endl;
        return false;
    }

    else
    {
        Person newP(name);
        if( head == NULL )
        {
            head = new Node();
            head->t = newP;
        }
        else
        {
            Node* cur = head;
            while(cur->next != NULL)
            {
                cur = cur->next;
            }
            cur->next = new Node();
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
    Node* temp = findPerson(name);

    if( temp != NULL)
    {
        if( temp == head )
        {
            Node* cur = head;
            cur = cur->next;
            delete head;
            head = cur;
        }
        else
        {
            for( Node* i = head; i != NULL; i = i->next )
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
    cout<<"The person has not been found."<<endl;
    return false;
}

bool PhoneBook::addPhone( string personName, int areaCode, int number )
{
    Node* person = findPerson(personName);
    return person->t.addPhone(areaCode,number);
}
bool PhoneBook::removePhone( string personName, int areaCode, int number )
{
    Node* person = findPerson(personName);
    return person->t.removePhone(areaCode,number);
}
void PhoneBook::displayPerson( string name )
{
    Node* person = findPerson(name);
    if( person == NULL )
        cout<<"--EMPTY--"<<endl;
    else
    {
        cout<<person->t.getName()<<endl;
        person->t.displayPhoneNumbers();
    }
}
/*void PhoneBook::displayPerson( string name, int areaCode )
{
    Node* person = findPerson(name);
    if( person == NULL )
        cout<<"--EMPTY--"<<endl;
    else
    {
        cout<<person->t.getName()<<endl;
        person->t.displayPhoneNumbers();
    }
}*/
void PhoneBook::displayAreaCode( int areaCode )
{
    cout<<areaCode<<endl;
    bool check= false;
    for( Node* i = head; i != NULL; i = i->next)
    {
        check = i->t.displayPhoneNumbers(areaCode);
        if(check)
            cout<<endl;
    }

    if(!check)
        cout<<"--EMPTY--"<<endl;
}

void PhoneBook::displayPeople()
{
    if( numberOfPeople < 1 )
        cout<<"--EMPTY--";
    else
    {
        for( Node* i = head; i != NULL; i = i->next)
        {
            cout<<"Person "<<i->t.getName()<<", number of phones "<<i->t.getName()<<" has "<<i->t.getNo()<<endl;
        }
    }
}
PhoneBook::Node* PhoneBook::findPerson(string name)
{
    bool returned;
    for( Node* i = head; i != NULL; i = i->next)
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


