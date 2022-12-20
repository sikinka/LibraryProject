//
// Created by Sikinka on 19.12.2022.
//

// Library.h
#ifndef LIBRARYPROJECT_LIBRARY_H
#define LIBRARYPROJECT_LIBRARY_H
#pragma once

#include "Book.h"
#include <algorithm>
#include <vector>

// Abstraktní třída pro objekty sledující změny v knihovně
class Observer {
public:
// Volá se, když dojde ke změně v knihovně
    virtual void update() = 0;
};
class SomeObserver : public Observer {
public:
    // Volá se, když dojde ke změně v knihovně
    void update() override {
        // Provede požadovanou akci pro reakci na změnu stavu objektu
    }
};

class Library {
private:
// Seznam knih v knihovně
    std::vector<Book> books_;

// Seznam sledujících objektů
    std::vector<Observer*> observers_;

public:
// Přidá knihu do knihovny
    void addBook(const Book& book);
    void removeBookCopies(const std::string& title, int copies);
// Získej seznam knih v knihovně
    std::vector<Book> getBooks() const;
    std::vector<Book> findByAuthor(const std::string& author) const;
    std::vector<Book> findByTitle(const std::string& title) const;

    void attach(Observer* observer);
    void notify();
};

#endif // LIBRARYPROJECT_LIBRARY_H