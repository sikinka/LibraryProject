//
// Created by Sikinka on 19.12.2022.
//

#ifndef LIBRARYPROJECT_BOOK_H
#define LIBRARYPROJECT_BOOK_H
#pragma once

#include <iostream>
#include <string>

// Třída reprezentující jednu knihu v knihovně
class Book {
private:
    std::string title_;
    std::string author_;
    int copies_;

public:
    Book(const std::string& title, const std::string& author, int copies);
    const std::string& getTitle() const;
    const std::string& getAuthor() const;
    int getCopies() const;
    void setCopies(int copies);
    friend std::ostream& operator<<(std::ostream& out, const Book& book);
    friend bool operator==(const Book& lhs, const Book& rhs);
};

bool operator==(const Book& lhs, const Book& rhs);
std::ostream& operator<<(std::ostream& out, const Book& book);
#endif // LIBRARYPROJECT_BOOK_H
