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

    void incOrder(List& incList) {
        Node* pv = head->prev;
        Node* node1 = head;
        Node* node2 = node1->next;
        int swapcount = 0;
        while (1) {
            while (node2) {
                if ((node1->year) > (node2->year)) {
                    node1->next = node2->next;
                    pv->next = node2;
                    node2->next = node1;
                    swapcount++;
                }
                pv = pv->next;
                node1 = node1->next;
                node2 = node2->next;
            }
            if (swapcount == 0) {
                break;
            }
            else {
                swapcount = 0;
            }
        }
        node1 = head;
        incList.addsong(node1->song, node1->author, node1->year);
        node1 = node1->next;
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
        while (true) {
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
        cout << "\nSongs in alphabetical order:\n";
        songList.display();

        List incList;
        songList.incOrder(incList);
        cout << "\nSongs in increasing order of year released:\n";
        incList.display();
        return 0;
    }
