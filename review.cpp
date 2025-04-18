#include "review.h"
Review::Review(){
    userName="";
    comment="";
    rating=0.0;
    reviewCapacity=0;
}
Review::Review(int k,string n,string m,float a){
    userName=n;
    comment=m;
    rating=a;
}
string Review::getComment(){
    return comment;
}
float Review::getRating(){
    return rating;
}