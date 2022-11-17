
#ifndef FACEBOOK_MEMBER_H
#define FACEBOOK_MEMBER_H
#include "Status.h"

class Member {

    char *name;
    char* birthDate;
    Member *friendsArr;
    FanPage *fanPagesArr;
    int friendsLogSize;
    int friendsPhySize;
    int fanPagesLogSize;
    int fanPagesPhySize;
    Status *BulletinBoard;
    int bulletinBoardLogSize;
    int bulletinBoardPhySize;

public:
    Member(char* &Name, char* &BirthDate1);

    void addFanPage(FanPage &fanPage);

    void removeFanPage(FanPage &fanPage);

    void printFanPages() const;

    char *getName() const { return name; };

    int getStatusNum() const { return bulletinBoardLogSize; };

    Status *getBulletinBoard() const { return BulletinBoard; };

    int getFriendsNum() const { return friendsLogSize; };

    Member *getFriendsArr() const { return friendsArr; };

    void addFriend(Member &member);

    void removeFriend(Member &member);

    void printLastFriendsStatuses();

    void addStatus(Status &status);

    void printAllStatuses();

    bool checkIfWeAreFriends(char *name);

    ~Member();
};

#endif //FACEBOOK_MEMBER_H
