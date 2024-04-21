#ifndef USERLIST_H
#define USERLIST_H
#include <string>
#include <iostream>
#include <cstring>
#include "user.h"
#include "book.h"


class Userlist
{
    private:
        User* users;
        int usersCount=0;
        int capacity;
        bool temp=false;

    public:
        Userlist(int );
        void addUser(User user);
        User& searchUser(string name);
        User& searchUser(int id);
        void deleteUser(int id);
        friend ostream &operator<<(ostream &output,Userlist &userlist );

        ~Userlist();

};

#endif // USERLIST_H
