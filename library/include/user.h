#ifndef USER_H
#define USER_H
#include <string>
#include <iostream>
#include <cstring>

using namespace std;



class User
{
private:
    string name;
    int age;
    int ID;
    string password;
    string email;
public:
 static int counteru;
    User();                     //Default constructor for the user
    User(string name, int age, string email, string password); //Parameterized constructor for the user
    User(const User& user);                   //copy constructor for the user
    bool operator==(const User& user);    //function to make sure that users are not equal
    void setName(string name);           //function to set name of user
    string getName() const;                 //function to get name of user
    void setPassword(string password);      //function to set password of user
    string getPassword();                   //function to get password of user
    void setEmail(string email);            //function to set email of user
    string getEmail();                       //function to get email of user
    void setAge(int age);                    //function to set age of user
    int getAge();                               //function to get age of user
    void setId(int id);                          //function to set id of user
    int getId();                                    //function to get id of user
    friend ostream &operator<<(ostream &output, const User &user );     //function to print the  user info
    friend istream &operator>>( istream  &input, User &user ); //function to  input the user info
    friend class Userlist;
    ~User();
};
#endif // USER_H


