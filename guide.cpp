#include "guide.h"
#include "exhibit.h"  // Required for Exhibit class
#include <iostream>
using namespace std;

Guide::Guide(){
    guideName="";
    language="";
}

Guide::Guide(string name, string lang):guideName(name),language(lang){}
void Guide::startTour(Exhibit& exhibit) {
    cout << "Guide " << guideName << " is starting a tour in " << language << " for exhibit: "<<endl;
    exhibit.display();  // Exhibit class ka method
}
