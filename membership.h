#ifndef MEMBERSHIP_H
#define MEMBERSHIP_H

#include <iostream>
#include <string>
using namespace std;

class Membership {
private:
    int memberShipId;
    string type;
    float discount;

public:
    // Constructors
    Membership();
    Membership(int membershipCapacity,int memberShipId, string type, float discount);

    // Setters
    void setMemberShipId(int id);
    void setType(string t);
    void setDiscount(float d);

    // Getters
    int getMemberShipId() const;
    string getType() const;
    float getDiscount() const;
};

#endif // MEMBERSHIP_H
