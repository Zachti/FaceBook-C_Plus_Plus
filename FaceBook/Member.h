
#ifndef FACEBOOK_MEMBER_H
#define FACEBOOK_MEMBER_H
#include "Status.h"

enum class MONTH {JAN = 1 , FEB , MARCH , APRIL , MAY , JUNE , JULY , AUG , SEP , OCT , NOV , DEC};

struct BirthDate{
    int BirthDay;
    MONTH BirthMonth;
    int BirthYear;
};

class Member {

    char *name;
    BirthDate birthDate;
    Member *friendsArr;
    FanPage *funPagesArr;
    int friendsNum;
    int maxFriendsNum;
    int funPagesNum;
    int maxFunPagesNum;
    Status *BulletinBoard;
    int maxStatusesNum;
    int statusesNum;

public:
    Member(char *Name, BirthDate birthDate1);

    void addFunPage(FanPage &funPage);

    void removeFunPage(FanPage &funPage);

    void printFunPages() const;

    char *getName() const { return name; };

    int getStatusNum() const { return statusesNum; };

    Status *getBulletinBoard() const { return BulletinBoard; };

    int getFriendsNum() const { return friendsNum; };

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
