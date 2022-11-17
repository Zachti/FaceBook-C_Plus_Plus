
#ifndef FACEBOOK_FACEBOOK_H
#define FACEBOOK_FACEBOOK_H
#include "Status.h"
#include "FanPage.h"
#include "Member.h"
#include <iostream>
#define BASIC_SIZE 1
#define EMPTY 0
#define LAST_TEN 10
#define NOT_FOUND -1
#define MEMBER 1
#define FAN_PAGE 2
#define RETURN_MAIN_PAGE 3
#define DISLIKE 1
#define REMOVE 1
#define DATE 11

using std::cout;
using std::cin;
using std::endl;
using std::swap;
using std::string;


class FaceBook {
    int membersLogSize , membersPhySize , fanPageLogSize , fanPagePhySize;
    Member* membersList;
    FanPage* fanPageList;
    bool ActiveFaceBook = true;
public:
    FaceBook();
    bool getActiveFaceBook() const {return ActiveFaceBook;} ;
    void static printIntro() {cout << "Hello and welcome to facebook! " << endl;};
    void static printMenu();
    void adduser();
    void addFanPage();
    void addStatus();
    void showStatus();
    void show10status();
    void friendship(int remove = 0);
    void AddOrRemoveFanPage(int dislike = 0);
    void ShowAllEntities();
    void ShowMembers();
    void Exit();
    void PrintWrongSelection() const;
    ~FaceBook();
};


#endif //FACEBOOK_FACEBOOK_H
