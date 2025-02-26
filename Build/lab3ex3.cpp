#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Node {
    string song;
    string author;
    string town;
    Node* next;
    Node* prev;
    Node(string s, string a, string t) : song(s), author(a), town(t), next(nullptr), prev(nullptr) {}
};

class List {
private:
    Node* head;

public:
    List() : head(nullptr) {}
    ~List() {
        while (head) {
            deletesong(head->song, head->author, head->town);
        }
    }

    void addsong(string song, string author, string town) {
        Node* newNode = new Node(song, author, town);
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

    void deletesong(string xsong, string xauthor, string xtown) {
        Node* pv = head->prev;
        Node* curr = head;
        while (curr) {
            if ((curr->song == xsong) && (curr->author == xauthor) && (curr->town == xtown)) {
                Node* temp = curr;
                pv->next = curr->next;
                delete temp;
            }
            
        }
    }

    void display() {
        Node* current = head;
        while (current) {
            cout << "Song name: " << current->song << ", Author: " << current->author << ", town of author: " << current->town << endl;
            current = current->next;
        }
    }
};
    
    int main() {
        List songList;
        string song, author;
        string town;
        cout << "Enter song name, author, and town of author. Enter empty string to end new node.\n";
        while (1) {
            cout << "Song name: ";
            getline(cin, song);
            if (song.empty()) {
            break;
            }
            
            cout << "Author: ";
            getline(cin, author);
            
            cout << "town of author: ";
            cin >> town;
            cin.ignore(); 
    
            songList.addsong(song, author, town);
        }
    
        for (int i = 1; i <= 3; i++) {
            cout << "\nEnter song name, author, and town of author to delete song.\n";
            cout << "Song name: ";
            getline(cin, song);
            if (song.empty()) {
            break;
            }
            
            cout << "Author: ";
            getline(cin, author);
            
            cout << "town of author: ";
            cin >> town;
            cin.ignore(); 
    
            songList.deletesong(song, author, town);
        }

        songList.display();
        return 0;
    }
