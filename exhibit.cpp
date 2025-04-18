#include "exhibit.h"
#include <iostream>
#include <string>
using namespace std;

Exhibit::Exhibit():title(""),description(""),popularity(0),rating(0.0){}

Exhibit::Exhibit(string t,string d,int p,float r){
    title=t;
    description=d;
    popularity=p;
    rating=r;
}

void Exhibit::setTitle(string title) {
    this->title = title;
}

string Exhibit::getTitle() {
    return title;
}

void Exhibit::setDescription(string description) {
    this->description = description;
}

string Exhibit::getDescription() {
    return description;
}

void Exhibit::setRating(float rating) {
    this->rating = rating;
}

float Exhibit::getRating() {
    return rating;
}

void Exhibit::display()const {
    cout << "Title: " << title << endl;
    cout << "Description: " << description << endl;
    cout << "Popularity: " << popularity << endl;
    cout << "Rating: " << rating << endl;
}

void Exhibit::setPopularity(int p){
    if(p >= 0 && p <= 100){
        popularity = p;
    } else {
        cout << "Invalid popularity. It must be between 0 and 100." << endl;
    }
}

void Exhibit::incrementPopularity(){
    popularity++;
}
int Exhibit::getPopularity(){
    return popularity;
}

string Exhibit::getPopularityStatus(){
    if (popularity > 100) return "Viral";
    else if (popularity >= 100) return "Highly Popular";
    else if (popularity >= 50) return "Moderately Popular";
    else return "Less Popular";
}

bool Exhibit::operator==(const Exhibit& other) {
return title == other.title && description == other.description && 
rating == other.rating && popularity ==
 other.popularity;
}

bool Exhibit::operator!=(const Exhibit& other) {
    if (*this == other) {
        return false;
    } else {
        return true;
    }
}

// ArtExhibit
ArtExhibit::ArtExhibit():artist(""){}
void ArtExhibit::setArtist(string artist) {
    this->artist = artist;
}
string ArtExhibit::getArtist() {
    return artist;
}

// HistoryExhibit
HistoryExhibit::HistoryExhibit():era(""){}
void HistoryExhibit::setEra(string era) {
    this->era = era;
}
string HistoryExhibit::getEra() {
    return era;
}

// TechExhibit
TechExhibit::TechExhibit():technology(""){}
void TechExhibit::setTechnology(string technology) {
    this->technology = technology;
}
string TechExhibit::getTechnology() {
    return technology;
}

void ArtExhibit::display()const{
    Exhibit::display();
    cout<<artist<<endl;
}

void TechExhibit::display()const{
    Exhibit::display();
    cout<<technology<<endl;
}

void HistoryExhibit::display()const{
    Exhibit::display();
    cout<<era<<endl;
}