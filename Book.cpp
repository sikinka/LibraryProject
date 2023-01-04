//
// Created by Sikinka on 19.12.2022.
//
#include "Book.h"

// Implementace konstruktoru pro inicializaci objektu knihy s názvem, autorem a počtem kopií
// Členové proměnné jsou inicializovány pomocí syntaxe member initializer list
Book::Book(const std::string& title, const std::string& author, int copies)
        : title_(title), author_(author), copies_(copies) {}

// Vrací název knihy
const std::string& Book::getTitle() const { return title_; }

// Vrací jméno autora knihy
const std::string& Book::getAuthor() const { return author_; }

// Vrací počet kopií knihy
int Book::getCopies() const { return copies_; }

// Nastavuje počet kopií knihy
void Book::setCopies(int copies) { copies_ = copies; }

// Přetěžuje operátor vstupu do streamu pro výpis objektu knihy ve formátu:
// "název by autor (kopie kopie)"
std::ostream& operator<<(std::ostream& out, const Book& book) {
    out << book.title_ << " by " << book.author_ << " (" << book.copies_
        << " copies)";
    return out;
}

// Přetěžuje operátor rovnosti pro porovnání dvou knih za účelem rovnosti
// Dvě knihy jsou považovány za rovné, pokud mají stejný název, autora a počet kopií
bool operator==(const Book& lhs, const Book& rhs) {
    return lhs.title_ == rhs.title_ && lhs.author_ == rhs.author_ &&
           lhs.copies_ == rhs.copies_;
}
