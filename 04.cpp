#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;
class TBook {
private:
    string Name;
    string Author;
    int Count;
public:
    TBook() {}
    TBook(const string& name, const string& author, int count) : Name(name), Author(author), Count(count) {}
    void setName(const string& name) { Name = name; }
    void setAuthor(const string& author) { Author = author; }
    void setCount(int count) { Count = count; }
    string getName() const { return Name; }
    string getAuthor() const { return Author; }
    int getCount() const { return Count; }
};

bool compareByAuthor(const TBook& a, const TBook& b) {
    return a.getAuthor() < b.getAuthor();
}
bool compareByName(const TBook& a, const TBook& b) {
    return a.getName() < b.getName();
}
int main() {
    vector<TBook> books;
    ifstream input("books.txt");
    if (input.is_open()) {
        string line;
        while (getline(input, line)) {
            stringstream ss(line);
            string name, author;
            int count;
            ss >> name >> author >> count;
            TBook book(name, author, count);
            books.push_back(book);
        }
        input.close();
        sort(books.begin(), books.end(), compareByAuthor);
        cout << "Sorted by author:" << endl;
        for (const auto& book : books) {
            cout << "Name: " << book.getName() << ", Author: " << book.getAuthor() << ", Count: " << book.getCount() << std::endl;
        }
        cout << endl;
        sort(books.begin(), books.end(), compareByName);
        cout << "Sorted by name:" << endl;
        for (const auto& book : books) {
            cout << "Name: " << book.getName() << ", Author: " << book.getAuthor() << ", Count: " << book.getCount() << std::endl;
        }
    }
    else {
        cout << "Unable to open file" << endl;
    }
    return 0;
}
