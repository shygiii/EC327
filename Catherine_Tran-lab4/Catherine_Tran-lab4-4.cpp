#include "lab4_problem4.h"
#include <string>
#include <vector>

Person::Person(string name) {
    this->name = name;
}

void Person::befriend(Person &thePerson) {
    friends.push_back(&thePerson);
}

void Person::unfriend(Person &thePerson) {
    for (int i=0; i<friends.size(); i++) {
        if (&thePerson == friends[i]) friends.erase(friends.begin()+i);
    }
}

int Person::getFriendCount() {
    return friends.size();
}

string Person::getFriends() {
    string friendlist = "";
    for (int i=0; i<friends.size(); i++) {
        friendlist += friends[i]->name;
        if (i != friends.size()-1) friendlist += ", ";
    }
    return friendlist;
}

string Person::getFriendsOfFriends() {
    vector<Person*> fof;
    for (int i=0; i<friends.size(); i++) {
        Person* aFriend = friends[i];
        vector<Person*> friendofafriend = aFriend->friends;
        for (int j=0; j<friendofafriend.size(); j++) {
            bool infof = false;
            for (int k=0; k<fof.size(); k++) {
                if (fof[k]==friendofafriend[j]) {
                    infof = true;
                    break;
                }
            }
            if (infof==false) fof.push_back(friendofafriend[j]);
        }
    }
    
    string foflst;
    for (int i=0; i<fof.size(); i++) {
        foflst += fof[i]->name;
        if (i != fof.size()-1) foflst += ", ";
    }
    return foflst;
}