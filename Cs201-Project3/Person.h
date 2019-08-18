#ifndef __PERSON_H
#define __PERSON_H
#include <string>
#include "Phone.h"
using namespace std;
class Person{
    public:
     Person( const string name = "" );
     ~Person();
     Person( const Person& personToCopy );
     void operator=( const Person &right );
     string getName();
     int getNo();
     bool addPhone( const int areaCode, const int number );
     bool removePhone( const int areaCode, const int number );
     void displayPhoneNumbers();
     bool displayPhoneNumbers( const int areaCode );
    private:
     struct PhoneNode {
     Phone p;
     PhoneNode* next;
     };
     PhoneNode *head;
     int numberOfPhone;
     string name;
     PhoneNode* findPhone( const int areaCode, const int number );
};
#endif
