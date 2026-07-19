#include "Library.hpp"
#include <iostream>

void Library::displayBooks() const{
    if(books.empty()){
        std:: cout << "Library is empty."<< std::endl;
        return;
    }
    for(const Book& book : books){
        book.display();
    }
}

void Library::addBook(const Book& book){
    books.push_back(book);
}

void Library::searchBook(const std:: string& title) const{
    for( const Book& book : books){
        if(book.get_Title() == title){
            book.display();
            return;
        }
    }
}

void Library::borrowBook(const std::string& title){
    for(Book& book: books){
        if(book.get_Title() == title){
            if(book.isBorrowed()){
                std:: cout << "Book is already borrowed." << std::endl;
            }
            else{
                book.borrowBook();
                std::cout << "Book borrowed."<< std::endl;
            }
            return;
        }
       
    }
    std::cout << "Book not found."<<std::endl;
}

void Library::returnBook(const std::string& title){
    for(Book& book : books){
        if(book.get_Title()== title){
            if(book.isBorrowed()){
                book.returnBook();
                std:: cout << "Book returned."<< std:: endl;
            }
            else{
                std:: cout<<"Book wasn't borrowed." << std:: endl;
            }

            return;
        }
    }
    std:: cout << "Book not found." << std:: endl;
}


