#include "Book.h"
#include <string>
#include <iostream>
#include <cstring>
#include "User.h"
#include "BookList.h"
using namespace std;


Book::Book()
{

   Title=" ";
   ISBN="  ";
   counter++;
   ID=counter;
   Category="   ";
   AverageRating=0;

}
Book::Book(string title, string isbn, string category)
{
   Title=title;
   ISBN=isbn;
   counter++;
   ID=counter;
   Category=category;
}
Book:: Book(const Book& book)
{
   ID=book.ID;
   Title=book.Title;
   ISBN=book.ISBN;
   Category=book.Category;
}
void Book::setTitle(string title)
{
   Title=title;
}
string Book::getTitle()
{
    return Title;
}
void Book:: setISBN(string isbn)
{
   ISBN=isbn;
}
string Book::getISBN()
{
    return ISBN;
}
void Book::setId(int id)
{
    ID=id;
}
int Book::getId()
{
    return ID;
}
void Book::setCategory(string category)
{
    Category=category;
}
string Book::getCategory()
{
    return Category;
}
void Book::rateBook(double x)
{
    AverageRating= x;
}
void Book::setAuthor(User user)
{

    author = user;
    BK=true;

}
User Book::getAuthor()
{
    return author;

}
/*bool Book::operator==(const Book& book)
{
    bool status;
    if(Title==book.Title && ISBN==book.ISBN && Category==book.Category && ID==book.ID)
        {
            cout<<"[You Entered The Same Book !!"<<endl;
            cout<<"[You Entered The Same Book !!"<<endl;
            status=true;
        }
    else
        status=false;
    return status;

}*/
int Book::getrate()
{
    return AverageRating;
}

  ostream & operator <<(ostream &output,Book &book )
 {
     output<<"========Book "<<book.ID<<" info ========"<<endl;
     output<<"Title: "<<book.Title<<endl;
     output<<"|ISBN: "<<book.ISBN<<endl;
     output<<"|Id: "<<book.ID<<endl;
     output<<"|Category: "<<book.Category<<endl;
     output<<"|AVG Rating : "<<book.AverageRating<<endl;
     output<<"=============================================="<<endl;
     if(book.BK==true)
     {output<<book.getAuthor();}

     return output;
 }
  istream & operator >>( istream  &input, Book &book )
 {


         cout<<"Enter the book information in this order"<<endl;
         cout<<"Title ISBN Category "<<endl;
         input>>book.Title>>book.ISBN>>book.Category;
         cout<<endl;
         return input;

 }
 Book::~Book()
 {

 }

