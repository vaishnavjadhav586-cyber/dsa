
#include <iostream>
#include <queue>
#define MAX_TICKETS 10

using namespace std;

class Ticket_Booking_System {
    int booking_counter = 0;  // Counts booked tickets
    queue<string> ticket_q;   // Stores customer names
    string name;

public:
    // Add a customer to the back of the queue
    void join_ticket_booking_queue() {
        cout << "\nEnter customer name: ";
        cin >> name;

        ticket_q.push(name);  // Insert customer into queue
        cout << name << " joined booking queue.\n";
    }
    // Book a ticket for the first customer
    void ticket_booked() {
        if (ticket_q.empty()) {
            cout << "\nEmpty Queue\n";
        }
        else if (booking_counter >= MAX_TICKETS) {
            cout << "\nSorry, No more tickets available.\n";
        }
        else {
            // front() gets the first customer
            cout << "\nTicket booked for: "
                 << ticket_q.front() << "\n";

            ticket_q.pop();     // Remove booked customer
            booking_counter++;  // Increase booked tickets
        }
    }

    // Display the number of tickets remaining
    void ticket_availability() {
        if (booking_counter == MAX_TICKETS) {
            cout << "\nSorry / No more tickets available.\n";
        }
        else {
            cout << "\nTickets remaining: "
                 << MAX_TICKETS - booking_counter << "\n";
        }
    }

    // Display the waiting list without changing the original queue
    void waiting_list() {
        if (ticket_q.empty()) {
            cout << "\nNo more persons in queue\n";
        }
        else {
            queue<string> temp = ticket_q;  // Copy original queue

            cout << "\nWaiting list is: ";

            while (!temp.empty()) {
                cout << temp.front() << " ";  // Display first name
                temp.pop();                   // Remove from copy
            }

            cout << "\n";
        }
    }
};

int main() {
    Ticket_Booking_System tbs;
    int choice;

    // Repeat menu until the user exits
    do {
        cout << "\n--- Ticket Booking System Menu ---";
        cout << "\nPress 1, To join queue";
        cout << "\nPress 2, To book ticket";
        cout << "\nPress 3, To check ticket availability";
        cout << "\nPress 4, To see WL";
        cout << "\nPress 5, To exit";
        cout << "\nEnter your choice: ";

        cin >> choice;

        switch (choice) {
            case 1:
                tbs.join_ticket_booking_queue();
                break;

            case 2:
                tbs.ticket_booked();
                break;

            case 3:
                tbs.ticket_availability();
                break;

            case 4:
                tbs.waiting_list();
                break;

            case 5:
                cout << "\nExit\n";
                return 0;  // End program

            default:
                cout << "\nPlease enter correct choice\n";
                break;
        }

    } while (choice != 5);

    return 0;
}
