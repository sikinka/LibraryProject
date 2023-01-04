//
// Created by Sikinka on 19.12.2022.
//
#ifndef LIBRARYPROJECT_BOOK_H
#define LIBRARYPROJECT_BOOK_H
#pragma once

#include <iostream>
#include <string>

class Book {
private:
    std::string title_; // drží název knihy
    std::string author_; // drží jméno autora knihy
    int copies_; // drží počet kopií knihy

public:
    // Konstruktor pro inicializaci knihy s názvem, autorem a počtem kopií
    Book(const std::string& title, const std::string& author, int copies);

    // Vrací název knihy
    const std::string& getTitle() const;

    // Vrací jméno autora knihy
    const std::string& getAuthor() const;

    // Vrací počet kopií knihy
    int getCopies() const;

    // Nastavuje počet kopií knihy
    void setCopies(int copies);

    // Přetěžení operátoru vstupu do streamu pro výpis knihy
    friend std::ostream& operator<<(std::ostream& out, const Book& book);

    // Přetěžení operátoru rovnosti pro porovnání dvou knih
    friend bool operator==(const Book& lhs, const Book& rhs);
};

// Definice implementace operátoru rovnosti mimo třídu
bool operator==(const Book& lhs, const Book& rhs);

// Definice implementace operátoru vstupu do streamu mimo třídu
std::ostream& operator<<(std::ostream& out, const Book& book);

#endif // LIBRARYPROJECT_BOOK_H
