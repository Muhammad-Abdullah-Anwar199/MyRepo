#include "guide.h"
#include "museum.h"
#include "exhibit.h"
#include "ticket.h"
#include "user.h"
#include "review.h"
#include "membership.h"
#include "MuseumCollection.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include <map>  // Include the map header

using namespace std;

int main() {
    int totalUsers;
    cout << "Enter the number of users: ";
    cin >> totalUsers;

    int initialSize;
    cout << "Enter the initial ticket array size: ";
    cin >> initialSize;

    // Create a map to store users with their names as the key
    map<string, User*> userMap;
    string name;

    // Create and store user objects in the map
    for (int i = 0; i < totalUsers; i++) {
        cout << "Enter the name of user " << i + 1 << ": ";
        cin >> name;

        // Dynamically create a User object and add it to the map
        User* newUser = new User(initialSize);
        newUser->setUserName(name);
        userMap[name] = newUser;
    }

        // Let the active user log in
        string userName;
        cout << "\nEnter your name to proceed: ";
        cin >> userName;
    
        User* currentUser = nullptr;
        if (userMap.find(userName) != userMap.end()) {
            currentUser = userMap[userName];
            cout << "Welcome, " << userName << "!" << endl;
        } else {
            cout << "User not found. Exiting program.\n";
            return 1;  // Exit the program early
        }
    

    // Create Museum instance using singleton pattern
    Museum* museum = Museum::getInstance();
    museum->setMuseumName("National Museum");
    cout << "Museum name: " << museum->getMuseumName() << endl;

    MuseumCollection<Exhibit> exhibitCollection;

    // Create and add exhibits to the museum
    string title, description;
    int popularity;
    float rating;
    Exhibit exhibit;
    
    cin.ignore();
    cout << "Enter your Exhibit Title: ";
    getline(cin, title);
    cout << "Enter some Description about the Exhibit: ";
    getline(cin, description);
    cout << "Give popularity out of 100: ";
    cin >> popularity;
    cout << "Rate the Exhibit (0-5): ";
    cin >> rating;

    exhibit.setTitle(title);
    exhibit.setDescription(description);
    exhibit.setPopularity(popularity);
    exhibit.setRating(rating);
    exhibitCollection.addItem(exhibit);
    museum->addExhibit(exhibit);  // Add exhibit to museum
    cout << "\n--- Exhibit Collection ---\n";
    exhibitCollection.displayItems();

    // Display exhibit details
    cout << "\nExhibit Details:\n";
    exhibit.display();
    cout << "Popularity Status: " << exhibit.getPopularityStatus() << endl;

    int numTickets;
    cout << "Enter the number of tickets you want to buy: ";
    cin >> numTickets;

    Ticket* tickets = new Ticket[numTickets];
    cin.ignore();
    for (int i = 0; i < numTickets; i++) {
        int ticketId;
        string expiryDate;
        int hasVipPassInt;
        bool hasVipPass;

        cout << "\nEnter details for Ticket #" << i + 1 << endl;
        cout << "Enter your Ticket ID: ";
        cin >> ticketId;
        cin.ignore();

        cout << "Enter your Ticket's Expiry Date: ";
        getline(cin, expiryDate);

        cout << "Do you have a VIP Pass? (1 for Yes, 0 for No): ";
        cin >> hasVipPassInt;
        while (hasVipPassInt != 0 && hasVipPassInt != 1) {
            cout << "Please enter 1 (Yes) or 0 (No): ";
            cin >> hasVipPassInt;
        }
        hasVipPass = (hasVipPassInt == 1);

        Ticket ticket(ticketId, expiryDate, hasVipPass);
        ticket.setExhibit(exhibit);  // Associate ticket with exhibit
        tickets[i] = ticket;

        // Add ticket to the first user (you can modify to add it to any user from the map)
        userMap.begin()->second->addTicket(ticket);  
        cin.ignore();
    }

    cout << "Counting the Tickets how many added: " << userMap.begin()->second->countTickets() << endl;

    cout << "\nDisplaying All Tickets:\n";
    for (int i = 0; i < numTickets; i++) {
        cout << "\nTicket #" << i + 1 << " Info:\n";
        cout << "Ticket ID: " << tickets[i].getTicketId() << endl;
        cout << "Expiry Date: " << tickets[i].getExpiryDate() << endl;
        cout << "VIP Access: " << (tickets[i].hasVIPAccess() ? "Yes" : "No") << endl;
        cout << "Linked Exhibit:\n";
        tickets[i].getExhibit().display();
    }

    Ticket ticket1(8,"17 April 2025",true);
    try{
        for(int i=0;i<numTickets;i++){
        if(tickets[i]!=ticket1){
            throw runtime_error("This Ticket is not Equal to Ticket!");
        }else{
            cout<<"Ticket1 is equal to that Ticket"<<endl;
        }
    }
    }
    
    catch(const runtime_error& e){
        cerr<<e.what()<<endl;
    }

    Ticket t1(123, "18 April 2025", true);

    if (isTicketOfUser(t1, 123)) {
    cout << "Ticket belongs to user 123." << endl;
    } else {
    cout << "Ticket does not belong to user 123." << endl;
    }
    
    // Add reviews
    int numReviews;
    cout << "\nHow many reviews do you want to give? ";
    cin >> numReviews;
    cin.ignore();

    Review* reviews = new Review[numReviews];
    for (int i = 0; i < numReviews; i++) {
        string userName, comment;
        float rating1;

        cout << "\n--- Review #" << i + 1 << " ---\n";
        cout << "Enter your Name: ";
        getline(cin, userName);
        cout << "Enter your Comment: ";
        getline(cin, comment);
        cout << "Give the Rating (0-5): ";
        cin >> rating1;
        cin.ignore();

        Review review(initialSize, userName, comment, rating1);
        reviews[i] = review;  // Add to array

        // Assuming we add review to the first user
        userMap.begin()->second->addReviews(review);  // Add to user's reviews

        cout << "Review #" << i + 1 << " added successfully!" << endl;
    }

    cout << "Total Reviews added by user: " << userMap.begin()->second->countReviews() << endl;

    delete[] reviews;

    // Add memberships
    int numMembership;
    cout << "How many memberships do you want to add? ";
    cin >> numMembership;
    cin.ignore();

    Membership* memberships = new Membership[numMembership];
    for (int i = 0; i < numMembership; i++) {
        int memberShipId;
        cout << "\nEnter your MemberShip ID for Membership #" << i + 1 << ": ";
        cin >> memberShipId;
        cin.ignore();
        
        string type;
        cout << "Which Type of Membership? Vip or Local?: ";
        getline(cin, type);

        float discount;
        if (type == "vip") {
            discount = 30.0;
        } else if (type == "local") {
            discount = 10.0;
        } else {
            discount = 0.0;
            cout << "Unknown membership type, no discount applied.\n";
        }

        Membership membership(initialSize, memberShipId, type, discount);
        memberships[i] = membership;  // Add to array

        // Assuming we add membership to the first user
        userMap.begin()->second->addMemberShip(membership);  // Add to user's memberships

        cout << "Getting discount --> " << membership.getDiscount() << "%" << endl;
        cout << "Membership #" << i + 1 << " added successfully!" << endl;
        cout << "Total Memberships added by user: " << userMap.begin()->second->countMembership() << endl;
    }

    //Dealing With Guide
    string guideName;
    string language;
    cout<<"Enter the name of your the Guide:"; cin>>guideName;
    cout<<"Enter the language u want to choose:"; cin>>language;
    Guide guide(guideName,language);
    guide.startTour(exhibit);

    // Add different types of exhibits
    string artist;
    cout << "Enter the name of the Artist: "; cin>>artist;
    ArtExhibit artExhibit;
    artExhibit.setArtist(artist);

    cout << "Enter the title of the Art Exhibit: "; cin>>title;
    cout << "Enter the description of the Art Exhibit: "; cin>>description;
    cout << "Enter the popularity of the Art Exhibit: ";
    cin >> popularity;
    cout << "Rate the Art Exhibit (0-5): ";
    cin >> rating;

    artExhibit.setTitle(title);
    artExhibit.setDescription(description);
    artExhibit.setPopularity(popularity);
    artExhibit.setRating(rating);

    cout << "Showing the Name of the Artist: " << artExhibit.getArtist() << endl;
    artExhibit.display();

    // History Exhibit
    HistoryExhibit historyExhibit;
    string era;
    cout << "\nEnter the Era of the History Exhibit: "; cin>>era;
    cout << "Enter the title of the History Exhibit: "; cin>>title;
    cout << "Enter the description of the History Exhibit: ";cin>>description;
    cout << "Enter the popularity of the History Exhibit: ";
    cin >> popularity;
    cout << "Rate the History Exhibit (0-5): ";
    cin >> rating;

    historyExhibit.setEra(era);
    historyExhibit.setTitle(title);
    historyExhibit.setDescription(description);
    historyExhibit.setPopularity(popularity);
    historyExhibit.setRating(rating);

    cout << "Showing the Era of the Exhibit: " << historyExhibit.getEra() << endl;
    historyExhibit.display();

    // Tech Exhibit
    TechExhibit techExhibit;
    string technology;
    cout << "\nEnter the Technology showcased in the Tech Exhibit: "; cin>>technology;
    techExhibit.setTechnology(technology);

    cout << "Enter the title of the Tech Exhibit: "; cin>>title;
    cout << "Enter the description of the Tech Exhibit: "; cin>>description;
    cout << "Enter the popularity of the Tech Exhibit: ";
    cin >> popularity;
    cout << "Rate the Tech Exhibit (0-5): ";
    cin >> rating;

    techExhibit.setTitle(title);
    techExhibit.setDescription(description);
    techExhibit.setPopularity(popularity);
    techExhibit.setRating(rating);

    cout << "Showing the Technology used: " << techExhibit.getTechnology() << endl;
    techExhibit.display();

    // Clean up dynamic memory for users
    for (auto& pair : userMap) {
        delete pair.second;  // Delete each dynamically allocated User object
    }

    delete[] memberships;
    delete[] tickets;
    return 0;
}