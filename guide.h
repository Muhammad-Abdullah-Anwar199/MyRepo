#ifndef GUIDE_H
#define GUIDE_H

#include <string>
using namespace std;

class Exhibit;  // Forward declaration

class Guide {
private:
    string guideName;
    string language;
public:
    Guide();
    Guide(string name, string lang);
    void startTour(Exhibit& exhibit);  // Exhibit ka reference
};

#endif //GUIDE_H
