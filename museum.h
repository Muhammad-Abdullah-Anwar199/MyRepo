#ifndef MUSEUM_H
#define MUSEUM_H
#include <iostream>
#include <vector>
using namespace std;
class Schedule;
class Exhibit;
class Guide;
class Museum {
private:
    static Museum* instance;
    Museum();
    string museumName;
    Schedule* schedule;
    Exhibit* exhibit;
    int exhibitCount;
    int exhibitCapacity;
    vector<Guide>g;
public:
    static Museum* getInstance();
    void setMuseumName(string);
    string getMuseumName();
    void setSchedule(Schedule&);
    Schedule getSchedule();
    void addExhibit(Exhibit);
    int countExhibit();
    Exhibit getExhibit(int index);
    bool isOpenToday(const string& today);
    void addGuide(Guide&);
    Guide getGuide(int index);
    int countGuide();
};
#endif //MUSEUM_H
