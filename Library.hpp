#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include "Book.hpp"
#include <vector>
#include <string>

class Library{
    private:
    std::vector<Book> books;

    public:
    void displayBooks() const;

    void addBook(const Book& book);

    void searchBook(const std::string& title) const;

    void borrowBook(const std::string& title);

    void returnBook(const std::string& title);
};

#endif