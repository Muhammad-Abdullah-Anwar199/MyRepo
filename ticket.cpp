#include "ticket.h"
#include "exhibit.h"
Ticket::Ticket() {
    ticketId=0;
    expiryDate="";
    isVIP=false;
}

Ticket::Ticket(int i,string date,bool is){
    ticketId=i;
    expiryDate=date;
    isVIP=is;
}

void Ticket::setTicketId(int i){
    ticketId=i;
}

int Ticket::getTicketId(){
    return ticketId;
}

void Ticket::setExpiryDate(string i){
    expiryDate=i;
}

string Ticket::getExpiryDate(){
    return expiryDate;
}

void Ticket::setViPAccess(bool is){
    isVIP=is;
}

bool Ticket::hasVIPAccess()const{
    return isVIP;
}

void Ticket::setExhibit(Exhibit exhibit){
    this->exhibit=exhibit;
}

Exhibit Ticket::getExhibit()const{
    return exhibit;
}

// operator overloading
bool Ticket::operator==(Ticket& t)const{
    return ticketId==t.ticketId&& expiryDate==t.expiryDate&& isVIP==t.isVIP;
}

bool Ticket::operator!=(Ticket& t)const{
    return ticketId!=t.ticketId|| expiryDate!=t.expiryDate|| isVIP!=t.isVIP;
}

bool isTicketOfUser(const Ticket& ticket, const int & userId) {
    return ticket.ticketId == userId;
}