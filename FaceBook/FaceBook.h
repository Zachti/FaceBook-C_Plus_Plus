
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

using std::cout;
using std::cin;
using std::endl;
using std::swap;
using std::string;


class FaceBook {
    int membersListSize , maxMembersListSize , fanPageListSize , maxFanPageListSize;
    Member* membersList;
    FanPage* fanPageList;
    bool ActiveFaceBook = true;
public:
    FaceBook();
    bool getActiveFaceBook() const {return ActiveFaceBook;} ;
    void static printIntro() {cout << "Hello and welcome to facebook! " << endl;};
    void static printMenu();
    void PerformOptionOne();
    void PerformOptionTwo();
    void PerformOptionThree();
    void PerformOptionFour();
    void PerformOptionFive();
    void PerformOptionSix();
    void PerformOptionSeven();
    void PerformOptionEight();
    void PerformOptionNine();
    void PerformOptionTen();
    void PerformOptionEleven();
    void PerformOptionTwelve();
    void PrintWrongSelection() const;
    ~FaceBook();
};


#endif //FACEBOOK_FACEBOOK_H
