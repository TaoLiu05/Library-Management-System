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

    bool addBook(const Book& book);

    void searchBook(const std::string& title) const;

    void borrowBook(const std::string& title);

    void returnBook(const std::string& title);

    void saveBooks(const std::string& filename) const;

    void loadBooks(const std::string& filename);

    void removeBook(const std::string& title);

    void sortBooks();
};

#endif