#include "museum.h"
#include "guide.h"
#include "exhibit.h"
#include "schedule.h"
Museum*Museum::instance=nullptr;
Museum::Museum(){
    
}
Museum *Museum::getInstance() {
    if (instance==nullptr) {
        instance=new Museum();
    }
    return instance;
}

void Museum::setMuseumName(string name) {
    museumName=name;
}

string Museum::getMuseumName() {
    return museumName;
}

void Museum::setSchedule(Schedule& newSchedule){
    this->schedule=new Schedule(newSchedule);
}

Schedule Museum::getSchedule(){
    return *schedule;
}

void Museum::addExhibit(Exhibit newExhibit) {
    if (exhibitCount >= exhibitCapacity) {
        int newCapacity = exhibitCapacity * 2;
        
        Exhibit* newExhibitArray = new Exhibit[newCapacity];
        
        // Copy existing exhibits
        for (int i = 0; i < exhibitCount; i++) {
            newExhibitArray[i] = exhibit[i];
        }

        delete[] exhibit;              // Free old memory
        exhibit = newExhibitArray;     // Point to new array
        exhibitCapacity = newCapacity; // Update capacity
    }

    exhibit[exhibitCount] = newExhibit; // Add new exhibit
    exhibitCount++;
}

int Museum::countExhibit(){
    return exhibitCount;
}

Exhibit Museum::getExhibit(int index) {
    if (index < 0 || index >= exhibitCount) {
        cout << "Invalid Index" << endl;
        return Exhibit();  // Return a default Exhibit object
    }
    return exhibit[index];
}

bool Museum::isOpenToday(const string& today){
    return schedule->isOpenOn(today);
}

void Museum::addGuide(Guide& guide){
    g.push_back(guide);
}

int Museum::countGuide(){
    return g.size();
}

Guide Museum::getGuide(int index){
    if(index>=0 && index<g.size()){
        return g[index];
    }
    cout<<"Invalid Index"<<endl;
    return Guide();
}