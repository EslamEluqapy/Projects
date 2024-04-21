#include "Userlist.h"
#include "User.h"
#include "Book.h"
#include <iostream>
#include <cstring>


Userlist::Userlist(int C) //parameterized constructor to make the list
{
    capacity=C;
    users=new User[C];
}

void Userlist::addUser(User user) //function to add a user to the list
{

    users[usersCount]=user;
    users[usersCount].setId(usersCount+1);

    usersCount++;



}

User& Userlist::searchUser(string name)     //function to search for a user in list by name
{
    for(int i=0;i<capacity;i++)
   {
       if(users[i].name==name)
        {

            cout<<users[i];
        }


    }
}
User& Userlist::searchUser(int id) //function to search for a user in list by id
{
     for(int i=0;i<capacity;i++)
   {

       if(users[i].ID==id)
        cout<<users[i];


    }

}
void Userlist::deleteUser(int id) //function to delete a user in the list
{
    for(int i=0;i<usersCount;i++)
    {
        if(users[i].getId()==id)
        {
         for( int z=i;z<usersCount-1;z++)
         {
             users[z]=users[z+1];
         }
        }

    }
    users[usersCount-1]={};
    usersCount--;

}
 ostream &operator<<(ostream &output,Userlist &userlist ) //to display all users in list
{
    for(int i=0;i<userlist.usersCount;i++)
    {



            output<<userlist.users[i];


    }
    return output;
}



Userlist::~Userlist()
{
delete [] users;
}


