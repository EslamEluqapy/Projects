#include "BookList.h"
#include "User.h"
#include "Book.h"
#include "userlist.h"

BookList::BookList(int C) //parameterized constructor to make the list
{
    Capacity=C;
    books= new Book[C];

}
BookList::BookList(const BookList& anotherlist) //copy constructor to copy all books in list to another list
{
    Capacity=anotherlist.Capacity;
    books= new Book[anotherlist.Capacity];
    bookscount=anotherlist.bookscount;
    for(int i=0;i<bookscount;i++)
    {
        books[i]=anotherlist.books[i];
    }
}
void BookList::addBook(Book book) //function to add a book in the list
{
    books[bookscount]=book;
    books[bookscount].setId(bookscount+1);
    bookscount++;
}
Book& BookList::searchBook(string name) //function to search for a book by name
{
    for(int i=0;i<Capacity;i++)
   {
       if(books[i].Title==name)
        {

         cout<<"========Book "<<books[i].ID<<" info ========"<<endl;
         cout<<"Title: "<<books[i].Title<<endl;
         cout<<"|ISBN: "<<books[i].ISBN<<endl;
         cout<<"|Id: "<<books[i].ID<<endl;
         cout<<"|Category: "<<books[i].Category<<endl;
         cout<<"|AVG Rating : "<<books[i].AverageRating<<endl;
         cout<<"Author : "<<books[i].getAuthor().getName()<<endl;
        }
    }
}
Book& BookList::searchBook(int id) //function to search for a book by id
{
     for(int i=0;i<Capacity;i++)
   {

       if(books[i].ID==id)
        {

         cout<<"========Book "<<books[i].ID<<" info ========"<<endl;
         cout<<"Title: "<<books[i].Title<<endl;
         cout<<"|ISBN: "<<books[i].ISBN<<endl;
         cout<<"|Id: "<<books[i].ID<<endl;
         cout<<"|Category: "<<books[i].Category<<endl;
         cout<<"|AVG Rating : "<<books[i].AverageRating<<endl;
         cout<<"Author : "<<books[i].getAuthor().getName()<<endl;
        }
    }
}

void BookList::deleteBook(int id) //function to delete a specific book
{
    for(int i=0;i<bookscount;i++)
    {
        if(books[i].getId()==id)
        {
            for(int x=i;x<bookscount-1;x++)
            {
                books[x]=books[x+1];
            }
        }
    }
    bookscount--;

}
Book BookList::getTheHighestRatedBook() //function to get the highest rated book in the list
{
     double temp=0;
     int U;
     Book b;
    for(int i=0;i<bookscount;i++)
    {
       if(books[i].AverageRating>temp)
       {
           temp=books[i].AverageRating;
           U=i;
       }

    }
     b=books[U];
     return b;

}
Book* BookList::getBooksForUser(User user) // function to get all books of a user
{
    Book* B;
    B=new Book[Capacity];
    int counter=0;
    for(int i=0;i<bookscount;i++)
    {
      if(books[i].author==user)
      {
        B[counter]=books[i];
        counter++;

      }

    }
    return B;

}
Book& BookList::operator[](const int position) //operator [] to access each object in the array of books
{
    if(position<0 ||position>=Capacity)
    {
        cout<<"ERROR OUT OF RANGE "<<endl;
    }
    return books[position];
}
ostream& operator<<(ostream &output,BookList &booklist) //operator <<to display all books in the list
{
   for(int i=0;i<booklist.bookscount;i++)
    {

            output<<booklist.books[i];



     }
    return output;
}
void BookList::changename(string bookname) //function to change the name of a book
{
    for(int i=0;i<bookscount;i++)
   {if(books[i].getTitle()==bookname)
    {string namee;
     cout<<"enter new name : "<<endl;
     cin>>namee;
     books[i].setTitle(namee);}}
}
void BookList::changeauthor(string bookname,User user) //function to change author of a book
{

    for(int i=0;i<bookscount;i++)
    {if(books[i].getTitle()==bookname)
        {books[i].setAuthor(user);}}
}
void BookList::changecategory(string bookname) //function to change category of a book
{
    for(int i=0;i<bookscount;i++)
   {if(books[i].getTitle()==bookname)
    {string category;
     cout<<"enter new category : "<<endl;
     cin>>category;
     books[i].setCategory(category);}}
}
void BookList::ratebook(string bookname) //function to rate book
{
    for(int i=0;i<bookscount;i++)
    {
        if(books[i].getTitle()==bookname)
        {   int ratingValue;
            cout<<"Enter Rating Value : "<<endl;
            cin>>ratingValue;
            books[i].rateBook(ratingValue);

        }
    }
}
void BookList::assignAuthor(int countt,User U) //function to assign an author for a book
{

    books[countt].setAuthor(U);



}
BookList::~BookList()
{
 delete [] books;
}


