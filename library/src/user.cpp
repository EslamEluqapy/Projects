#include "User.h"
#include "Book.h"
#include <string>
#include <iostream>
#include <cstring>
#include "Userlist.h"
using namespace std;

User::User()
{

    name=" ";
    age=0;
    password=" ";
    email=" ";
    counteru++;
    ID=counteru;
}
User::User(string N, int A, string E, string P)
{

    name=N;
    age=A;
    email=E;
    password=P;
    counteru++;
    ID=counteru;


}
User::User(const User& user)
{

    name=user.name;
    age=user.age;
    email=user.email;
    password=user.password;
    ID=user.ID;



}
bool User::operator==(const User &user)
{
    bool status;
    if(name==user.name && age==user.age && email==user.email && ID==user.ID)
    {
        //cout<<"[YOu Entered The Same User !!"<<endl;
        status=true;
    }
    else
        status=false;
    return status;

}
void User::setName(string N)
{
    name=N;

}
string User:: getName() const
{
    return name;
}
void User::setPassword(string P)
{
    password=P;


}
string User::getPassword()
{
    return password;
}
 void User::setEmail(string E)
 {
     email=E;
 }
 string User::getEmail()
 {
     return email;
 }
 void User::setAge(int A)
 {
     age=A;
 }
 int User::getAge()
 {
     return age;
 }
 void User::setId(int id)
 {
     ID=id;
 }
 int User::getId()
 {
     return ID;
 }
 ostream &operator<<(ostream &output, const User & user )
 {

     output<<"========Author  info ========"<<endl;
     output<<"Name: "<<user.name<<endl;
     output<<"|Age: "<<user.age<<endl;
     output<<"|Id: "<<user.ID<<endl;
     output<<"|Email: "<<user.email<<endl;
     output<<"=============================================="<<endl;
     output<<endl;

 }
 istream &operator>>( istream  &input, User &user )
 {


         cout<<"Enter the user information in this order"<<endl;
         cout<<"Name Age Email Password"<<endl;
         input>>user.name>>user.age>>user.email>>user.password;
         cout<<endl;
         return input;


 }
 User::~User()
 {

 }

