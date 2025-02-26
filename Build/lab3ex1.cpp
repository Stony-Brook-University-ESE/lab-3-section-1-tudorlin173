#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Node {
    string song;
    string author;
    int year;
    Node* next;
    Node* prev;
    Node(string s, string a, int y) : song(s), author(a), year(y), next(nullptr), prev(nullptr) {}
};

class List {
private:
    Node* head;

public:
    List() : head(nullptr) {}
    ~List() {
        while (head) {
            deletesong(head->song, head->author, head->year);
        }
    }

    void addsong(string song, string author, int year) {
        Node* newNode = new Node(song, author, year);
        if (head == NULL) {
            newNode->next = head;
            head = newNode;
        }
        else {
            Node* curr = head;
            Node* pv = head->prev;
            while (curr) {
                if ((newNode->song) < (curr->song)) {
                    pv->next = newNode;
                    newNode->next = curr;
                    break;
                }
                else {
                    pv = pv->next;
                    curr = curr->next;
                }
            }
        }
     }

    void deletesong(string xsong, string xauthor, int xyear) {
        Node* pv = head->prev;
        Node* curr = head;
        while (curr) {
            if ((curr->song == xsong) && (curr->author == xauthor) && (curr->year == xyear)) {
                Node* temp = curr;
                pv->next = curr->next;
                delete temp;
            }
            
        }
    }

    void display() {
        Node* current = head;
        while (current) {
            cout << "Song name: " << current->song << ", Author: " << current->author << ", Year released: " << current->year << endl;
            current = current->next;
        }
    }
};
    
    int main() {
        List songList;
        string song, author;
        int year;
        cout << "Enter song name, author, and year released. Enter empty string to end new node.\n";
        while (1) {
            cout << "Song name: ";
            getline(cin, song);
            if (song.empty()) {
            break;
            }
            
            cout << "Author: ";
            getline(cin, author);
            
            cout << "Year released: ";
            cin >> year;
            cin.ignore(); 
    
            songList.addsong(song, author, year);
        }
    
        for (int i = 1; i <= 3; i++) {
            cout << "\nEnter song name, author, and year released to delete song.\n";
            cout << "Song name: ";
            getline(cin, song);
            if (song.empty()) {
            break;
            }
            
            cout << "Author: ";
            getline(cin, author);
            
            cout << "Year released: ";
            cin >> year;
            cin.ignore(); 
    
            songList.deletesong(song, author, year);
        }

        songList.display();
        return 0;
    }
