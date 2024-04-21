#ifndef BOOKLIST_H
#define BOOKLIST_H
#include "User.h"
#include "book.h"


class BookList
{
    private:
         Book* books;
         int Capacity;
         int bookscount=0 ;
         bool temp=false;
         int val=0;
    public:
        void addBook(Book book);
        BookList(const BookList& anotherlist);
        BookList(int );
        Book& searchBook(string name);
        Book& searchBook(int id);
        void deleteBook(int id);
        void changename(string bookname);
        void changeauthor(string bookname,User user);
        void assignAuthor(int countt,User U);
        void changecategory(string bookname);
        void ratebook(string bookname);
        Book getTheHighestRatedBook();
        Book* getBooksForUser(User);
        Book& operator[](const int position);
        friend ostream& operator<<(ostream &output,BookList &booklist);
        friend class Book;
        friend class Userlist;
        ~BookList();














    private:
};

#endif // BOOKLIST_H
