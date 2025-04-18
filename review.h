#ifndef REVIEW_H
#define REVIEW_H
#include <iostream>
using namespace std;
class Review{
  private:
  int reviewCapacity;
    string userName;
    string comment;
    float rating;
    public:
    Review();
    Review(int,string,string,float);
    string getComment();
    float getRating();
};
#endif //REVIEW_H
