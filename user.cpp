#include "user.h"
#include "ticket.h"
#include "membership.h"
#include "review.h"

User::User(int initialSize) {

  reviewCapacity = initialSize;
  reviewCount = 0;
  reviews = new Review[reviewCapacity];
}
void User::setUserName(string name){
  userName=name;
}
string User:: getUserName(){
  return userName;
}

void User::addTicket(Ticket& ticket){
  tickets.push_back(ticket);
}

Ticket User::getTicket(int index){
  if(index>=0 && index<tickets.size()){
    return tickets[index];
  }
  cout<<"Invalid Index"<<endl;
  return Ticket();
}

int User:: countTickets(){
  return tickets.size();
}

void User::addMemberShip(Membership& a){
  mem.push_back(a);
}

int User::countMembership() {
  return mem.size();
}

Membership User::getMemberShip(int index){
  if(index>=0 && index<mem.size()){
    return mem[index];
  }
  cout<<"Invalid Index"<<endl;
  return Membership();
}

void User::addReviews(Review review) {
  if (reviewCount >= reviewCapacity) {
      int newCapacity = reviewCapacity * 2;
      Review* newReviews = new Review[newCapacity];
      for (int i = 0; i < reviewCount; i++) {
          newReviews[i] = reviews[i];
      }
      delete[] reviews;
      reviews = newReviews;
      reviewCapacity = newCapacity;
  }
  reviews[reviewCount] = review;
  reviewCount++;
}
int User::countReviews(){
  return reviewCount;
}
User::~User() {
  delete[] reviews;
  // delete[] reviews; ← when you implement dynamic array for reviews too
}

bool User::hasVipPass() {
  for (const auto& ticket : tickets) {
      if (ticket.hasVIPAccess()) {
          return true;
      }
  }
  return false;
}

// Copy Constructor
User::User(const User& other) {

  reviewCapacity = other.reviewCapacity;
  reviewCount = other.reviewCount;
  reviews = new Review[reviewCapacity];
  for (int i = 0; i < reviewCount; i++) {
      reviews[i] = other.reviews[i];
  }

}

// Assignment Operator
User& User::operator=(const User& other) {
  if (this != &other) {

      delete[] reviews;

      reviewCapacity = other.reviewCapacity;
      reviewCount = other.reviewCount;
      reviews = new Review[reviewCapacity];
      for (int i = 0; i < reviewCount; i++) {
          reviews[i] = other.reviews[i];
      }
  }
  return *this;
}
