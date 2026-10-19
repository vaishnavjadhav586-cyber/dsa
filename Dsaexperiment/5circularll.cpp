
#include<iostream>
#include<string>
using namespace std;

class Song{
    public:
        string songName;
        float duration;
        Song *next;
        Song *prev;

        // Constructor
        Song(string s,float t)
        {
            songName = s;
            duration = t;
            next = prev = NULL;
        }
};

class Playlist{
    Song *head = NULL;
    Song *tail = NULL;

    public:
        // Add a new song
        void addSong(string s, float t){
            Song *newSong = new Song(s,t);

            if(head == NULL){
                head = newSong;
                tail = newSong;
                tail -> next = head;
                head -> prev = tail;
            }
            else{
                tail -> next = newSong;
                newSong -> prev = tail;
                newSong -> next = head;

                head -> prev = newSong;
                tail = newSong; // Update tail
            }

            cout<<"\nSong Added in playlist "<<s<<" ";
        }

        // Display all songs
        void displayPlaylist(){
            if(head == NULL){
                cout<<"\nPlaylist is empty";
                return;
            }

            Song *temp = head;
            cout<<"\nCurrent Playlist is :";

            do{
                cout<<temp ->songName<<",";
                temp = temp -> next;
            }while(temp != head);
        }

        // Find the previous song
        void previousSong(string s) {
            if (head == NULL) {
                cout << "\nPlaylist empty";
                return;
            }

            Song *temp = head;
            bool found = false;

            do {
                if (temp->songName == s) {
                    found = true;
                    break;
                }
                temp = temp->next;
            } while (temp != head);

            if (!found) {
                cout << "\nSong not found: " << s;
                return;
            }

            cout << "\nCurrent Song: " << s;
            cout << "\nNow playing Previous Song: "
                 << temp->prev->songName;
        }

        // Delete a song
        void deleteSong(string s) {
            if (head == NULL) {
                cout << "\nEmpty playlist";
                return;
            }

            Song *temp = head;
            bool found = false;

            do {
                if (temp->songName == s) {
                    found = true;
                    break;
                }
                temp = temp->next;
            } while (temp != head);

            if (!found) {
                cout << "\nSong not found: " << s;
                return;
            }

            // Only one song in the playlist
            if (head == tail) {
                delete head;
                head = NULL;
                tail = NULL;
            }
            else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;

                if (temp == head) {
                    head = temp->next;
                }
                if (temp == tail) {
                    tail = temp->prev;
                }

                delete temp;
            }

            cout << "\nSong deleted: " << s;
        }
};

int main() {
    Playlist playlist;
    int choice;
    string songName;
    float duration;

    do {
        cout << "\n\n=== PLAYLIST MENU ===";
        cout << "\n1. Add Song";
        cout << "\n2. Delete Song";
        cout << "\n3. Display Playlist";
        cout << "\n4. Previous Song";
        cout << "\n5. Exit";
        cout << "\nEnter your choice (1-5): ";
        cin >> choice;

        cin.ignore(); // Clear leftover Enter key

        switch (choice) {
            case 1:
                cout << "Enter song name: ";
                getline(cin, songName);
                cout << "Enter duration (e.g., 4.30): ";
                cin >> duration;
                playlist.addSong(songName, duration);
                break;

            case 2:
                cout << "Enter song name to delete: ";
                getline(cin, songName);
                playlist.deleteSong(songName);
                break;

            case 3:
                playlist.displayPlaylist();
                break;

            case 4:
                cout << "Enter current song name: ";
                getline(cin, songName);
                playlist.previousSong(songName);
                break;

            case 5:
                cout << "\nExiting program. see you later , bye!\n";
                break;

            default:
                cout << "\nInvalid choice! Please enter a number between 1 and 5.";
        }
    } while (choice != 5);

    return 0;
}
