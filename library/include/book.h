#ifndef BOOK_H
#define BOOK_H
#include<cstring>
#include<iostream>
#include "user.h"
using namespace std;

class Book
{
private:
    string Title;
    string ISBN;
    int ID;
    string Category;
    double AverageRating=0;
    User author;
    bool BK=false;


public:
static int counter;
    Book();                                                 //Default constructor for the user
    Book(string title, string isbn, string category);       //Parameterized constructor for the user
    Book(const Book& book);                                 //copy constructor for the user
    void setTitle(string title);                            //function to set title of the book
    string getTitle();                                      //function to get title of the book
    void setISBN(string isbn);                              //function to set ISBN of the book
    string getISBN();                                       //function to get ISBN of the book
    void setId(int id);                                     //function to set ID of the book
    int getId();
    int getrate();                                          //function to get ID of the book
    void setCategory(string category);                      //function to set category of the book
    string getCategory();                                   //function to get category of the book
    void setAuthor(User user);                              //function to set author of the book
    User getAuthor();                                       //function to get author of the book
    void rateBook(double x);                       //function to rate the book
    bool operator==(const Book& book);                      //function to make sure that books are not equal
    friend ostream &operator <<(ostream &output,Book &book );    //function to print the  book info
    friend istream &operator >>( istream &input, Book &book ); //function to  input the book info
    friend class BookList;
    ~Book();
};
#endif // BOOK_H



