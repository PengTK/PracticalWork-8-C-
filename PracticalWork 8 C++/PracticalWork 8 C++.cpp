#include <iostream>
#include <string>
#include <array>
#include <list>
#include <stack>
#include <queue>
#include <forward_list>

using namespace std;

struct Book {
    string title;
    string author;
    string genre;
    int year;
};

void inputBookInfo(Book& book) {
    setlocale(LC_ALL, "Russian");
    cout << "Введите название книги: ";
    getline(cin, book.title);
    cout << "Введите автора книги: ";
    getline(cin, book.author);
    cout << "Введите жанр книги: ";
    getline(cin, book.genre);
    cout << "Введите год издания книги: ";
    cin >> book.year;
    cin.ignore();
}

void outputBookInfo(const Book& book) {
    setlocale(LC_ALL, "Russian");
    cout << "Название: " << book.title << endl;
    cout << "Автор: " << book.author << endl;
    cout << "Жанр: " << book.genre << endl;
    cout << "Год издания: " << book.year << endl;
}

// Функция для сравнения книг по году издания для использования в Priority_queue
struct CompareBooksByYear {

    bool operator()(const Book& book1, const Book& book2) {
        return book1.year > book2.year;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    array<Book, 5> booksArray;
    list<Book> booksList;
    forward_list<Book> booksforward_list;

    // Заполняем контейнеры книгами
    for (int i = 0; i < 5; i++) {
        cout << "Введите информацию о книге " << i + 1 << endl;
        inputBookInfo(booksArray[i]);
        booksList.push_back(booksArray[i]);
        booksforward_list.push_front(booksArray[i]);
    }

    // Выводим все книги в порядке, обратном порядку, в котором они были добавлены, используя Stack
    stack<Book> booksStack;
    for (const auto& book : booksArray) {
        booksStack.push(book);
    }
    cout << "Книги в порядке в обратном тому в котором котором они добавлены,используя Stack:" << endl;
    while (!booksStack.empty()) {
        outputBookInfo(booksStack.top());
        booksStack.pop();
    }

    // Выводим все книги в том же порядке, в котором они были добавлены, используя Queue
    queue<Book> booksQueue;
    for (const auto& book : booksList) {
        booksQueue.push(book);
    }
    cout << "Книги в порядке в котором они добавлены, используя Queue: " << endl;
    while (!booksQueue.empty()) {
        outputBookInfo(booksQueue.front());
        booksQueue.pop();
    }

    // Выводим все книги в порядке возрастания года издания, используя Priorityqueue
    priority_queue<Book, vector<Book>, CompareBooksByYear> booksPriorityQueue;
    for (const auto& book : booksforward_list) {
        booksPriorityQueue.push(book);
    }
    cout << "Книги в порядке возростания года, используя Priority_queue:" << endl;
    while (!booksPriorityQueue.empty()) {
        outputBookInfo(booksPriorityQueue.top());
        booksPriorityQueue.pop();
    }

    for (const auto& book : booksList) {
        booksQueue.push(book);
    }
    cout << "Книги в порядке в котором они добавлены, используя Queue: " << endl;
    while (!booksQueue.empty()) {
        outputBookInfo(booksQueue.front());
        booksQueue.pop();
    }


    return 0;
}
