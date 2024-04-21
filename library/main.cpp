#include <iostream>
#include "Book.h"
#include "User.h"
#include <string>
#include <Userlist.h>
#include <BookList.h>
#include <memory>

using namespace std;
int User::counteru=0;
int Book::counter=0;

int main()
{   int Size,choice,choice2,choice3,choice4,id,ID,booksize,choice5,choice6,choice7,authorid,bookid,userid,choice8,AID,ABcount=0;
    int usercount=0 ;
    double ratingValue;
    int bookcount=0;
    string name,bookname,newname,category;
    bool con=true;
    bool con2=true;
    bool con3=true;
    bool con4=true;
    bool con5=true;
    bool temp=true;

    User* users;
    Book* books;
    Userlist U1(Size);

while(con2==true)
  { con2=false;
    cout <<"Select one of the following choices: "<<endl;
    cout<<"1- Users menu "<<endl;
    cout<<"2- Books menu "<<endl;
    cout<<"3- Exit "<<endl;
    cin>>choice;

    if(choice==1)
    {
        cout<<"How many users will be added ? "<<endl;
        cin>>Size;
        users=new User[Size];
        Userlist U1(Size);
for(int i = 0 ; i < Size ; i++)
{
    users[i].setId(i+1);
}
        while (con==true)
        { con=false;
        cout<<"USERS MENU"<<endl;
        cout<<"1- Create a User and added it to the list "<<endl;
        cout<<"2- Search for a user "<<endl;
        cout<<"3- Display all users "<<endl;
        cout<<"4- Back to main menu "<<endl;
        cin>>choice2;
            switch (choice2)
            {
                    case 1:
                          {
                                cin>>users[usercount];
                                users[usercount].setId(usercount+1);
                                U1.addUser(users[usercount]);
                                usercount++;
                                con=true;
                          }
                                break;
                    case 2:
                    {   temp=true;
                        while(temp==true)
                        {
                        cout<<"Search For a User "<<endl;
                        cout<<"1- search by name "<<endl;
                        cout<<"2- search by id "<<endl;
                        cout<<"3- return to user menu"<<endl;
                        cin>>choice3;
                            if(choice3==1)
                            { cout<<"enter the name: "<<endl;
                                cin>>name;
                                U1.searchUser(name);
                                cout<<endl;
                                cout<<"1- delete user "<<endl;
                                cout<<"2- return to users menu "<<endl;
                                cin>>choice4;
                                if(choice4==1)
                                {
                                    for(int i=0;i<usercount;i++)
                                    {
                                       if(users[i].getName()==name)
                                        {
                                            U1.deleteUser(users[i].getId());
                                            usercount--;
                                        }
                                    }


                                }
                                if(choice4==2)
                                {
                                    con=true;
                                }
                            }
                            if(choice3==2)
                            {
                                cout<<"enter the id: "<<endl;
                                cin>>id;
                                U1.searchUser(id);
                            }
                            if(choice3==3)
                            { temp=false;
                                con=true;
                            }
                        }
                        con=true;
                    }
                                break;
                    case 3:
                    {
                        cout<<U1;
                        con=true;
                    }
                                break;
                    case 4:
                        {
                            cout<<"================================"<<endl;
                            con=false;
                            con2=true;
                        }
                                break;
                    default:
                    {
                        cout<<"you entered wrong choice "<<endl;
                       con=true;
                    }
              }
            }
        }
        if(choice==2)
        {
            cout<<"How many books will be added ? "<<endl;
            cin>>booksize;
            BookList B1(booksize);

            books=new Book[booksize];
            con3=true;
            while(con3==true)
            { con3=false;
            cout<<"BOOKS MENU"<<endl;
            cout<<"1- Create a Book and added it to the list "<<endl;
            cout<<"2- Search for a book "<<endl;
            cout<<"3- Display all books "<<endl;
            cout<<"4- Get the Highest rating book "<<endl;
            cout<<"5- get all books of a user "<<endl;
            cout<<"6- copy the current Book list to a new Book list and switch to it  "<<endl;
            cout<<"7- Back to main menu "<<endl;
            cin>>choice5;
                switch(choice5)
                    {   case 1:
                        {
                            cin>>books[bookcount];
                            books[bookcount].setId(bookcount+1);
                            B1.addBook(books[bookcount]);
                            bookcount++;
                                con3=true;
                                int choicee;
                                bool H=true;
                                while(H==true)
                                { H=false;
                                    cout<<"1- assign author "<<endl;
                                    cout<<"2-continue "<<endl;
                                    cin>>choicee;
                                    if(choicee==1)
                                    { cout<<"Enter author id "<<endl;
                                        cin>>AID;
                                        int out=0;
                                        for(int i=0;i<usercount;i++)
                                        {
                                         if(users[i].getId()==AID)
                                         {
                                             B1.assignAuthor(bookcount-1,users[i]);
                                             H=false;
                                             out=1;
                                         }

                                            }
                                            if(out==0)
                                            {
                                                cout<<"no author found with id = "<<AID<<endl;
                                                 H=true;
                                            }
                                            ABcount++;
                                    }
                                    else
                                    {
                                        con3=true;

                                    }
                                }
                        }
                            break;
                            case 2:
                            {
                                bool temp=true;
                                 while(temp==true)
                                {
                                cout<<"Search For a Book "<<endl;
                                cout<<"1- search by name "<<endl;
                                cout<<"2- search by id "<<endl;
                                cout<<"3- return to book menu"<<endl;
                                cin>>choice6;
                                    if(choice6==1)
                                    {       cout<<"enter the name: "<<endl;
                                            cin>>bookname;
                                            B1.searchBook(bookname);
                                            cout<<endl;
                                                cout<<"1- update author "<<endl;
                                                cout<<"2- update name "<<endl;
                                                cout<<"3- update category "<<endl;
                                                cout<<"4- delete book "<<endl;
                                                cout<<"5- rate book "<<endl;
                                                cout<<"6- get back to books menu "<<endl;
                                                cin>>choice7;
                                                if(choice7==1)
                                                {
                                                        for(int i=0;i<bookcount;i++)
                                                        {
                                                            if(books[i].getTitle()==bookname)
                                                            {
                                                                    cout<<"Enter author id "<<endl;
                                                                    cin>>authorid;
                                                                for(int x=0;x<usercount;x++)
                                                                {
                                                                    if(users[x].getId()==authorid)
                                                                    {
                                                                    B1.changeauthor(bookname,users[x]);
                                                                    }
                                                                }
                                                            }
                                                        }
                                                        con5=true;
                                                }

                                                if(choice7==2)
                                                {
                                                    B1.changename(bookname);

                                                }

                                                if (choice7==3)
                                                {

                                                    B1.changecategory(bookname);
                                                }

                                                if (choice7==4)
                                                {
                                                        for(int i=0;i<bookcount;i++)
                                                        {
                                                            if(books[i].getTitle()==bookname)
                                                            {   cout<<books[i].getId()<<endl;
                                                                B1.deleteBook(books[i].getId());
                                                            }
                                                        }
                                                }

                                                if(choice7==5)
                                                {
                                                    B1.ratebook(bookname);
                                                }
                                                if(choice7==6)
                                                {
                                                    con5=false;
                                                }


                                    }

                                    if(choice6==2)
                                    {
                                        cout<<"enter the book id: "<<endl;
                                        cin>>bookid;
                                        B1.searchBook(bookid);

                                    }
                                    if(choice6==3)
                                    {
                                        temp=false;
                                        con3=true;
                                    }
                                }
                                con3=true;
                            }

                                break;

                            case 3:
                            {
                                cout<<B1;

                                con3=true;
                            }
                                break;
                            case 4:
                            {   Book B0;
                                B0=B1.getTheHighestRatedBook();
                                cout<<B0;

                                con3=true;
                            }
                                break;
                            case 5:
                            {
                                cout<<"enter user id "<<endl;
                                int iddd;
                                cin>>iddd;
                                Book* B;
                                int countt=0;
                                B=new Book[countt];
                                for(int i=0;i<usercount;i++)
                                {
                                    if(users[i].getId()==iddd)
                                    {   B=B1.getBooksForUser(users[i]);
                                        for(int x=0;x<ABcount;x++)
                                        {

                                             cout<<"========Book "<<B[x].getId()<<" info ========"<<endl;
                                             cout<<"Title: "<<B[x].getTitle()<<endl;
                                             cout<<"|ISBN: "<<B[x].getISBN()<<endl;
                                             cout<<"|Id: "<<B[x].getId()<<endl;
                                             cout<<"|Category: "<<B[x].getCategory()<<endl;
                                             cout<<"|AVG Rating : "<<B[x].getrate()<<endl;
                                             cout<<"Author : "<<B[x].getAuthor().getName()<<endl;
                                             cout<<"=============================================="<<endl;


                                        }
                                    }
                                }


                                con3=true;
                            }
                                break;
                            case 6:
                            {
                                BookList B2(B1);
                                cout<<"Copied current list ( "<<bookcount<<" books ) to a new list and switched to it"<<endl;
                                cout<<endl;
                                con3=true;

                            }
                                break;
                            case 7:
                                {
                                    con2=true;
                                    con3=false;
                                }
                                    break;
                            default:
                                {
                                    cout<<"you entered wrong choice "<<endl;
                                }
                                con3=true;
                    }
            }
         }
         if(choice==3)
         {
             cout<<" -------------EXITING THE SYSTEM-------------"<<endl;
         }
         else
         {
             //cout<<"you entered WRONG choice "<<endl;
         }


















    }
    delete users;
    delete books;

    return 0;
}
