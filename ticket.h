#ifndef TICKET_H
#define TICKET_H
#include "exhibit.h"
#include <iostream>
using namespace std;
class Ticket {
private:
    int ticketId;
    string expiryDate;
    bool isVIP;
    Exhibit exhibit; //Composition
public:
    Ticket();
    Ticket(int,string,bool);
    void setTicketId(int);
    int getTicketId();
    void setExpiryDate(string);
    string getExpiryDate();
    void setViPAccess(bool);
    bool hasVIPAccess()const;
    void setExhibit(const Exhibit exhibit);
    Exhibit getExhibit()const;
    bool operator==(Ticket&)const;
    bool operator!=(Ticket&)const;
    friend bool isTicketOfUser(const Ticket& ticket, const int & userID);
};
#endif //TICKET_H
